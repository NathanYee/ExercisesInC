/* Word counter using Glib library
* Nathan Yee
* Software Systems
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <glib.h>
#include <glib/gstdio.h> // file utilites

int main(int argc, char** argv) {
    gssize length;
    gchar *content, *filename = "laIncognita.txt";
    if (g_file_get_contents (filename, &content, &length, NULL)) {
        // Process contents
        gchar** split = g_strsplit(content, " ", -1);
        g_free (content);
    }

    //GList* list = NULL;
    //list = g_list_append(list, "Hello world!");
    //printf("The first item is '%s'\n", (char *) g_list_first(list)->data);
    return 0;
}
