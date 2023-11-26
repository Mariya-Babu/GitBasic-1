//Program for fork operation 
#include<stdio.h>
#include<unist.h>
#include<sys/types.h>

int main(){
	fork();
	fork();
	fork();
	printf("The process is created using fork() system call \n");
	printf("pid = %d\n",getpid());
	return 0;
}


