#include "dependency.h"

int parse_expression (char *str) {
  char *except;
  char str2 [LINE_LENGTH+1];

  except = strstr(str, NEEDLE);
  if (except) {
    strncpy (str2, str, (unsigned int)(except-str));
  } else {
    
    r_strcpy (str2, str);
  }

  return 0;
}

int main ()
{
  char A [LINE_LENGTH+1];
  A[LINE_LENGTH] = EOS;

  parse_expression (A);
  return 0;
}
