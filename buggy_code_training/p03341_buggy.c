#include <stdio.h>
int main(void) {
  int n;
  char s[300010];
  scanf("%d", &n);
  scanf("%s", s);

  int east[30010] = {0}, west[30010] = {0};
  east[0] = 0;
  west[0] = 0;
  for (int i = 1; i <= n; i++) {
    east[i] = east[i - 1];
    west[i] = west[i - 1];
    if (s[i - 1] == 'W') {
      west[i]++;
    } else {
      east[i]++;
    }
  }

  // for(int i=0;i<=n;i++){
  //   printf("%d %d\n",east[i],west[i]);
  // }
  int min = n;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    sum += (west[i - 1] - west[0]) + (east[n] - east[i + 1]);
    if (sum < min) {
      min = sum;
    }
  }

  printf("%d\n", min);
  return 0;
}
