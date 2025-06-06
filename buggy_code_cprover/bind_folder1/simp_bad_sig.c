#include "dependency.h"

#define SPACE_FOR_VARS INT32SZ

static int
rrextract(u_char *msg, int msglen, u_char *rrp, u_char *dname, int namelen)
{

  u_char *eom, *cp, *cp1, *rdatap;
  u_int class, type, dlen;
  int n;
  long origTTL;
  u_char data[MAXDATA*2+SPACE_FOR_VARS];
  data [(MAXDATA*2)-1+SPACE_FOR_VARS] = EOS;

  cp = rrp;
  eom = msg + msglen;

  GETSHORT(dlen, cp);
  BOUNDS_CHECK(cp, dlen);

  cp1 = (u_char *)data;
  BOUNDS_CHECK(cp, SPACE_FOR_VARS);
  memcpy(cp1, cp, SPACE_FOR_VARS);
  cp += SPACE_FOR_VARS;
  cp1 += SPACE_FOR_VARS;

  n = nondet_int();		
  if (n < 0) {
    return (-1);
  }

  n = dlen - (SPACE_FOR_VARS + n);
  if (n > (int)(sizeof data) - (cp1 - (u_char *)data)) {
    return (-1);  
  }
  
  r_memcpy(cp1, cp, n);


  return 0;
}

int main(){
  
  int msglen, ret;
  u_char *dp;
  u_char name [NAMELEN];
  u_char msg [MSGLEN+SPACE_FOR_VARS];

  name [NAMELEN-1] = EOS;
  msg [MSGLEN-1+SPACE_FOR_VARS] = EOS;

  msglen = MSGLEN;
  dp = msg;

  ret = rrextract(msg, msglen, dp, name, NAMELEN);
  
  return 0;
  
}
