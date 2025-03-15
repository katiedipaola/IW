#include <stdio.h>
int main() {
  int a[6], i, k;
  int max = 0;
  int min = 123;

  for (i = 1; i <= 5; i++) {
    scanf("%d", &a[i]);
    if (max < a[i])
      max = a[i];
    if (min > a[i])
      min = a[i];
  }
  scanf("%d", &k);

  if (max - min > k)
    printf(":(");
  else
    printf("Yay!");

  return 0;
}
