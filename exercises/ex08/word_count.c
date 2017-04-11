/* Word counter using Glib library
* Nathan Yee
* Software Systems
*
* Usage: ./word_count laIncognita.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h> // for isspace
#include <glib.h>
#include <glib/gstdio.h> // file utilites

int main(int argc, char** argv) {
    gssize length;
    gchar *content, *filename = argv[1];

    if (g_file_get_contents (filename, &content, &length, NULL)) {
        // Process contents
        // convert to lowercase
        content = g_ascii_strdown(content, -1);
        g_strcanon(content, "abcdefghijklmnopqrstuvwxyz", ' ');

        // count words based on space delimiter
        gchar **split = g_strsplit(content, " ", -1);
        gchar **ptr;

        // create hash table to count number of words
        GHashTable *word_counter_table = g_hash_table_new(g_str_hash, g_str_equal);

        // traverse array
        int val;
        for (ptr = split; *ptr; ptr++){
            if (g_hash_table_contains(word_counter_table, *ptr)) {
                // if key already in hash table - increment value by one
                val = g_hash_table_lookup(word_counter_table, *ptr);
                g_hash_table_replace(word_counter_table, *ptr, val+1);
            } else {
                // otherwise add key to hash table and set val to 1
                g_hash_table_insert(word_counter_table, *ptr, 1);
            }
        }

        // get the keys of the hash table as a GList
        GList* keys = g_hash_table_get_keys(word_counter_table);

        // Descend through GList and print out key and value
        while (keys != NULL){
            printf("%s, %d\n", keys->data, g_hash_table_lookup(word_counter_table, keys->data));
            keys = keys->next;
        }

        g_free (content);
    } else {
        return 1;
    }

    return 0;
}
