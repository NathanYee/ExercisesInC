// To be used with coffee.c

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  // choose one of the four blocks below to get different results

  char *my_env[] = {"FOOD=coffee", NULL};
  if(execle("./coffee", "./coffee", "donuts", NULL, my_env) == -1){
  fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
  return 1;
  }

  // char *my_env[] = {"FOOD=donuts", NULL};
  // if(execle("./coffee", "./coffee", "cream", NULL, my_env) == -1){
  // fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
  // return 1;
  // }

  // if(execl("./coffee", "coffee", NULL) == -1){
  // fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
  // return 1;
  // }

  // char *my_env[] = {"FOOD=donuts", NULL};
  // if(execle("./coffee", "coffee", NULL, my_env) == -1){
  // fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
  // return 1;
  // }

  return 0;
}
