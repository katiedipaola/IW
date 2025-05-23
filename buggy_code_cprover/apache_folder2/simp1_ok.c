#include "dependency.h"

void escape_absolute_uri (char *uri)
{
  int cp;
  char *token[TOKEN_SZ];
  int c;

  cp = 0;
  c = 0;

  token[0] = uri;
  while (uri[cp] != EOS
         && c < TOKEN_SZ - 1) {
    if (uri[cp] == '?') {
      ++c;
      
      token[c] = uri + cp + 1;
      uri[cp] = EOS;
    }
    ++cp;
  }

  return;
}

int main ()
{
  char uri [URI_SZ];

  uri [URI_SZ-1] = EOS;

  escape_absolute_uri (uri);

  return 0;
}
