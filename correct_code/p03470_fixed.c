#include <stdio.h>
int main() {
  int a;
  scanf("%d", &a);
  int c = a;
  int b[a];
  for (int i = 0; i < a; i++) {
    scanf("%d", &b[i]);
    for (int j = 0; j < i; j++) {
      if (j != i && b[j] == b[i]) {
        c--;
        break;
      }
    }
  }
  printf("%d\n", c);
  return 0;
}