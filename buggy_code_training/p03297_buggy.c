int main(void) {
  int t, i;
  long long reft, r, x, y, s, e, k;
  scanf("%d", &t);
  long long a[300], b[300], c[300], d[300];
  for (i = 0; i <= t - 1; i++) {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
    scanf("%lld", &c[i]);
    scanf("%lld", &d[i]);
  }

  for (i = 0; i <= t - 1; i++) {
    if (a[i] < b[i])
      printf("No\n");
    else if (b[i] > d[i])
      printf("No\n");
    else if (b[i] - 1 <= c[i])
      printf("Yes\n");
    else {
      reft = a[i] % b[i];

      if (reft > c[i])
        printf("No\n");
      else {
        x = d[i];
        y = b[i];

        r = x % y;
        while (r != 0) {
          x = y;
          y = r;
          r = x % y;
        }

        c[i] = c[i] - reft;
        e = b[i] - reft;
        k = c[i] % y;
        s = (c[i] - k) / y;

        if ((s + 1) * y < b[i])
          printf("No\n");
        else
          printf("Yes\n");
      }
    }
  }
  return 0;
}