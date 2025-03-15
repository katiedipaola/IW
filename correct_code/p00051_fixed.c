#include <stdio.h>

int convert(char *s) {
  int n = 10000000;
  int i, num = 0;
  for (i = 0; i < 8; i++) {
    num += (int)(*(s + i) - '0') * n;
    n /= 10;
  }
  return num;
}

void sort(char *data, int muki) {
  int i, j;
  char tmp;

  for (i = 0; i < 7; i++) {
    for (j = i + 1; j > 0; j--) {
      if (muki == 1) {
        if (*(data + j) < *(data + j - 1)) {
          tmp = *(data + j);
          *(data + j) = *(data + j - 1);
          *(data + j - 1) = tmp;
        }
      } else if (muki == -1) {
        if (*(data + j) > *(data + j - 1)) {
          tmp = *(data + j);
          *(data + j) = *(data + j - 1);
          *(data + j - 1) = tmp;
        }
      }
    }
  }
}

int main() {
  char str[9];
  int max, min, diff, n, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    sort(str, -1);
    max = convert(str);
    sort(str, 1);
    min = convert(str);
    diff = max - min;
    printf("%d\n", diff);
  }
  return 0;
}