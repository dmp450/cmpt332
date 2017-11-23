/*
 * CMPT 332 -- Fall 2017
 * Assignment 3
 * Derek Perrin 		dmp450 11050915
 * Dominic McKeith 	dom258 11184543
 */

#include "types.h"
#include "stat.h"
#include "user.h"

#define NFORK 10

void
child_proc(void)
{
  setpriority(getpid(), 4);
  sleep(0);
  printf(1, "I am a child with priority %d\n", getpriority(getpid()));

  exit();
}

int
main(int argc, char* argv[])
{
  int pid, i;
  int pids[NFORK];
  for(i = 0; i < NFORK; i++) {
    pid = fork();
    if (pid == 0){
      child_proc();
    }
    pids[i] = pid;
  }
  for (i = 0; i < NFORK; i++) {
    setpriority(pids[i], 2);
  }
  while(wait() >= 0);
  exit();
}
