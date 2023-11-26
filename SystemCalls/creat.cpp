#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd = open("example.txt",0644);
	printf("file desciptor = %d \n",fd);
	if(fd == -1){
		perror("Error creating file");
		return 1;
	}
	close(fd);
	return 0;
}
