#include "dependency.h"
#include "../stubs.h"

int main (void)
{
  unsigned char data[sizeof (u_int16_t) + sizeof (u_char) + BASE_SZ];
  unsigned char *p;
  int size, txtlen;
  char *rr_txt;

  p = data;

  NS_GET16(size, p);

  txtlen = *p;
  rr_txt = (char *) malloc (txtlen + 1);
  if (rr_txt == 0)
    return 0;

  
  strncpy (rr_txt, (char *) p + 1, *p);
  
  rr_txt[*p] = 0;
}
