#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static void handleSigHup(int sig) {

    printf("%ld: J'ai reçu SIGHUP\n", (long) getpid());
    fflush(stdout);

}

int main(int argc, char *argv[]) {

    pid_t processFils;

    struct sigaction sa;
    sa.sa_handler = handleSigHup;

    // Handler pour SIGHUP
    if (sigaction(SIGHUP, &sa, NULL) == -1)
        perror("Erreur sigaction");
        fflush(stdout);

    processFils = fork();

    if(processFils > 0) {
        printf("Je suis le processus parent : PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long) getpid(),
        (long) getppid(), (long) getpgrp(), (long) getsid(0));
        fflush(stdout);
    }

    if(processFils < 0)
        perror("Erreur fork du fils");
        fflush(stdout);

    if(processFils == 0){
        /*
         * Déplacer le fils dans un nouveau groupe si un parametre a été passé
         * (le shell n'a pas créée ce groupe, il n'est pas au courant !)
         */
        if(argc > 1) {
            if (setpgid(0, 0) == -1)
                perror("setpgid");
            printf("Le fils a changé de groupe !\n");
            fflush(stdout);
        }
        printf("Je suis le processus fils : PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long) getpid(),
        (long) getppid(), (long) getpgrp(), (long) getsid(0));
        fflush(stdout);
    }

    alarm(20); // Envoyer un SIGALARM, pour terminer le process si rien ne le termine


    for(;;) { // Wait des signaux
        pause();
    }
}
