#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void sigint_handler(int signo) {
	fprintf(stderr,"PID: %d: J'ai reçu SIGINT\n", getpid());
}

void sigtstp_handler(int signo) {
	fprintf(stderr,"PID: %d: J'ai reçu SIGTSTP\n",
    getpid(), getppid(), getpgrp(), getsid(0));
	raise(SIGSTOP);  // Interompre le process
}

void sigcont_handler(int signo) {
	fprintf(stderr,"PID: %d: J'ai reçu SIGCONT\n",
    getpid(), getppid(), getpgrp(), getsid(0));
	if (isatty(STDIN_FILENO) && (getpid() == getpgrp())) {
    // Print groupe foreground ssi stdin est un terminal et que
    // le process est un leader de groupe
    	fprintf(stderr,"Groupe en foreground: %d\n", tcgetpgrp(STDIN_FILENO));
	}
}

int main() {
	// Handlers pour SIGINT, SIGTSTP et SIGCONT
	signal(SIGINT, sigint_handler);
	signal(SIGTSTP, sigtstp_handler);
	signal(SIGCONT, sigcont_handler);

    if (isatty(STDIN_FILENO) && (getpid() == getpgrp())) {
    // Print groupe foreground ssi stdin est un terminal et que
    // le process est un leader de groupe
    	fprintf(stderr,"Groupe en foreground: %d\n", tcgetpgrp(STDIN_FILENO));
	}

	fprintf(stderr,"Je suis le process: PID: %d, PPID: %d, PGID: %d, SID: %d\n",
    getpid(), getppid(), getpgrp(), getsid(0));

	while (1) {
    	pause();
	}

	return 0;
}
