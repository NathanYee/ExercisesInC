/* Compares integers.
 *
 * ip: pointer to int
 * jp: pointer to int
 *
 * returns: 1 if equal, 0 otherwise
 */
int equal_int (void *ip, void *jp)
{
    if (*(int*) ip == *(int*) jp){
      return 0;
    } else {
      return 1;
    }

}
