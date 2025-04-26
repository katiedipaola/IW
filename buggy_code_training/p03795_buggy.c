int main(int argc, const char *argv[]) {
  int x = 0, y = 0, N, sum = 0;

  scanf("%d\n", &N);

  if (N % 15 == 0) {
    y = 200 * (N / 15);
  }

  x = 800 * N;

  sum = x - y;
  printf("%d", sum);
  return 0;
}
