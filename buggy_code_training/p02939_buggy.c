#include <stdio.h>
#include <string.h>

#define MAX 200000

int main(void) {
  long i, ans1 = 0, ans2 = 1;

  char str[MAX + 1];
  scanf(" %s", str);

  int reset = 0;
  for (i = 1; i < strlen(str); i++) {
    if (reset == 0) {
      ans1++;
      reset = 1;
    } else if (str[i] != str[i - 1]) {
      ans1++;
    } else if (i != strlen(str) - 1) {
      ans1++;
      i++;
      reset = 0;
    }
  }

  reset = 0;
  for (i = 2; i < strlen(str); i++) {
    if (reset == 0) {
      ans2++;
      reset = 1;
    } else if (str[i] != str[i - 1]) {
      ans2++;
    } else if (i != strlen(str) - 1) {
      ans2++;
      i++;
      reset = 0;
    }
  }

  if (ans1 >= ans2) {
    printf("%ld\n", ans1);
  } else {
    printf("%ld\n", ans2);
  }

  return 0;
}
