#include "dependency.h"

#define SPACE_FOR_VARS 2

static int
rrextract(u_char *msg, int msglen, u_char *rrp, u_char *dname, int namelen)
{
  u_char *eom, *cp, *cp1, *rdatap;
  u_int class, type, dlen;
  int n;
  int n1,n2;
  u_char data[MAXDATA*2 + SPACE_FOR_VARS];
  data [(MAXDATA*2 + SPACE_FOR_VARS)-1] = EOS;

  cp = rrp;
  eom = msg + msglen;

  GETSHORT(dlen, cp);
  BOUNDS_CHECK(cp, dlen);


  n = dn_expand(msg, eom, cp, (char *)data, sizeof data);
	   
  if (n < 0) {
    return (-1);
  }

  if (nondet_int()) {
    return (-1);
  }
  cp += n;

  n1 = strlen((char *)data) + 1;
  cp1 = data + n1 + 1;

  n2 = dlen - n;
  if (n2 > sizeof data - n1) {
    return -1;
  }
  
  r_memcpy(cp1, cp, n2);

  return 0;
}

int main(){
  
  int msglen, ret;
  u_char *dp;
  u_char name [NAMELEN];
  u_char msg [MSGLEN];

  name [NAMELEN-1] = EOS;
  msg [MSGLEN-1] = EOS;

  msglen = MSGLEN;
  dp = msg;

  ret = rrextract(msg, msglen, dp, name, NAMELEN);
  
  return 0;
  
}
