#include "../stubs.h"

typedef char u_char;
typedef int u_int;
typedef int u_int32_t;

#define MAXDATA BASE_SZ

#define MSGLEN  MAXDATA + 2

#define NAMELEN 3

#define INT16SZ 2
#define INT32SZ 4

#define CLASS_MAX 100
#define MAXIMUM_TTL 101

#define GETSHORT(to, from) \
  do {(to) = nondet_short(); (from) += INT16SZ;} while(0)
#define GETLONG(to, from) \
  do {(to) = nondet_long(); (from) += INT32SZ;} while(0)
#define BOUNDS_CHECK(ptr, count) \
  do {if ((ptr) + (count) > eom) return -1;} while(0)

int dn_expand(const u_char *msg, const u_char *eomorig,
              const u_char *comp_dn, char *exp_dn, int length);


extern int nondet_int();
