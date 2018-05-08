#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/*
 * 
 */
#define N 5
int ccount = 0;
/*
 * child_handler2 - SIGCHLD handler that reaps all terminated children
 */
void child_handler2(int sig){
    int child_status;
    pid_t pid;
    printf("proceso que llama al handler %d\n", getpid());
    while ((pid = wait(&child_status)) > 0) {
        ccount--;
        printf("Received signal %d from process %d\n", sig, pid);
        fflush(stdout);
    }
    printf("Termina la funcion de la senal\n");
}
    /*
     * fork15 - Using a handler that reaps multiple children
     */
void main(){
    pid_t pid[N];
    int i;
    ccount = N;
    printf("Proceso principal: %d\n", getpid());
    signal(SIGCHLD, child_handler2);
    for (i = 0; i < N; i++){
       if ((pid[i]=fork()) == 0) {
           sleep(1);
           printf("se cierra el proceso %d\n", getpid());
           exit(0);
       }
    }
    while (ccount > 0) {
       printf("To be paused\n");
       fflush(stdout);
       printf("%d\n", ccount);
       pause();
       printf("Termina de recibir la senal\n");
    }
    exit(0);
}