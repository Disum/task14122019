#ifndef ARRAY_H
#define ARRAY_H

int read_array(char ***a, const char *name);
void free_array(char **a, int n);
int print_array(char **a, int n, const char *name);

#endif
