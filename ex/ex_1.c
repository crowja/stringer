#include <stdlib.h>
#include <stdio.h>
#include "stringer.h"

int
main(void)
{
   char        word[50];
   char **list, **cpp;
   unsigned n;
   struct stringer *z = stringer_new();

   while (fscanf(stdin, "%s", word) > 0) {
      printf("WORD: %s\n", word);
      stringer_insert(z, word);
   }

   printf("rc = %d\n", stringer_strings(z, &n, &list));

#if 1
   cpp = list;
   while (NULL != *cpp)
       printf("FOUND: %s\n", *cpp++);
#else
   printf("FOUND: %s\n", list[0]);
#endif
    
   stringer_free(&z);
   return 0;
}
