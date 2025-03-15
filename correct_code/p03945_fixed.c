#include <stdio.h>
#include <stdlib.h>

int main() {
  char *state;
  state = (char *)malloc(sizeof(char) * 100001);
  scanf("%s", state);
  int i = 0, count = 0;
  char current = state[0];
  while (state[i] != '\0') {
    if (state[i] != current) {
      count++;
      current = state[i];
    }
    i++;
  }
  printf("%d", count);
  free(state);
  return 0;
}