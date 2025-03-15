i, j, k;
long a[444], p[444][444], S, T, P;
main() {
  scanf("%*d");
  for (; ~scanf("%ld", &T);) {
    for (a[i = j++] = T; i--; p[i][j] = P) {
      P = 9e18;
      for (T += a[k = i]; ++k < j;) {
        P = fmin(P, p[i][k] + p[k][j] + T);
      }
    }
  }
  printf("%ld", P);
}