#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int sz;
	int fd = open("write.txt",O_WRONLY | O_CREAT | O_TRUNC,644);
	if(fd < 0){
		perror("Error");
	}
	sz = write(fd,"hello friends\n",strlen("hello friends\n"));
	printf(" called write fd=%d\n hello friends=%d\n it returned%d",fd,strlen("hello friends\n"),sz);
	close(fd);
}
