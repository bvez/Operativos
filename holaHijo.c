#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	

	int fd[2];
	int fd2[2];
	int fdHermano[2];
	char buffer[5000];
	pipe(fd);///proceso 1 escribe en fd y proceso 2 lo lee/
	pipe(fd2);//proceso 1 lee de fd2 y proceso 2 escribe
	pipe(fdHermano);

	write(fd[1],"Hola hijo",10);

	int pidHijo = fork();
	

	if(pidHijo)printf("Pid Hijo: %d\n",pidHijo);

	if(!pidHijo){
		//printf("Hola\n");
		usleep(100000);
		close(fd[1]);
		close(fd2[0]);
		close(fdHermano[0]);
		printf("%d\n",read(fd[0],buffer,10));
		printf("El proceso hijo con pid %d lee el mensaje:\n", getpid());
		printf("%s\n", buffer);
		write(fd2[1],"Hola papi",20);
		write(fdHermano[1],"Hola hermano, cuando leas esto, estare muerto",100);
		exit(0);
	}
	else{
		close(fd[0]);
		close(fd2[1]);
		//close(fdHermano[0]);
		//close(fdHermano[1]);
	}
	wait(NULL);
	read(fd2[0],buffer,20);
	printf("Ya espere a mi hijo y leo el mensaje: %s\n",buffer);
	
	int pidHijo2 = fork();
	char buff[100];
	if(!pidHijo2){
		close(fdHermano[1]);
		close(fd[1]);
		close(fd2[0]);
		close(fd2[1]);

		printf("El proceso hijo con pid %d lee el mensaje:\n", getpid());
		int g = read(fdHermano[0],buff,100);
		printf("%d %s\n", g,buff);
		exit(0);
	}
	wait(NULL);
	printf("Espere a mi otro hijo\n");
	/*
	int fd[2];
	char buffer[100000];
	pipe(fd);
	int i=0;
	int m = write(fd[1],"a",1);
	//printf("%d\n", );
	while(1){
		i++;
		printf("%d %d\n",m,i);
		m = write(fd[1],buffer,65540);
	}
	printf("Se llego a %d\n", i);
	return 0;*/
}