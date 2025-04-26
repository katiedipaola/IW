s, t, n;
main(a) {
  for (; ~scanf("%d", &a);)
    n ? a % 4 ? a % 2 ? 0 : ++t : ++s : (n = a);
  puts(n > s + t / 2 ? "No" : "Yes");
}