# stringer 0.2.0-dev0.

Used like this:

```c
     int n;
     char **cpp;
     z = stringer_new();
     stringer_insert(z, "dog");
     stringer_insert(z, "cat");
     stringer_insert(z, "mouse");
     stringer_insert(z, str); /* arbitrary string */
     stringer_strings(z, &n, &cpp);
     /* n => 3, cpp => {"dog", "cat", "mouse", str, NULL} */
     /* use n and cpp before the next call to stringer_insert() */
```

## Why?

I wanted a way to build up a list of strings one-by-one for situations in which
this process would be repeated millions of times. It's straightforward to create
a NULL-terminated list of strings, but, for me, it got a little tricky
minimizing new mallocs and keeping track of allocated memory. Stringer has an
internal buffer for storing strings

     d o g \0 c a t \0 m o u s e \0 ...
     ^        ^        ^            ^

and another for the pointers to the beginning of each string, indicated by the
^.
