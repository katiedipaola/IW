#include "dependency.h"

#ifndef BOOL
typedef int BOOL;
#endif

struct winbindd_request {
  union {
    fstring winsreq;
    BOOL list_all_domains;
  } data;
};

union nss_XbyY_key {
  const char *name;
  int number;
};

typedef struct nss_XbyY_args {
  union nss_XbyY_key key;
} nss_XbyY_args_t;

