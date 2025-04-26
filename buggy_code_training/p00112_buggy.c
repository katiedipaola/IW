#include <stdio.h>

int main(void) {
  int n;
  int customer[10000];
  int i;
  int flag;
  int buf;
  int time[10000];
  int total;

  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    for (i = 0; i < n; i++) {
      scanf("%d", &customer[i]);
    }

    /*昇順にソート*/
    flag == 1;
    while (flag == 1) {
      flag = 0;
      for (i = 0; i < n - 1; i++) {
        if (customer[i] > customer[i + 1]) {
          buf = customer[i];
          customer[i] = customer[i + 1];
          customer[i + 1] = buf;
          flag = 1;
        }
      }
    }

    for (i = 0; i < n; i++) {
      time[i] = 0;
    }

    total = 0;
    for (i = 0; i < n; i++) {
      if (i != 0) {
        time[i] = time[i - 1] + customer[i - 1];
        total += time[i];
      }
      /*printf("%d\n", time[i]);*/
    }

    printf("%d\n", total);
  }

  return (0);
}