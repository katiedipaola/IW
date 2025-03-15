#include <stdio.h>
//#define scanf scanf_s
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
char a[4001];
int main() {
  int n, i, j, k, l, R, G, B;
  long long sum = 0, sum1 = 0;
  j = k = l = R = G = B = 0;
  scanf("%d", &n);
  getchar();
  gets(a);
  for (i = 0; i < n; i++) {
    if (a[i] == 'R')
      R++;
    else if (a[i] == 'G')
      G++;
    else if (a[i] == 'B')
      B++;
  }
  sum = (long long)R * G * B;
  /*for (i = 0; i < n; i++)
  {
          if (a[i] == 'R')  R--, sum += G*B;
          else if (a[i] == 'G')  G--,sum+=R*B;
          else if (a[i] == 'B')  B--,sum+=R*G;
  }*/
  for (i = 0; i < n; i++) {
    for (j = i + 2; j < n; j++) {
      if ((i + j) % 2 != 0)
        continue;
      if (a[i] != a[j] && a[i] != a[(i + j) / 2] && a[j] != a[(i + j) / 2])
        sum--;
    }
  }
  printf("%lld", sum);
}