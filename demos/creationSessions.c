#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>


int main(void) {

    if (fork() != 0) /* Exit if parent, or on error */
        exit(EXIT_SUCCESS);

    if (setsid() == -1)
        errExit("setsid");

    printf("PID=%ld, PGID=%ld, SID=%ld\n", (long) getpid(),
        (long) getpgrp(), (long) getsid(0));

    if (open("/dev/tty", O_RDWR) == -1)
        errExit("open /dev/tty");

    exit(EXIT_SUCCESS);

}
