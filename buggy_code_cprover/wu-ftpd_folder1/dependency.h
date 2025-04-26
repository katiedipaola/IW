#include "../stubs.h"

#define MAXPATHLEN BASE_SZ + 3

typedef short uid_t;
uid_t geteuid(void);
int seteuid(uid_t euid);

int     enable_signaling();
int     delay_signaling();

int readlink(const char *path, char *buf, int bufsiz);
char *getcwd(char *buf, size_t size);
