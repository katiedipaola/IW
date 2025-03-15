#include <stdio.h>
// #include<math.h>
// #include<stdlib.h>
// #include<string.h>
// #include<stdbool.h>

// #define MOD 998244353

// #define MIN(a,b) ((a)<(b)?(a):(b));
// #define MAX(a,b) ((a)>(b)?(a):(b));

// typedef long long int64;

int main(void) {
  int H, W;
  scanf("%d %d", &H, &W);
  int h, w;
  scanf("%d %d", &H, &W);

  printf("%d", (H - h) * (W - w));

  return 0;
}