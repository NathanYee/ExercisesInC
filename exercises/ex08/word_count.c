/* Word counter using Glib library
* Nathan Yee
* Software Systems
*
* Usage: ./word_count laIncognita.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <glib.h>
#include <glib/gstdio.h> // file utilites

int main(int argc, char** argv) {
    gssize length;
    gchar *content, *filename = argv[1];

    if (g_file_get_contents (filename, &content, &length, NULL)) {
        // Process contents
        // count words based on space delimiter
        gchar** split = g_strsplit(content, " ", -1);
        gchar **ptr;
        int word_counter = 0;

        // traverse array
        for (ptr = split; *ptr; ptr++){
            word_counter++;
        }

        // output number of words in list
        printf("%d\n", word_counter);
        g_free (content);
    } else {
        return 1;
    }
    
    return 0;
}
