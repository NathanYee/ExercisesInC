#include <stdio.h>
#include <unistd.h> // for the exec functions
#include <errno.h>  // for errno variable
#include <string.h> //display errors with strerror()

int main(int argc, char *argv[])
{
  char *feeds[] = {"https://www.reddit.com/.rss", "http://www.rollingstone.com/rock.xml"};
  int times = 2;
  char *phrase = argv[1];
  int i;
  for (i = 0; i < times; i++) {
    char var[255];
    sprintf(var, "RSS_FEED=%s", feeds[i]);
    char *vars[] = {var, NULL};

    pid_t pid = fork(); //pid_t is an integer that works on any operating system
    if (pid == -1) {
      fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
      return 1;
    }

    if (!pid) {
      if (execle("/usr/bin/python",
                 "/usr/bin/python",
                 "./rssgossip.py",
                 phrase, NULL, vars) == -1) {
        fprintf(stderr, "Can't run script: %s\n", strerror(errno));
        return 1;
      }
    }
  }
  return 0;
}
