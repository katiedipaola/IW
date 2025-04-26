#include "dependency.h"

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
  char in [INSZ];
  in [INSZ-1] = EOS;

  ftpls(in);

  return 0;
}
