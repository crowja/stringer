#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "stringer.h"
#include "t/tinytest.h"

#ifdef  _COLOR_CODE
#undef  _COLOR_CODE
#endif
#define _COLOR_CODE       0x1B

#ifdef  _COLOR_RED
#undef  _COLOR_RED
#endif
#define _COLOR_RED        "[1;31m"

#ifdef  _COLOR_GREEN
#undef  _COLOR_GREEN
#endif
#define _COLOR_GREEN      "[1;32m"

#ifdef  _COLOR_YELLOW
#undef  _COLOR_YELLOW
#endif
#define _COLOR_YELLOW     "[1;33m"

#ifdef  _COLOR_RESET
#undef  _COLOR_RESET
#endif
#define _COLOR_RESET      "[0m"

static void
_printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", _COLOR_CODE, _COLOR_YELLOW, name, _COLOR_CODE, _COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}

static void
test_constr(void)
{
   struct stringer *z;

   _printf_test_name("test_constr", "stringer_new, stringer_free");

   z = stringer_new();
   ASSERT("Constructor test", z);
   stringer_free(&z);
   ASSERT_EQUALS(NULL, z);
}

static void
test_null(void)
{
   struct stringer *z;
   char      **cpp;
   unsigned    n;

   _printf_test_name("test_null", "stringer_new, stringer_strings, stringer_free");

   z = stringer_new();
   ASSERT("Constructor test", z);

   stringer_strings(z, &n, &cpp);
   ASSERT_EQUALS(0, n);
   ASSERT_EQUALS(NULL, cpp);

   stringer_free(&z);
   ASSERT_EQUALS(NULL, z);
}

#if 0
static void
test_insert(void)
{
   char      **cpp;
   struct stringer *z;

   _printf_test_name("test_insert", "stringer_insert");

   z = stringer_new();
   stringer_insert(z, "cow");
   stringer_insert(z, "crow");
   cpp = stringer_strings(z);
   printf("FOUND %s\n", cpp[0]);
   printf("FOUND %s\n", cpp[1]);

   stringer_free(&z);
   ASSERT_EQUALS(NULL, z);
}
#endif

static void
test_insert(void)
{
   char      **cpp;
   unsigned    n;
   struct stringer *z;

   _printf_test_name("test_insert", "stringer_insert, stringer_strings");

   z = stringer_new();
   stringer_insert(z, "cow");
   stringer_insert(z, "");                       /* insert empty string */
   stringer_insert(z, "crow");
   stringer_insert(z, NULL);                     /* no-op */
   stringer_insert(z, "horse");
   stringer_strings(z, &n, &cpp);
   ASSERT_STRING_EQUALS("cow", cpp[0]);
   ASSERT_STRING_EQUALS("", cpp[1]);
   ASSERT_STRING_EQUALS("crow", cpp[2]);
   ASSERT_STRING_EQUALS("horse", cpp[3]);

   stringer_free(&z);
   ASSERT_EQUALS(NULL, z);
}

#if 0                                            /* 16 yy */
static void
test_stub(void)
{
   struct stringer *z;
   double      x = 1.23;                    /* TODO */

   _printf_test_name("test_stub", NULL);

   z = stringer_new();
   ASSERT("Constructor test, pt 1", z);
   ASSERT("Here's a test ...", _two_doubles_equal(x, 1.23));
   ASSERT_EQUALS(10, 10);

   stringer_free(&z);
   ASSERT_EQUALS(NULL, z);
}
#endif

int
main(void)
{
   printf("%s\n", stringer_version());

   RUN(test_constr);
   RUN(test_null);
   RUN(test_insert);

   return TEST_REPORT();
}
