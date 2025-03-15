#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i, j, k, N;
  int i2, i3, i4;
  int a, b, c;
  char A, B, C;
  char input[30010];
  int count;

  scanf("%d", &N);
  scanf("%s", input);
  /*for(i=0;i<N;i++){
    scanf("%d",&input[i]);
  }
  for(i=0;i<N;i++){
    printf("%d",&input[i]);
  }*/

  count = 0;
  for (i = 100; i <= 999; i++) {

    a = i / 100;
    j = i % 100;
    b = j / 10;
    k = i % 10;
    c = k;
    A = '0' + a;
    B = '0' + b;
    C = '0' + c;
    // printf("%c%c%c\n",A,B,C);

    for (i2 = 0; i2 < N; i2++) {
      if (A == input[i2]) {
        for (i3 = i2 + 1; i3 < N; i3++) {
          if (B == input[i3]) {
            for (i4 = i3 + 1; i4 < N; i4++) {
              if (C == input[i4]) {
                count++;
                break;
              }
            }
            break;
          }
        }
        break;
      }
    }
  }

  printf("%d\n", count);

  return 0;
}