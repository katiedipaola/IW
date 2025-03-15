#include <stdio.h>
int main(void) {
  int n;
  long int i, j, k, ans = 0;
  long int ma[5] = {};
  char str[10] = {};
  char march[5] = {'M', 'A', 'R', 'C', 'H'};
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    // printf("%s\n",str);
    for (j = 0; j < 5; j++) {
      if (str[0] == march[j])
        ma[j]++;
    }
    // printf("ii=%d\n",i);
  }
  for (i = 0; i < 5; i++) {
    for (j = i + 1; j < 5; j++) {
      for (k = j + 1; k < 5; k++) {
        ans += ma[i] * ma[j] * ma[k];
      }
    }
  }
  printf("%ld", ans);
  return 0;
}
