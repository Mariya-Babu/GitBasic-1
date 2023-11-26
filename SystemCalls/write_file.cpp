//Program for write in a file
#include<stdio.h>
#include<fentl.h>
int main(){
	int sz;
	
	int fd = open("oslab.txt",O_WRONLY | O_CREATE | O_TRUNC, 0644);
	if(fd<0z){
		perror("r1");
		exit(1);
	}
	
	sz = write(fd,"hello students\n",strlen("hello students\n"));
	
	printf("called write(%d, \"hello students\\n",%d)."
		It returned %d\n, fd, strlend("hello students\n",sz);
		
		close(fd);
	")
}
