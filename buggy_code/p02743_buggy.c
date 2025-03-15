main() {
  long long a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);
  puts(c - a - b < 0 && 4 * a * b < (c - a - b) * (c - a - b) ? "Yes" : "No");
}