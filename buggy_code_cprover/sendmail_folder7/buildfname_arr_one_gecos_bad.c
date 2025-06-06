#define BUF BASE_SZ
#define GECOS 1
#define LOGIN (BASE_SZ + 1)/GECOS 

#include "../stubs.h"

int
main (void)
{
  char login[LOGIN + 1];
  char gecos[GECOS + 1];

  char buf[BUF + 1];
  char c;
  int i, j;

  login[(int) (sizeof login - 1)] = EOS;
  gecos[(int) (sizeof gecos - 1)] = EOS;

  i = 0;
  if (gecos[i] == '*')
    i++;

  c = gecos[i];
  j = 0;
  while (c != EOS && c != ',' && c != ';' && c != '%')
  {
    if (c == '&')
    {
      
      (void) strcpy (buf + j, login);
      while (buf[j] != EOS)
	j++;
    }
    else
    {
      
      buf[j] = c;
      j++;
    }	    
    i++;
    c = gecos[i];
  }
  buf[j] = EOS;
  return 0;
}
