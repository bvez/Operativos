#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	pipe(fd);

	int a[6] = {4,2,2,4,5,6};
	int out[10] = {1,1,1,1,1,1,1,1,1,1};

	//printf("%d\n", fd[0]);
	//printf("%d\n", fd[1]);
	//open(fd[0]);
	//open(fd[1]);

	write(fd[1],a,6*sizeof(int));
	//close(fd[0]);
	read(fd[0],out,3*sizeof(int));

	for(int i = 0;i<6;i++) 
		//write(1,out,sizeof(int));
		printf("%d\n", out[i]);

	//close(fd[0]);
	close(fd[1]);
	return 0;
}