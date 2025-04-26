#include "dependency.h"

static int
gdTcl_UtfToUniChar (char *str, Tcl_UniChar * chPtr)
{
  int byte;

  byte = (unsigned char)(str[0]);
  if (byte < 0xC0) {
    return 1;
  }
  else if (byte < 0xE0) {
    if ((str[1] & 0xC0) == 0x80) {
      return 2;
    }
    return 1;
  }
  else if (byte < 0xF0) {
    if (((str[1] & 0xC0) == 0x80) && ((str[2] & 0xC0) == 0x80)) {
      return 3;
    }
    return 1;
  }

  return 1;
}

void gdImageStringFTEx (char *string) {
  int next;
  int encoding;
  int i;
  int ch;
  int len;

  encoding = nondet_int();
  if (encoding > 2 || encoding < 0)
    return;

  next = 0;

  
  for (i=0; string[next] != EOS; i++)
    {

      ch = string[next];

      if (ch == '\r')
	{
	  next++;
	  continue;
	}
      if (ch == '\n')
	{
	  next++;
	  continue;
	}


      switch (encoding)
        {
        case gdFTEX_Unicode:
          {
            len = gdTcl_UtfToUniChar (string + next, &ch);
            next += len;
          }
          break;
        case gdFTEX_Shift_JIS:
          {
            unsigned char c;
            c = (unsigned char) string[next];
            if (0xA1 <= c && c <= 0xFE)
              {
                next++;
              }
            next++;
          }
          break;
        case gdFTEX_Big5:
          {
            ch = (string[next]) & 0xFF;	
            next++;
            if (ch >= 161
                && string[next] != EOS)
              {
                next++;
              }
          }
          break;
        }
    }
}

int main ()
{
  char in [INSZ];
  in [INSZ-1] = EOS;

  gdImageStringFTEx (in);

  return 0;
}

