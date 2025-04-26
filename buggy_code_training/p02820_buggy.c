#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int R, S, P;

long int point(char s) {
  long int x = 0;
  switch (s) {
  case 'r':
    x = P;
    break;
  case 's':
    x = R;
    break;
  case 'p':
    x = S;
    break;
  }
  return x;
}

int main(void) {
  char str[1000000];
  long int K, N, i, j, k, sum;
  int flag = 0;

  fgets(str, sizeof(str), stdin);
  N = atoi(strtok(str, " "));
  K = atoi(strtok(NULL, " "));
  fgets(str, sizeof(str), stdin);
  R = atoi(strtok(str, " "));
  S = atoi(strtok(NULL, " "));
  P = atoi(strtok(NULL, " "));
  fgets(str, sizeof(str), stdin);

  sum = 0;
  for (i = 0; i < K; i++) {
    sum += point(str[i]);
    for (j = 1; i + j * K < N; j++) {
      if (str[i + j * K] != str[i + (j - 1) * K]) {
        sum += point(str[i + j * K]);
        flag = 0;
      } else {
        if (flag == 0) {
          flag = 1;
        } else {
          sum += point(str[i + j * K]);
          flag = 0;
        }
      }
    }
  }
  printf("%ld\n", sum);
  return 0;
}
