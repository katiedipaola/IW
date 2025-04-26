#include <stdio.h>

typedef struct {
  int id;
  int a;
  int time;
} T;
T Team[51], tmp;

int main() {
  int i, j, M, T, P, R, m, t, p;
  int mis[51][11];
  while (1) {
    scanf("%d%d%d%d", &M, &T, &P, &R);
    if (M == 0 && T == 0 && P == 0 && R == 0)
      break;
    for (i = 1; i < 51; i++) {
      for (j = 0; j < 11; j++)
        mis[i][j] = 0;
      Team[i].id = i;
      Team[i].a = 0;
      Team[i].time = 0;
    }
    for (i = 0; i < R; i++) {
      scanf("%d%d%d%d", &m, &t, &p, &j);
      if (j != 0)
        mis[t][p]++;
      else {
        Team[t].a++;
        Team[t].time += (m + mis[t][p] * 20);
      }
    }
    for (i = 1; i < T + 1; i++) {
      for (j = T; j > i; j--) {
        if (Team[j].a > Team[j - 1].a) {
          tmp = Team[j];
          Team[j] = Team[j - 1];
          Team[j - 1] = tmp;
        }
        if (Team[j].a == Team[j - 1].a && Team[j].time < Team[j - 1].time) {
          tmp = Team[j];
          Team[j] = Team[j - 1];
          Team[j - 1] = tmp;
        }
        if (Team[j].a == Team[j - 1].a && Team[j].time == Team[j - 1].time &&
            Team[j].id > Team[j - 1].id) {
          tmp = Team[j];
          Team[j] = Team[j - 1];
          Team[j - 1] = tmp;
        }
      }
    }
    printf("%d", Team[1].id);
    for (i = 2; i < T + 1; i++) {
      if (Team[i].a == Team[i - 1].a && Team[i].time == Team[i + 1].time)
        printf("=");
      else
        printf(",");
      printf("%d", Team[i].id);
    }
    printf("\n");
  }
  return 0;
}