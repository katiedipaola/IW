#include <stdio.h>
int main(void) {
  int q1, b, c1, c2, q2;
  int aizu_c, normal_c, leaveMoney;
  while (1) {
    scanf("%d", &q1);
    if (q1 == 0)
      break;
    scanf("%d %d %d %d", &b, &c1, &c2, &q2);
    aizu_c = 0;
    normal_c = 0;
    leaveMoney = b;
    while (leaveMoney - c1 >= 0 && aizu_c < q2) {
      leaveMoney -= c1;
      aizu_c++;
    }
    while (leaveMoney - c2 >= 0) {
      leaveMoney -= c2;
      normal_c++;
    }
    while (1) {
      if (aizu_c == 0) {
        printf("NA\n");
        break;
      } else if (aizu_c + normal_c >= q1) {
        printf("%d %d\n", aizu_c, normal_c);
        break;
      } else if (aizu_c != 0) {
        aizu_c--;
        leaveMoney += c1;
        normal_c += leaveMoney / c2;
        leaveMoney -= c2 * (leaveMoney / c2);
      }
    }
  }
  return 0;
}