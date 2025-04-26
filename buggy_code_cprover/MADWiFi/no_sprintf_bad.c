#include "dependency.h"

static u_int
encode_ie(void *buf, size_t bufsize,                  
               const u_int8_t *ie, size_t ielen,          
	       const char *leader, size_t leader_len)
{
  u_int8_t *p;
  int i;

  if (bufsize < leader_len)
    return 0;
  p = buf;
  memcpy(p, leader, leader_len);
  bufsize -= leader_len;
  p += leader_len;

  for (i = 0; i < ielen && bufsize > 2; i++) {

    *p = 'x';
    *(p+1) = 'x';
    p += 2;
  }
  return (i == ielen ? p - (u_int8_t *)buf : 0);
}

int main()
{
  u_int8_t buf [BUFSZ];
  u_int8_t ie [IESZ];
  char leader [LEADERSZ];

  encode_ie (buf, BUFSZ,
             ie, IESZ,
             leader, LEADERSZ);

  return 0;
}
