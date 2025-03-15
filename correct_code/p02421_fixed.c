#include <stdio.h>
int main(void) {
  int n, i;
  int pt = 0, ph = 0;
  char taro[101], hana[101];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", taro, hana);
    // printf("%d %d\n",taro[0],hana[0]);
    if (strcmp(taro, hana) > 0)
      pt += 3;
    else if (strcmp(taro, hana) < 0)
      ph += 3;
    else {
      pt++;
      ph++;
    }
  }
  printf("%d %d\n", pt, ph);
  return 0;
}