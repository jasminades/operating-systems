#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Failed\n");
        exit(EXIT_FAILURE);
    } 
    
    else if (pid == 0) {
        printf("Child processes\n");
        execl("/bin/ls", "ls", "-l", NULL);
        
        perror("execl");
        exit(EXIT_FAILURE);
    } 
    else {
        printf("Parent process\n");
        int status;
        wait(&status);
        
        if (WIFEXITED(status)) {
            printf("Child process %d\n", WEXITSTATUS(status));
        } else {
            printf("Stopped\n");
        }
    }

    return 0;
}
