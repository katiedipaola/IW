#include "dependency.h"

int fetchsms (char *pdu, int sim)
{
  char answer[ANSWERSIZE];
  int position;
  int beginning;
  int end;
  int  foo,err;

  answer[ANSWERSIZE-1] = EOS;

  position=istrstr(answer,NEEDLE);
  if (position==-1)
    return 0;
  beginning = position + NEEDLE_SZ + 1;

  
  r_strcpy(pdu,answer+beginning);
  
  return sim;
}

int main ()
{
  char pdu [ANSWERSIZE];
  int sim = 0;

  fetchsms (pdu, sim);

  return 0;
}
