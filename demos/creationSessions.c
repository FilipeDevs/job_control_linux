#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>  

int main(void) {

    if (fork() != 0) // Exit du parent
        exit(EXIT_SUCCESS);

    if (setsid() == -1)
        perror("setsid");
        exit(-1);

    printf("PID=%ld, PGID=%ld, SID=%ld\n", (long) getpid(),
        (long) getpgrp(), (long) getsid(0));

    if (open("/dev/tty", O_RDWR) == -1) // Ouvrir terminal de controle associé
        perror("open /dev/tty");
        exit(-1);

    exit(0);
}
