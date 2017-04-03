/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
  struct timeval tv[1];

  gettimeofday(tv, NULL);
  return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
  sleep(i);
  printf("Hello from child %d.\n", i);
  exit(i); // Child process stops running the for loop
           // because we exit the child process here
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
  int status;
  pid_t pid;
  double start, stop;
  int i, num_children;

  // the first command-line argument is the name of the executable.
  // if there is a second, it is the number of children to create.
  if (argc == 2) {
    num_children = atoi(argv[1]);
  } else {
    num_children = 1;
  }

  // get the start time
  start = get_seconds();

  for (i=0; i<num_children; i++) {

    // create a child process
    printf("Creating child %d.\n", i);
    pid = fork(); // both processes continue from here
                  // pid is zero for child processes
                  // pid is nonzero for parent process

    /* check for an error */
    if (pid == -1) {
      fprintf(stderr, "fork failed: %s\n", strerror(errno));
      perror(argv[0]);
      exit(1);
    }


    /* see if we're the parent or the child */
    if (pid == 0) {
      printf("Child, memory location of iter:%p\n", &i);
      num_children += 1; // if the processes shared the same memory,
                         // this would create an infinite loop of
                         // creating processes. Although it could exit
                         // this loop if the main process got lucky
                         // multiple times in a row
      child_code(i);
    } else {
      printf("Parent, memory location of iter:%p\n", &i);
    }
      // Both the parrent and child processes share identical copies
      // of the virtual memory space. Even though it looks like updating
      // one of the values would change the other, it doesn't actually
      // update the other process.
  }

  /* parent continues */
  printf("Hello from the parent.\n");

  for (i=0; i<num_children; i++) {
    pid = wait(&status);

    if (pid == -1) {
      fprintf(stderr, "wait failed: %s\n", strerror(errno));
      perror(argv[0]);
      exit(1);
    }

    // check the exit status of the child
    status = WEXITSTATUS(status);
    printf("Child %d exited with error code %d.\n", pid, status);
  }
  // compute the elapsed time
  stop = get_seconds();
  printf("Elapsed time = %f seconds.\n", stop - start);

  exit(0);
}

/*
 * The processes usually print in order in which they were created.
 * This happens because each successively created process is told to
 * sleep for a longer and longer time.
 */
