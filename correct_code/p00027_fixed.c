#include <stdio.h>
main() {
  char W[7][10] = {"Wednesday", "Thursday", "Friday", "Saturday",
                   "Sunday",    "Monday",   "Tuesday"};
  int M, D = 0;
  int a, b, c, d, e, f, g = 0;
  int days = 0;
  int weeks = 0;
  while (1) {
    scanf("%d %d", &M, &D);
    if (M == 0 && D == 0)
      break;
    for (a = 1; a < M; a++) {
      if (a == 2) {
        days = days + 29;
      } else if (a == 4 || a == 6) {
        days = days + 30;
      } else if (a == 9 || a == 11) {
        days = days + 30;
      } else {
        days = days + 31;
      }
    }
    days = days + D;
    weeks = days % 7;
    for (b = 0; b < 7; b++) {
      if (weeks == b) {
        printf("%s\n", W[b]);
      }
    }
    days = 0;
    weeks = 0;
  }
  return 0;
}