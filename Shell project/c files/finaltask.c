#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    char command[100];

    printf("Choose a command ");
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    int rc = fork();
    if (rc == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (rc == 0) { 
        int fd = open("foo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if(fd == -1){
            perror("open");
            exit(EXIT_FAILURE);
        }

        if (dup2(fd, STDOUT_FILENO) == -1){
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        close(fd);

        system(command);
        exit(EXIT_SUCCESS);
    } else { 
        wait(NULL);
    }

    return 0;
}
