
#include "../stubs.h"

int main (void)
{
  char buffer[BASE_SZ+1];
  char input[BASE_SZ+70];
  char *buf;
  char *buflim;
  char *in;
  char cur;

  in = input;
  buf = buffer;
  buflim = &buffer[sizeof buffer - 2];


  cur = *in;
  while (cur != EOS)
  {
    if (buf == buflim)
      break;

    *buf = cur;
    buf++;
out:
    in++;
    cur = *in;
  }

  *buf = '>';
  buf++;

  
  *buf = EOS;
  buf++;

  return 0;
}
