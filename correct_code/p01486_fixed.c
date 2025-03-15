/*
AizuOnline A2369
cat checker
*/
#include <stdio.h>
#include <string.h>

#define MAXLEN 500
char S[MAXLEN + 1];
char stack[MAXLEN + 1];
int depth;
int state;
#define AFTERW 0
#define AFTERM 1
#define AFTERMW 2
#define AFTERE 3
#define AFTEREW 4

int ismew(char *s, int len) {
  int i, state;
  char c;
  if (len == 0)
    return (1);
  depth = 0;
  state = AFTERW;
  for (i = 0; i < len; i++) {
    c = s[i];
    // printf("%d %c:",state,c);
    if (c == 'm') {
      if (state == AFTERW && i == 0) {
        stack[depth] = state;
        depth++;
        state = AFTERM;
      } else if (state == AFTERM || state == AFTERE) {
        stack[depth] = state;
        state = AFTERM;
        depth++;
      } else
        return (0);
    } else if (c == 'e') {
      if (state == AFTERM || state == AFTERMW)
        state = AFTERE;
      else
        return (0);
    } else if (c == 'w') {
      if (state == AFTERE || state == AFTEREW) {
        depth--;
        state = stack[depth];
        if (state != AFTERW)
          state++;
      } else
        return (0);
    }
    // printf("%d\n",state);
  }
  if (depth == 0 && state == AFTERW)
    return (1);
  else
    return (0);
}

main() {
  int ret;

  scanf("%s", S);

  ret = ismew(S, strlen(S));

  printf("%s\n", ret ? "Cat" : "Rabbit");

  return (0);
}