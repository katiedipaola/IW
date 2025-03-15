#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define kLENGTH 2000000

int main() {
  int leng, sum = 0;
  char S[kLENGTH], T[kLENGTH];
  scanf("%s", S);
  scanf("%s", T);
  leng = strlen(S);

  for (int i = 0; i < leng; i++) {
    if (S[i] != T[i]) {
      sum++;
    }
  }
  printf("%d\n", sum);
  return 0;
}