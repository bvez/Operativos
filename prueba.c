#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/*printf("hola");
	fflush(stdout);
	while(1);*/
	int a[5]={1,2,4,5,6};
	if(fork()){
		a[4] = 10;
	}
	for(int i = 0;i<5;i++){
		printf("%d\n", a[i]);
	}
	exit(0);
}