#include <stdio.h>

int main(void) {
  int n, a, b, i;
  scanf("%d", &n);
  scanf("%d %d", &a, &b);

  int p[n];
  for (i = 0; i < n; i++)
    scanf("%d", &p[i]);

  int first = 0, second = 0, third = 0, ans;
  for (i = 0; i < n; i++) {
    if (p[i] <= a)
      first++;
    else if (a < p[i] && p[i] <= b)
      second++;
    else
      third++;
  }

  if (first <= second && first <= third)
    ans = first;
  else if (second < first && second <= third)
    ans = second;
  else
    ans = third;

  printf("%d", ans);

  return 0;
}
