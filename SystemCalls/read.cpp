#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

extern int errno;

int main(){
	int buf[1000];
	int fd = open("read.txt",O_RDONLY | O_CREAT);
	printf("file descriptor(open) : %d\n",fd);
	if(fd==-1){
		perror("error opening file");
	}
	int fd1 = read(3,buf,sizeof(buf));
	printf("file descriptor(read):%d",fd1);
	if(fd1<0){
		perror("error reading file");
	}
	close(fd);
}
