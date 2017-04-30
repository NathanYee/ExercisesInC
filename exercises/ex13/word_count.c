/* Example code for Exercises in C

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Started with ex-ghashtable-3.c from
http://www.ibm.com/developerworks/linux/tutorials/l-glib/section5.html

==7842== HEAP SUMMARY:
==7842==     in use at exit: 18,604 bytes in 6 blocks
==7842==   total heap usage: 476,670 allocs, 476,664 frees, 9,387,092 bytes allocated
==7842==
==7842== Searching for pointers to 6 not-freed blocks
==7842== Checked 110,760 bytes
==7842==
==7842== LEAK SUMMARY:
==7842==    definitely lost: 0 bytes in 0 blocks
==7842==    indirectly lost: 0 bytes in 0 blocks
==7842==      possibly lost: 0 bytes in 0 blocks
==7842==    still reachable: 18,604 bytes in 6 blocks
==7842==         suppressed: 0 bytes in 0 blocks
==7842== Reachable blocks (those to which a pointer was found) are not shown.
==7842== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==7842==
==7842== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==7842== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gstdio.h>


/* Represents a word-frequency pair. */
typedef struct {
    gint freq;
    gchar *word;
} Pair;

/* Key and Value destroyer functions */
void free_data (gpointer data)
{
  // printf ("freeing data\n");
  g_free (data);
}

/* Compares two key-value pairs by frequency. */
gint compare_pair (gpointer v1, gpointer v2, gpointer user_data)
{
    Pair *p1 = (Pair *) v1;
    Pair *p2 = (Pair *) v2;
    return p1->freq - p2->freq;
}


/* Iterator that prints pairs. */
void pair_printor (gpointer value, gpointer user_data)
{
    Pair *pair = (Pair *) value;
    printf ("%d\t %s\n", pair->freq, pair->word);
}


/* Iterator that prints keys and values. */
void printor (gpointer key, gpointer value, gpointer user_data)
{
    printf (user_data, key, * (gint *) value);
}


/* Iterator that add key-value pairs to a sequence. */
void accumulator (gpointer key, gpointer value, gpointer user_data)
{
    GSequence *seq = (GSequence *) user_data;
    Pair *pair = g_new(Pair, 1);
    pair->word = (gchar*) key;
    pair->freq = * (gint *) value;

    g_sequence_insert_sorted (seq,
			      (gpointer) pair,
			      (GCompareDataFunc) compare_pair,
			      NULL);
}

/* Increments the frequency associated with key. */
void incr (GHashTable* hash, gchar *key)
{
    gint *val = (gint *) g_hash_table_lookup (hash, key);

    if (val == NULL) {
	gint *val1 = g_new (gint, 1);
	*val1 = 1;
	g_hash_table_insert (hash, g_strdup(key), val1);
    } else {
	*val += 1;
    }
}

int main (int argc, char** argv)
{
    gchar *filename;

    // open the file
    if (argc > 1) {
	filename = argv[1];
    } else {
	filename = "emma.txt";
    }

    FILE *fp = g_fopen(filename, "r");
    if (fp == NULL) {
	perror (filename);
	exit (-10);
    }

    /* string array is a (two-L) NULL terminated array of pointers to
       (one-L) NUL terminated strings */

    gchar line[128];
    GHashTable* hash = g_hash_table_new_full (g_str_hash, g_str_equal, free_data, free_data);
    int i;

    // read lines from the file and build the hash table
    while (1) {
  gchar **array;
	gchar *res = fgets (line, sizeof(line), fp);
	if (res == NULL) break;

	array = g_strsplit(line, " ", 0);
	for (i=0; array[i] != NULL; i++) {
	    incr(hash, array[i]);
	}
  g_strfreev(array);
    }

    fclose (fp);

    // print the hash table
    // g_hash_table_foreach (hash,  (GHFunc) printor, "Word %s freq %d\n");

    // iterate the hash table and build the sequence
    GSequence *seq = g_sequence_new (free_data);
    // GSequence *seq = g_sequence_new (NULL);
    g_hash_table_foreach (hash,  (GHFunc) accumulator, (gpointer) seq);

    // iterate the sequence and print the pairs
    g_sequence_foreach (seq,  (GFunc) pair_printor, NULL);

    // try (unsuccessfully) to free everything
    // (in a future exercise, we will fix the memory leaks)
    puts("Free g_hash");
    g_hash_table_destroy (hash);
    puts("Free g_sequence");
    g_sequence_free (seq);


    return 0;
}
