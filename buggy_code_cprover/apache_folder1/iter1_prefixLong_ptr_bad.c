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

  if (c == '-') {
    GET_CHAR(c, NULL);
    if (c == '-') {
      do {
        GET_CHAR(c, NULL);
      } while (ap_isspace(c));
      if (c == '>') {
        ap_cpystrn(tag, "done", tagbuf_len);
        return tag;
      }
    }
    return NULL;
  }

  while (1) {
    if (t == tag + tagbuf_len) {
      *t = EOS;
      return NULL;
    }
    if (c == '=' || ap_isspace(c)) {
      break;
    }
    *t = ap_tolower(c);
    t++;
    GET_CHAR(c, NULL);
  }

  *t = EOS;
  t++;
  tag_val = t;

  while (ap_isspace(c)) {
    GET_CHAR(c, NULL);
  }
  if (c != '=') {
    return NULL;
  }

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
