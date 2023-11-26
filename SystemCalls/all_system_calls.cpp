#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
extern int errno;

int main(){
	int fd,fd1,fd2,fd3,fd4;
	char buf[100];
	
	fd=creat("hi.txt",644);
	printf("file descriptor(creat)=%d\n",fd);
	
	fd1=open("hi.txt",O_RDWR);
	printf("file descriptor(open)=%d\n",fd1);
	
	fd2=lseek(fd,1000,SEEK_SET);
	printf("file desciptor(write)=%d\n",fd2);
	
	fd3=write(fd,"oslab",strlen("oslab"));
	printf("file descipotr(write)=%d\n",fd3);
	
	fd4=read(fd1,buf,sizeof(buf));
	printf("file desciptor(read)=%d\n",fd4);
	
	if(close(fd) == -1){
		perror("error closing file");
		return 1;
	}
	
	printf("file closed successsfully");
	return 0;
	
}
