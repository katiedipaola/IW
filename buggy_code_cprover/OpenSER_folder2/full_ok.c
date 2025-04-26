#include "dependency.h"

int fetchsms (char *pdu, int sim)
{
  char answer[ANSWERSIZE];
  int position;
  int beginning;
  int end;
  int  foo,err;

  answer[ANSWERSIZE-1] = EOS;

  if (nondet_int() == 0) {
    position=istrstr(answer, NEEDLE);
    if (position != -1) {
      end=position+NEEDLE_SZ;
      while (answer[end] < '9' && answer[end] > '0')
        end++;
      position = 0;
    }
  } else {
    position=istrstr(answer, NEEDLE);
  }

  if (position==-1)
    return 0;
  beginning = position + NEEDLE_SZ + 1;

  if (istrstr(answer, NEEDLE2) == -1)
    return 0;

  for( end=beginning ; answer[end] != EOS && answer[end] != '\r' ; end++ );
  if ( answer[end] == EOS || end-beginning < MIN_DIFF)
    return 0;
  for( end=end+1 ; answer[end] != EOS && answer[end] !='\r' ; end++ );
  if ( answer[end] == EOS || end-beginning < MIN_DIFF )
    return 0;

  answer[end] = EOS;

  
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
