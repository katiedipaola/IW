#include <stdio.h>
int cnt = 0, n, s;
void func(int sum, int depth, int x) {
  int i;
  if (depth > n) {
    if (sum == s) {
      cnt++;
    }
    return;
  }
  for (i = x; i < 10; i++) {
    // if(sum+i>s)return;

    func(sum + i, depth + 1, i + 1);
  }
}
int main(void) {
  while (scanf("%d %d", &n, &s), n || s) {
    cnt = 0;
    func(0, 1, 0);
    printf("%d\n", cnt);
  }
  return 0;
}