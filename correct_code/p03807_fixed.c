#include <stdio.h>

int en;
int on;
int N;

void input() {
  int i, t;
  en = 0;
  on = 0;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &t);
    if (t % 2 == 0) {
      en++;
    } else {
      on++;
    }
  }
  return;
}

int main() {
  input();
  if (on % 2 == 0 || (on == 1 && en == 0)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
