#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static void handleSigHupSigCont(int sig) {
    if(sig == 1) {
        printf("%ld: J'ai reçu SIGHUP\n", (long) getpid());
    } else {
        printf("%ld: J'ai reçu SIGCONT\n", (long) getpid());
    }
}


int main(void) {

    pid_t processFils;

    struct sigaction sa;
    sa.sa_handler = handleSigHupSigCont;

    printf("Je suis le processus parent : PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long) getpid(),
                    (long) getppid(), (long) getpgrp(), (long) getsid(0));

    // Handler pour SIGHUP
    if (sigaction(SIGHUP, &sa, NULL) == -1)
        perror("Erreur sigaction SIGHUP");


     // Handler pour SIGCONT
    if (sigaction(SIGCONT, &sa, NULL) == -1)
        perror("Erreur sigaction SIGCONT");


    for(int i = 0; i < 2; i++) {
        switch (fork()) {
            case -1:
                perror("Erreur fork");
            case 0:
                printf("Je suis un processus fils et je vais me stopper : PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long) getpid(),
                    (long) getppid(), (long) getpgrp(), (long) getsid(0));

                raise(SIGSTOP); // Stopper fils
                exit(0);
            default:
                break;
        }
    }

    sleep(3); // Sleep parent pour donner chance aux fils de s'exec
    printf("Je suis le parent PID=%ld; mes fils vont devenir un groupe de process orphelins....\n", (long) getpid());
    exit(0);
}
