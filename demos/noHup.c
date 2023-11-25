#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    printf("Je suis le processus : PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long) getpid(),
        (long) getppid(), (long) getpgrp(), (long) getsid(0));
        fflush(stdout);


    printf("Je vais compter jusqu'à 15 toutes les 2 secondes...\n");
    fflush(stdout);
    for(int i = 1; i <= 15; i++) {
        printf("Je suis au chiffre %ld \n", i);
        fflush(stdout);
        sleep(1);
    }

    printf("Je suis arrivé à la fin !\n");
    fflush(stdout);

    return 0;

}
