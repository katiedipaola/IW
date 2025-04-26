#include "dependency.h"
#include "../stubs.h"

#define DATA 100

int main (void)
{
  unsigned char data[sizeof (u_int16_t) + sizeof (u_char) + DATA];
  unsigned char *p;
  int size;
  char *rr_txt;

  p = data;

  NS_GET16(size, p);
  rr_txt = (char *) malloc (size + 1);
  if (rr_txt == 0)
    return 0;

  
  strncpy (rr_txt, (char *) p + 1, *p);
  
  rr_txt[*p] = 0;
}
