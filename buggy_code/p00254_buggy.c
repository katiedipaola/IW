#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp1(const void *a, const void *b) { return *(char *)a - *(char *)b; }
int comp2(const void *a, const void *b) { return *(char *)b - *(char *)a; }

int ctoi(char *s) {
  return ((s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 +
          (s[3] - '0') * 1);
}
int func(char *s) {
  int a, b;
  qsort(s, 4, sizeof(char), comp2);
  a = ctoi(s);
  qsort(s, 4, sizeof(char), comp1);
  b = ctoi(s);
  // printf("%d %d\n",a,b);

  return (a - b);
}

int main() {
  char n[9];
  int i, ans, a;

  while (1) {
    scanf("%s", n);
    if (strcmp(n, "0000") == 0)
      break;
    for (i = 0; i < 3; i++)
      if (n[i] != n[i + 1])
        break;
    if (i == 3) {
      printf("NA\n");
      continue;
    }
    ans = 0;
    while (ctoi(n) != 6174 && ans < 5) {
      a = func(n);
      n[0] = (a / 1000) % 10 + '0';
      n[1] = (a / 100) % 10 + '0';
      n[2] = (a / 10) % 10 + '0';
      n[3] = (a / 1) % 10 + '0';
      ans++;
    }
    printf("%d\n", ans);
  }

  return 0;
}