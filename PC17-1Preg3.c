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

	fd = open("salida",O_CREAT | O_RDWR,0770);
	dup2(fd,1);
	printf("Hello world\n");

	while(1);

	//write(fd,"Hello world\n",20*sizeof(char));
	//close(fd);
	//execlp("sleep","sleep","0",(char*)NULL);
	exit(EXIT_SUCCESS);
}