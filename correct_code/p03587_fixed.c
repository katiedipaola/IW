s;
main(n) {
  for (scanf("%d", &n); n; s += n % 10, n /= 10)
    ;
  printf("%d\n", s);
  exit(0);
}