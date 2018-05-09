#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    write(1,argv[1],1);
    write(1,"\n",1);
    //printf("%s %s %s\n",argv[1],argv[2],argv[3]);
    int pid;
    if(argc == 4) pid = fork();
    printf("%d(%d)\n",getpid(),getppid());

    if(!pid) usleep(1000000);
    if(*argv[1] == *argv[2]) exit(0);
    ++*argv[1];
    if(execl(argv[0],argv[0],argv[1],argv[2],argv[3],(char*)NULL)){
        write(1,"Oops...\n",8);
        exit(1);
    }
    
}