#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd = open("./hola.txt",O_WRONLY|O_CREAT);
	int fd2 = open("./hola.txt",O_WRONLY);
	
	char buff[10];
	char buff2[5]="hola";
	printf("antes de imprimir\n");
	if(write(fd,buff2,4)>0)
		printf("Imprimio correctamente\n");
	
	char buff3[5]="ja";

	if(write(fd2,buff3,2)>0)
		printf("Imprimio correctamente\n");

	close(fd2);
	close(fd);
	
	return 0;
}