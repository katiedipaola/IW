#include "dependency.h"

char *get_tag(char *tag, int tagbuf_len)
{
  char *tag_val, c, term;
  int t;

  t = 0;

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
    if (t == tagbuf_len) {
      tag[t] = EOS;
      return NULL;
    }
    if (c == '=' || ap_isspace(c)) {
      break;
    }
    tag[t] = ap_tolower(c);
    t++;
    GET_CHAR(c, NULL);
  }

  tag[t] = EOS;
  t++;
  tag_val = tag + t;

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
    if (t == tagbuf_len) { 
      tag[t] = EOS;
      return NULL;
    }

    if (c == '\\') {
      
      tag[t] = c;
      t++;               
      GET_CHAR(c, NULL);
      if (c == term) {   
        --t;
        
        tag[t] = c;
      }
    }
    else if (c == term) {
      break;
    }

    
    tag[t] = c;    
    t++;                
  }
  
  tag[t] = EOS;

  return tag;
}

int main ()
{
  char tag[MAX_STRING_LEN];

  get_tag (tag, MAX_STRING_LEN);

  return 0;
}
