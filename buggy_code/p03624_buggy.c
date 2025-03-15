#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char s[100001];
  int a[26] = {0};
  int i, j;
  scanf("%s", s);
  for (i = 0; i < strlen(s); i++) {
    for (j = 0; j < 26; j++) {
      if (s[i] == j + 97) {
        a[j]++;
      }
    }
  }
  int count = 0;
  for (i = 0; i < 26; i++) {
    if (a[i] == 0) {
      printf("%c\n", i + 97);
      break;
    }
    count++;
  }
  if (count == 26) {
    printf("none\n");
  }
  return 0;
}
