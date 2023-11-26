//Program for read a file:
#include<stido.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
extern int errno;
int main(){
	int fd = open("oslab.txt",O_RDONLY | O_CREAT);
	printf("fd = %d\n",fd);
	(fd==-1){
//		printf("Error Number %d \n",error);
		perror("Program");
	}
	return 0;
}
