#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  char s = 'Q';
  int sum = 0;
  getchar();
  for (int i = 0; i < N; i++) {
    char temp = getchar();
    if (temp != s) {
      sum++;
      s = temp;
    }
  }
  printf("%d", sum);
}