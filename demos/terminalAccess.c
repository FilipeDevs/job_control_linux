#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static void handleSIGTTIN(int sig) {
    printf("%ld: J'ai reçu SIGTTIN\n", (long) getpid());
}

int main(void) {

	struct sigaction sa;
	sa.sa_handler = handleSIGTTIN;
	printf("Je suis le processus: PID=%ld; PPID=%ld; PGID=%ld; SID=%ld\n", (long) getpid(),
                    (long) getppid(), (long) getpgrp(), (long) getsid(0));

	// Handler pour SIGTTIN
    if (sigaction(SIGTTIN, &sa, NULL) == -1) {
		perror("Erreur sigaction SIGINT");
		exit(-1);
	}
        
	char buffer[1024];
	long n;

	printf("Je vais lire depuis le terminal...\n");
	printf("Tapez quelque chose puis Enter, j'afficherais ce que vous avez tapé...\n");
	while(1) {

		n = read(STDIN_FILENO, buffer, sizeof(buffer)); 
		if(n < 0) {
			perror("Erreur dans read");
			break;
		}			
		
		write(STDOUT_FILENO, buffer, n);
	}	

	return 0;

}

