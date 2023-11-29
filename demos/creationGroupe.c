#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Enfant avant création du groupe - PID: %d, PGID: %d\n", getpid(), getpgrp());
        setpgid(0, 0); // Créer un nouveau groupe de processus avec le processus enfant comme leader
        printf("Enfant aprés création du groupe - PID: %d, PGID: %d\n", getpid(), getpgrp());
    } else if (pid > 0) {
        // Code du processus parent
        sleep(1); // Donner une chance au processus enfant de s'exécuter et de créer le nouveau groupe
        printf("Parent - PID: %d, PGID: %d\n", getpid(), getpgrp());
    } else {
        perror("Erreur lors de la création du processus");
        exit(EXIT_FAILURE);
    }
    return 0;
}