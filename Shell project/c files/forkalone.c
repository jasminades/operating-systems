#include <stdio.h>
#include <unistd.h>

int main(){
    while(1){
        int pid=fork();
        if(pid==0){
            printf("Child process pid: %d\n", getpid());
        }else if(pid<0){
            perror("fork");
            break;
        }
    }
    return 0;
}