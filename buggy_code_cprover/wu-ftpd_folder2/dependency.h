#include "../stubs.h"

#define MAXPATHLEN BASE_SZ + 2

#define MAXSYMLINKS 1

int readlink(const char *path, char *buf, int bufsiz);
char *getcwd(char *buf, size_t size);

