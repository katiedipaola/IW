#include "dependency2.h"

char in [INSZ];

static NSS_STATUS
_nss_winbind_ipnodes_getbyname(void *args)
{
  nss_XbyY_args_t *argp = (nss_XbyY_args_t*) args;
  struct winbindd_request request;

  
  r_strncpy(request.data.winsreq, argp->key.name, FSTRING_LEN) ;

  return 0;
}

int main ()
{
  nss_XbyY_args_t k;

  in[INSZ] = EOS;
  k.key.name = in;

  _nss_winbind_ipnodes_getbyname(&k);

  return 0;
}

