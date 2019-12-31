# stringer 0.2.0-dev0.

Used like this:

```c
     int n;
     char **cpp;
     z = stringer_new();
     stringer_insert(z, "dog");
     stringer_insert(z, "cat");
     stringer_insert(z, "mouse);
     stringer_insert(z, str); /* arbitrary string */
     stringer_strings(z, &n, &cpp);
     /* n => 3, cpp => {"dog", "cat", "mouse", str, NULL} */
```
