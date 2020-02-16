#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "stringer.h"
#include "t/tinytest.h"

#ifdef  COLOR_CODE
#undef  COLOR_CODE
#endif
#define COLOR_CODE       0x1B

#ifdef  COLOR_RED
#undef  COLOR_RED
#endif
#define COLOR_RED        "[1;31m"

#ifdef  COLOR_GREEN
#undef  COLOR_GREEN
#endif
#define COLOR_GREEN      "[1;32m"

#ifdef  COLOR_YELLOW
#undef  COLOR_YELLOW
#endif
#define COLOR_YELLOW     "[1;33m"

#ifdef  COLOR_RESET
#undef  COLOR_RESET
#endif
#define COLOR_RESET      "[0m"

static void
printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", COLOR_CODE, COLOR_YELLOW, name, COLOR_CODE, COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}

static void
test_constr(void)
{
   struct stringer *z;

   printf_test_name("test_constr", "stringer_new, stringer_free");

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

   printf_test_name("test_null", "stringer_new, stringer_strings, stringer_free");

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

   printf_test_name("test_insert", "stringer_insert");

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

   printf_test_name("test_insert", "stringer_insert, stringer_strings");

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

   printf_test_name("test_stub", NULL);

   z = stringer_new();
   ASSERT("Constructor test, pt 1", z);
   ASSERT("Here's a test ...", two_doubles_equal(x, 1.23));
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
