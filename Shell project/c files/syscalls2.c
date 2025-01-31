#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>

int child_function(void *arg) {
    printf("Child process  with clone()\n");

    char *args[] = {"/bin/ls", "-l", NULL};
    execle("/bin/ls", "ls", "-l", NULL, NULL);
    
    perror("execle");
    exit(EXIT_FAILURE);
}

int main() {
    char *stack = malloc(8192); 

    int pid = clone(child_function, stack + 8192, CLONE_VM | SIGCHLD, NULL);

    if (pid == -1) {
        perror("clone");
        exit(EXIT_FAILURE);
    }

    wait(NULL);

    free(stack);

    return 0;
}
