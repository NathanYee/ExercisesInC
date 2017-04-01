#include <stdio.h>
#include <unistd.h> // for the exec functions
#include <errno.h>  // for errno variable
#include <string.h> //display errors with strerror()

int main()
{
  if (execlp("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1){
    if (execlp("ipconfig", "ipconfig", NULL) == -1){
      fprintf(stderr, "Cannot run ipconfig: %s\n", strerror(errno));
      return 1;
    }
  }
}
