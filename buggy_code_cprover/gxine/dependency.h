#include "../stubs.h"

#define SUN_PATH_SZ BASE_SZ + 1

#define FILENAME_SZ SUN_PATH_SZ + 2

struct sockaddr_un
{
  char sun_path[SUN_PATH_SZ];
};
