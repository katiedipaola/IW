#include <stdio.h>
#include <string.h>

#define AC "AC"
#define WA "WA"
#define TLE "TLE"
#define RE "RE"

int main() {
  int n, ac = 0, wa = 0, tle = 0, re = 0;
  char *judge_result;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", judge_result);
    if (strcmp(judge_result, AC) == 0) {
      ac++;
    } else if (strcmp(judge_result, WA) == 0) {
      wa++;
    } else if (strcmp(judge_result, TLE) == 0) {
      tle++;
    } else if (strcmp(judge_result, RE) == 0) {
      re++;
    }
  }

  printf("AC x %d\n", ac);
  printf("WA x %d\n", wa);
  printf("TLE x %d\n", tle);
  printf("RE x %d\n", re);

  return 0;
}