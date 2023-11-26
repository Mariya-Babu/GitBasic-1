#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

extern int errno;

int main(){
	int fd = open("oslab.txt",O_RDONLY | O_CREAT);
	printf("file desciptor = %d \n",fd);
	if(fd == -1){
		perror("Program");
	}
	return 0;
}
