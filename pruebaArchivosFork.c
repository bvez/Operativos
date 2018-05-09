#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd;
	fd = open("./hola.txt",O_RDONLY);
	printf("id padre: %d\n", getpid());
	//int pid = fork();
	char buff[10];
	char buff2[5]="hola";
	if(write(fd,buff2,4)>0)
		printf("Imprimio correctamente\n");
	close(fd);
	/*if(pid){
		int st;
		read(fd,buff,5);
		wait(&st);
		printf("%s\n", buff);
	}
	else{
		int fd2 = open("./hola.txt",O_RDONLY);
		read(fd2,buff,5);
		printf("%s\n", buff);
	}*/
	
	/*read(fd,buff,1);
	int st;
	if(pid)(wait(&st)>0);
	printf("%d %d %s %d\n",getpid(),getppid(),buff,st);*/
	return 0;
}