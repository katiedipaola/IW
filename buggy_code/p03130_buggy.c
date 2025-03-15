#include <stdio.h>
int main() {
  int a, b, city[4] = {0, 0, 0, 0}, judge = 0;
  for (int i = 0; i < 3; i++) {
    scanf("%d%d", &a, &b);
    city[a - 1]++;
    city[b - 1]++;
  }
  for (int i = 0; i < 4; i++) {
    if (city[i] == 0 || city[i] > 2) {
      printf("NO\n");
      break;
    }
  }
  if (judge == 4) {
    printf("YES\n");
  }
  return 0;
}