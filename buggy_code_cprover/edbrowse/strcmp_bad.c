#include "dependency.h"

extern int nondet_int();

void ftpls (char *line)
{
    int j;

    for(j = 0; line[j] != EOS; ++j)
      if (!strchr("-", line[j]))
        break;

    if(j == J && line[j] == ' ') {	

      char user[USERSZ];
      
      r_strcpy (user, line + j);
    }
}

int main ()
{
  char out [INSZ];
  int out_l;
  bool dirmode;
  static const char npf[] = NPF;
  const int npfsize = NPFSZ;
  int c;

  dirmode = false;

  out_l = 0;
  out[INSZ-1] = EOS;

 top:

  while((c = nondet_int()) != EOF) {
    if(c == '\r')
      c = '\n';
    if(c == '\n') {
      if(dirmode) {
        ftpls(out);
      } else {
        if(!out_l)
          continue;
        assert (out_l <= INSZ-1);
        if (out_l > npfsize && !strcmp(out + out_l - npfsize, npf)) {
          dirmode = true;
          goto top;
        }
      }
      out_l = 0;
    } else {
      out_l++;
      if (out_l > INSZ-1)
        return ERR;
    }
  }

  return 0;
}
