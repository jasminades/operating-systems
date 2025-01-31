#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 100
#define PROMPT_SIZE 100 

int main() {
    printf("Program started\n");
    char command[MAX_LINE]; 
    char prompt[PROMPT_SIZE]; 
    char *username; 
    int should_run = 1;

    
    username = getenv("USER");

    while (should_run) {
        snprintf(prompt, PROMPT_SIZE, "%s@machine:~$ ", username);

        printf("%s", prompt); 
        fflush(stdout); 

        fgets(command, MAX_LINE, stdin);

        
        if (command[strlen(command) - 1] == '\n')
            command[strlen(command) - 1] = '\n';

        
        if (strcmp(command, "exit") == 0)
            break;

        
        pid_t pid = fork();

        if (pid < 0) { 
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { 
            if (execlp(command, command, NULL) == -1) {
                perror("exec");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    }

    return 0;
}
