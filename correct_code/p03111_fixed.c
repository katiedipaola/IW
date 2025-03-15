#include <stdio.h>

int abs(int n) {
  if (n < 0) {
    n *= -1;
  }
  return n;
}

int main(void) {
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);

  int l[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }

  int max = 1;
  for (int i = 0; i < n; i++) {
    max *= 4;
  }

  int aa, bb, cc;
  int q, ans = 1000000000, count, j;

  for (int i = 0; i < max; i++) {
    q = i;
    aa = bb = cc = 0;
    count = 0;
    j = 0;
    while (q > 0) {
      if (q % 4 == 1) {
        if (aa > 0) {
          count += 10;
        }
        aa += l[j];
      }
      if (q % 4 == 2) {
        if (bb > 0) {
          count += 10;
        }
        bb += l[j];
      }
      if (q % 4 == 3) {
        if (cc > 0) {
          count += 10;
        }
        cc += l[j];
      }
      j++;
      q /= 4;
    }
    if (aa == 0 || bb == 0 || cc == 0) {
      continue;
    }
    count += abs(a - aa) + abs(b - bb) + abs(c - cc);
    if (ans > count) {
      ans = count;
    }
  }

  printf("%d", ans);

  return 0;
}
