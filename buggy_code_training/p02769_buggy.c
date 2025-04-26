#define mod 1000000007
char buf[30];
sz;
char out[10];
osz = 10;
int N, K;
long I[2 << 17] = {1, 1};
main() {
  read(0, buf, 30);
  for (;;) {
    char c = buf[sz++];
    if (c < '0')
      break;
    N = N * 10 + c - '0';
  }
  for (;;) {
    char c = buf[sz++];
    if (c < '0')
      break;
    K = K * 10 + c - '0';
  }
  for (int i = 2; i <= K + 1; i++)
    I[i] = (mod - mod / i) * I[mod % i] % mod;
  long ans = 0;
  long x = 1, y = 1;
  for (long i = 0; i < N && i <= K; i++) {
    ans += x * y % mod;
    x = x * (N - i - 1) % mod * I[i + 1] % mod;
    y = y * (N - i) % mod * I[i + 1] % mod;
  }
  ans %= mod;
  do {
    out[--osz] = ans % 10 + '0';
  } while (ans /= 10);
  write(1, out + osz, 10 - osz);
}
