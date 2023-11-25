#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>


/*
 * Ce programme a pour but d'illustrer les signaux envoyés par les commandes(fg et bg) de gestion
 * de travaux dans un contexte de shell supportant le job control, ansi que la notion de groupe
 * en foreground et groupe en background.
 *
 * Pour ce faire un handler pour SIGCONT est mis en place ansi que des prints montrant
 * le groupe en foreground actuel et le dans quel groupe (background ou foreground) le processus
 * il se trouve actuellement.
 */


static pid_t foreground_group;

static void handleSigCont(int sig) {
    printf("%ld: J'ai reçu SIGCONT\n", (long) getpid());
    printf("Je continue à m'éxécuter...\n");
    foreground_group = tcgetpgrp(STDIN_FILENO);
    printf("Groupe de processus en Foreground actuel : %d\n", foreground_group);
    if(foreground_group == getpgrp()) {
        printf("Je fais partie du groupe en foreground, j'ai accès au terminal en stdin/stdout\n");
    } else {
        printf("Je fais partie du groupe en background, j'ai accès au terminal en stdout\n");
    }
}


int main (void) {

    printf("Je suis le processus: PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long) getpid(),
           (long) getppid(), (long) getpgrp(), (long) getsid(0));

    struct sigaction sa;
    sa.sa_handler = handleSigCont;

    // Handler pour SIGCONT
	if (sigaction(SIGCONT, &sa, NULL) == -1)
        perror("Erreur sigaction SIGCONT");

    foreground_group = tcgetpgrp(STDIN_FILENO);
    printf("Groupe de processus en Foreground actuel : %d\n", foreground_group);
    if(foreground_group == getpgrp()) {
        printf("Je fais partie du groupe en foreground, j'ai accès au terminal en stdin/stdout\n");
    } else {
        printf("Je fais partie du groupe en background, j'ai accès au terminal en stdout\n");
    }

    while(1)
        pause();

    return 0;
}
