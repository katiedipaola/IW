int main() {
  int a, b, c = 0;
  scanf("%d%d", &a, &b);
  if (a == 1 && b == 1)
    c = 400000;
  if (a == 1)
    c += 300000;
  if (a == 2)
    c += 200000;
  if (a == 3)
    c += 100000;
  if (b == 1)
    c += 300000;
  if (b == 2)
    c += 200000;
  if (b == 3)
    c += 100000;
  printf("%d\n", c);
  return 0;
}