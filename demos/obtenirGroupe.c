#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
  pid_t pid, pgid; // PID et PGID du process courrant
  pid_t ppid, ppgid; // PID et PGID du parent
  // Process courrant
  pid = getpid();
  pgid = getpgrp();
  // Process Parent
  ppid = getppid();
  ppgid = getpgid(ppid);
  // Print PGID et PID du process courrant + parent
  printf("(Process courrant) pid:%d pgid:%d\n", pid, pgid);
  printf("(Process parent) ppid:%d pgid:%d\n", ppid, ppgid);

  return 0;
}
