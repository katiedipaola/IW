#include <stdio.h>
int main() {

  int a[10];
  int sum[10 * 9 * 8 / 6];
  int i, j, k, l;
  int max;

  for (i = 0; i < 10; i++)
    scanf("%d", &a[i]);
  l = 0;
  for (i = 0; i < 10; i++)
    for (j = i + 1; j < 10; j++)
      for (k = j + 1; k < 10; k++)
        sum[l++] = a[i] + a[j] + a[k];
  max = 0;
  for (i = 0; i < 10 * 9 * 8 / 6; i++)
    if (max < sum[i])
      max = sum[i];
  printf("%d\n", max);
  for (i = 0; i < 10; i++)
    scanf("%d", &a[i]);
  l = 0;
  for (i = 0; i < 10; i++)
    for (j = i + 1; j < 10; j++)
      for (k = j + 1; k < 10; k++)
        sum[l++] = a[i] + a[j] + a[k];
  max = 0;
  for (i = 0; i < 10 * 9 * 8 / 6; i++)
    if (max < sum[i])
      max = sum[i];
  printf("%d\n", max);

  return 0;
}