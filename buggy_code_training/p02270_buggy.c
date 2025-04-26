w[100000], c, n, k, g, i, l, m, r = 1e9;
f(p) {
  c = 1;
  g = 0;
  for (i = 0; i < n;) {
    if (g + w[i] <= p) {
      g += w[i++];
    } else {
      if (g > 0)
        c++;
      else
        exit(k + 1);
      g = 0;
    }
  }
  return c;
}

main() {
  scanf("%d%d", &n, &k);
  for (; i < n; scanf("%d", w + i++))
    ;
  while (l < r) {
    m = (l + r) / 2;
    if (f(m) > k)
      l = m + 1;
    else
      r = m;
  }
  for (m--;; m++) {
    if (f(m) <= k)
      break;
  }
  printf("%d\n", m);
  return 0;
}
