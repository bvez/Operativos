#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
	int fd[2];
	double a[] = {'b','g','s'};
	pipe(fd);
	
	printf("%d\n", sizeof(a));

	/*printf("Llena la tuberia\n");
	write(fd[1],a,3*sizeof(int));
	close(stdout);

	//printf("%d\n",waitpid(getpid(),NULL,0));
	if(fork() == 0){
		int out[3];

		read(fd[0],out,3*sizeof(int));
		printf("Lee la tuberia\n");
		for(int i = 0;i<3;i++){
			printf("%d\n", out[i]);
		}
	}*/
	/*char buff[5];
	char cadena[5]="HOLA";
	close(STDOUT_FILENO);
	dup(fd[1]);

	write(STDOUT_FILENO,cadena,5*sizeof(char));
	//read(STDOUT_FILENO,buff,5*sizeof(char));
	read(fd[0],buff,5*sizeof(char));

	write(STDERR_FILENO,buff,5*sizeof(char));
	close(fd[1]);
	dup(STDOUT_FILENO);

	write(STDOUT_FILENO,"HOLA",5*sizeof(char));*/
	//fprintf(stderr, "Hola");
	//while(1);
	/*close(STDOUT_FILENO);
	dup2(STDERR_FILENO,STDOUT_FILENO);
	printf("HOLA\n");
	while(1);*/



	/*write(STDIN_FILENO,a,3*sizeof(char));
	char buffAux[3];
	printf("%d\n",read(STDOUT_FILENO,buffAux,3*sizeof(char)));

	for (int i = 0; i < 3; i++)
	{
		fprintf("%c\n", buffAux[i]);
	}*/

	/*read(STDIN_FILENO,buffAux,3*sizeof(int));

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", buffAux[i]);
	}*/
	return 0;
}