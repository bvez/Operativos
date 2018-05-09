#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	char buffer[5];
	pipe(fd);

	if (write(fd[0],"hola",5)>=0)
		printf("escribio\n");
	
	read(fd[1],buffer,1);//espera la entrada de los valores en el pipe

	printf("%s\n", buffer);
	return 0;
}