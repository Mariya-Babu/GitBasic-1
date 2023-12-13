#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t pid = fork(); // Creating a new process
    
    if (pid == -1) {
        // Error handling if fork fails
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("I am the child process!\n");
    } else {
        // Parent process
        printf("I am the parent process!\n");
    }
    return 0;
}

