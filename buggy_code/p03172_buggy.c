long d[2 << 17], *p, m = 1e9 + 7;
j;
main(a, k) {
  scanf("%*d%d", &k);
  p = d + k;
  for (*p = 1; ~scanf("%d", &a);) {
    // for(;d-p--;)*p+=p[1];for(;p++-d<k;*p%=m)*p-=p[a+1];
    j = 0;
    for (; j ? p++ - d < k : d - p-- || (j = 1); *p %= m)
      *p += j ? -p[a + 1] : p[1];
  }
  printf("%ld", *d);
}