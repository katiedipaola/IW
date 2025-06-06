#include "dependency.h"

static int parse_expression_list(char *str) 
{
  int start=0, i=-1, j=-1, apost=0;
  char str2[EXPRESSION_LENGTH];
	
  if (!str) return -1;

  do {

    i++;
    switch(str[i]) {
    case ',':
    case EOS:
      while ((str[start] == ' ')) start++;

      j = i-1;

      if (start<=j) {
        
        r_strncpy(str2, str+start, j-start+1);
        str2[j-start+1] = EOS;
      } else {
        return -1;
      }
      start = i+1;
    }
  } while (str[i] != EOS);
	
  return 0;
}


int main ()
{
  char A [LINE_LENGTH+1];
  A[LINE_LENGTH] = EOS;

  parse_expression_list (A);
  return 0;
}
