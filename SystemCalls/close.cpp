#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

extern int errno;

int main(){
	int fd = open("close.txt",O_WRONLY | O_CREAT,677);
	if(fd == -1){
		perror("Error opening file");
		return 1;
	}
	if(close(fd) == -1){
		perror("error closing file");
		return 1;
	}
	printf("file closed successfully\n");
	return 0;
}
