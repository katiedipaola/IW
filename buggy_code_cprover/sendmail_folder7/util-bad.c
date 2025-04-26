#include <ctype.h>
#include <stdio.h>
#include <string.h>

int
main (void)
{
  char *gecos, *login, *buf;
  char *p;
  char *bp;
  int l;

  bp = buf;

  if (*gecos == '*')
    gecos++;

  l = 0;
  for (p = gecos; *p != '\0' && *p != ',' && *p != ';' && *p != '%'; p++)
  {
    if (*p == '&')
      l += strlen(login);
    else
      l++;
  }

  for (p = gecos; *p != '\0' && *p != ',' && *p != ';' && *p != '%'; p++)
  {
    if (*p == '&')
    {
      (void) strcpy(bp, login);
      while (*bp != '\0')
	bp++;
    }
    else {
      *bp++ = *p;
    }	    
  }
  *bp = '\0';
}

