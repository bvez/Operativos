#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	char buff[10];
	printf("Hola");
	read(STDOUT_FILENO,buff,10);
	//RESPUESTA: SE QUEDA ESPERANDO A LA ENTRADA, PROBABLEMENTE PORQUE EL BUFFER ES UNA MÁS ESTRUCTURA INTERNA
	//QUE NO PUEDE SER LEIDA DIRECTAMENTE
	return 0;
}