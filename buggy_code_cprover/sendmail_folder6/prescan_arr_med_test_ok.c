#include "../stubs.h"

#define ADDRSIZE        500 
#define PSBUFSIZE       BASE_SZ
#define MAXNAME		(4 * BASE_SZ / 5)
#define NOCHAR		-1
#define TRUE 1
#define FALSE 0

int main (void)
{
  
  char addr[ADDRSIZE];
  char pvpbuf[PSBUFSIZE];

  int p, q, q_old;
  int c;

  int pvpbuf_end = sizeof (pvpbuf);

  int bslashmode;
  int i;

  p = 0;
  q = 0;
  bslashmode = FALSE;

  c = NOCHAR;

  q_old = q;
  do
  {
    if (c != NOCHAR && !bslashmode)
    {
      if (q >= pvpbuf_end - 1)
	return 0;
      pvpbuf[q] = c;
      q++;
    }

    c = addr[p] & 0xff; 
    p++;
    if (c == EOS)
      break;

      
    pvpbuf[q] = EOS; 

    if (bslashmode)
    {
      bslashmode = FALSE;

      if (c != '!')
      {

		
	pvpbuf[q] = '\\'; 
	q++;
	continue;
      }
    }

    if (c == '\\')
      bslashmode = TRUE;
    if (c == NOCHAR)
      continue;
    if (c == EOS)
      break;
  } while (1);

  if (q_old != q)
  {
    
    pvpbuf[q] = 0;
    q++;

    if (q - q_old > MAXNAME)
      return 0;
  }

  return 0;
}
