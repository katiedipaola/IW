#include <stdio.h>
#include <string.h>

int main(void) {

  char S[10];
  scanf("%s", S);
  if (S[0] == 'A') {

    int n;
    int flag = 0;
    for (n = 2; n < strlen(S) - 2; n++) {
      if (S[n] == 'C') {
        if (flag == 0) {
          flag = 1;
        } else {
          flag = 0;
          break;
        }
      }
    }

    if (flag) {
      int sum = 0;
      for (n = 0; n < strlen(S); n++) {
        if (S[n] >= 97 && S[n] <= 122) {
          sum++;
        }
      }

      if (sum == strlen(S) - 2) {
        printf("AC\n");
      } else {
        printf("WA\n");
      }

    } else {
      printf("WA\n");
    }

  } else {
    printf("WA\n");
  }

  return 0;
}
