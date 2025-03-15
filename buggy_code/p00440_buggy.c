#include <stdio.h>
int smax(int *list, int n) {
  int max, sec, maxreal, i;
  max = sec = maxreal = 0;
  for (i = 0; i < n; i++)
    if (list[i] == 1) {
      max++;
      sec++;
    } else if (list[i] == 0)
      if (max > maxreal) {
        maxreal = max;
        max = sec + 1;
        sec = 0;
      } else {
        max = sec + 1;
        sec = 0;
      }

  if (max > maxreal)
    maxreal = max;
  return maxreal;
}
int nmax(int *list, int n) {
  int max, sec, maxreal, i;
  max = sec = 0;
  for (i = 0; i < n; i++)
    if (list[i] == 1) {
      sec++;
    } else {
      if (max < sec) {
        max = sec;
        sec = 0;
      }
    }
  if (max < sec)
    max = sec;
  return max;
}
int main() {

  int list[100000];
  int i, n, k, flag, tmp, max, j;

  while (1) {
    flag = 0;
    scanf("%d %d", &n, &k);

    if (n == 0 && k == 0)
      break;
    for (i = 0; i < 100000; i++)
      list[i] = 0;

    for (i = 0; i < k; i++) {

      scanf("%d", &tmp);

      if (tmp == EOF)
        break;
      if (tmp > 0)
        list[tmp - 1] = 1;
      else
        flag = 1;
      /*	for(j=0;j<n;j++)
        printf("%d\n",list[j]);
      printf("--------\n");
      */
    }
    if (flag == 1)
      printf("%d\n", smax(list, n));
    else
      printf("%d\n", nmax(list, n));
  }
  return 0;
}