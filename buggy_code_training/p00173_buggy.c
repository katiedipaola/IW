#include <stdio.h>
int main() {
  char cl[20];
  int i, am, pm, yen;
  for (i = 0; i < 9; i++) {
    scanf("%s%d%d", &cl, &am, &pm);
    printf("%s%d%d\n", cl, am + pm, am * 200 + pm * 300);
  }
  return 0;
}