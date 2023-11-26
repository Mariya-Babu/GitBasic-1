#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd, fd1;
	fd = open("lseek.txt",O_RDONLY | O_CREAT);
	if(fd == -1){
		perror("error opening file");
		return 1;
	}
	fd1 = lseek(fd,100,SEEK_SET);
	printf("file descriptor=%d",fd1);
	if(fd1 == -1){
		perror("error seeking in file");
		close(fd);
		return 1;
	}
	close(fd);
	return 0;
}
