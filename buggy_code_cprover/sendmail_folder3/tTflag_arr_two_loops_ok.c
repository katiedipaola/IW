#include "../stubs.h"

#define INSIZE 14

int main (void)
{
  unsigned char in[INSIZE+1];
  unsigned char buf[BASE_SZ];
  unsigned char *s;
  unsigned char c;
  unsigned int first, last;
  int i, j;
  int idx_in;

  idx_in = 0;
  s = in;
  i = 0;

  c = in[idx_in];
  while (('0' <= c) && (c <= '9'))
  {
    j = c - '0';
    i = i * 10 + j;
    idx_in++;
    c = in[idx_in];
  }
  first = i;

  c = in[idx_in];
  if (c == '-')
  {
    i = 0;
    idx_in++;
    c = in[idx_in];
    while (('0' <= c) && (c <= '9'))
    {
      j = c - '0';
      i = i * 10 + j;
      idx_in++;
      c = in[idx_in];
    }
  }
  last = i;


  if (first >= BASE_SZ) 
    first = BASE_SZ - 1;
  if (last >= BASE_SZ)  
    last = BASE_SZ - 1;

  while (first <= last)
  {
    
    buf[first] = 'a';
    first++;
  }

  return 0;
}
