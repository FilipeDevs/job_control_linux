#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>


static void handleSigHupSigCont(int sig) {
        printf("%ld: J'ai reçu SIGCONT\n", (long) getpid());
	pid_t foreground_group = tcgetpgrp(STDIN_FILENO);
	if(foreground_group < 0) {
		perror("Erreur tcgetpgrp");
		exit(2);
	}
	printf("Processus en Foreground actuel : %d\n", foreground_group);
}


int main (void) {

	printf("Je suis le processus: PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long) getpid(),
        (long) getppid(), (long) getpgrp(), (long) getsid(0));
       
	pid_t foreground_group = tcgetpgrp(STDIN_FILENO);
	if(foreground_group < 0) {
		perror("Erreur tcgetpgrp");
		exit(2);
	}

	struct sigaction sa;
    	sa.sa_handler = handleSigHupSigCont;

	if (sigaction(SIGCONT, &sa, NULL) == -1)
        	perror("Erreur sigaction SIGCONT");

	printf("Processus en Foreground actuel : %d\n", foreground_group);

	while(1) {
		pause();
	}
	
	return 0;
}
