/**
 *  @file stringer.c
 *  @version 0.0.0
 *  @date Mon Dec 30 13:40:28 CST 2019
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "stringer.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  _FREE
#undef  _FREE
#endif
#define _FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct stringer {
   void       *x;
   char       *buffer;
   char      **list;
   size_t      buflen;                      /* length of used buffer */
   size_t      bufsiz;                      /* size of allocated buffer */
};

struct stringer *
stringer_new(void)
{
   struct stringer *tp;

   tp = (struct stringer *) malloc(sizeof(struct stringer));
   if (_IS_NULL(tp))
      return NULL;

   tp->buffer = NULL;
   tp->list = NULL;
   tp->bufsiz = 0;
   tp->buflen = 0;

   /* Do some magic here ... */

   return tp;
}

void
stringer_free(struct stringer **pp)
{

   /* Do some magic here ... */

   _FREE(*pp);
   *pp = NULL;
}

int
stringer_init(struct stringer *p, void *x)
{

   /* Do some magic here ... */
   p->x = x;                                     /* FIXME */

   return 0;
}

const char *
stringer_version(void)
{
   return "0.0.0";
}

int
stringer_empty(struct stringer *p)
{
   return 0;
}

int
stringer_insert(struct stringer *p, char *s)
{
   if (_IS_NULL(s))
      return 1;
   else {
      size_t      need = p->buflen + strlen(s) + 1;
      char       *tp = realloc(p->buffer, need * sizeof(char));
      if (_IS_NULL(tp))
         return 0;
   }

   return 0;
}

char      **
stringer_strings(struct stringer *p)
{
   return NULL;
}

#undef  _IS_NULL
#undef  _FREE
