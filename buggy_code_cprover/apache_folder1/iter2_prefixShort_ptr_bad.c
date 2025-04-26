#include "dependency.h"

char *get_tag(char *tag, int tagbuf_len)
{
  char *tag_val, c, term;
  char *t;

  t = tag;

  --tagbuf_len;

  do {
    GET_CHAR(c, NULL);
  } while (ap_isspace(c));

  if (c != '"' && c != '\'') {
    return NULL;
  }
  term = c;
  while (1) {
    GET_CHAR(c, NULL);
    if (t == tag + tagbuf_len) { 
      *t = EOS;
      return NULL;
    }  
    
    if (c == '\\') {
      
      *t = c;
      t++;               
      GET_CHAR(c, NULL);
      if (c == term) {   
        --t;
        
        *t = c;
      }
    }
    else if (c == term) {
      break;
    }
    
    *t = c;    
    t++;
  }
  
  *t = EOS;

  return tag;
}

int main ()
{
  char tag[MAX_STRING_LEN];

  get_tag (tag, MAX_STRING_LEN);

  return 0;
}
