#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

#define NUM_TRACKS 5
#define MAXMATCH 20

char tracks[][80] = {
  "So What",
  "Freddie Freeloader",
  "Blue in Green",
  "All Blues",
  "Flamenco Sketches"
};

int main () {

        char reginald[81];      /* Regular Expresion */

        regex_t emma;

        regmatch_t matches[MAXMATCH];   /* Array of matches */
        int status;

        /* Read in and compile a regular expression */
        printf("Please give test expression: ");
        fgets(reginald,80,stdin);
        reginald[strlen(reginald)-1] = '\0';

        /* Let's use extended regular expresssions */
        status = regcomp(&emma,reginald,REG_EXTENDED);
        printf("Validity of regex (0 => OK): %d\n",status);

        /* Leave program if regex is faulty */
        /* we could use regerror to decode the error ... */
        if (status) return 1;

        int i;
        for (i=0; i<NUM_TRACKS; i++) {
          status = regexec(&emma,tracks[i],MAXMATCH,matches,0);
          if (status == 0) {
            printf("Status %d: '%s'\n", status, tracks[i]);
          }
        }

        /* Free up memory held within the regex memory */
        regfree(&emma);

        return 0;

        }
