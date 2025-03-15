#include <stdio.h>

int main() {
  int H, W, A, B;
  scanf("%d %d %d %d", &H, &W, &A, &B);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      putchar('0' + ((i > B) ^ (j > A)));
    }
    putchar('\n');
  }
  return 0;
}
