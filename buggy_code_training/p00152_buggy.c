#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  int score;
} man_t;

int compare(const void *x, const void *y) {
  man_t *a;
  man_t *b;
  a = (man_t *)x;
  b = (man_t *)y;
  if (a->score > b->score)
    return 1;
  if (a->score < b->score)
    return -1;
  if (a->id > b->id)
    return 1;
  if (a->id < b->id)
    return -1;
  return 0;
}

int main(void) {
  man_t mandata[40];
  int score[10][3];
  int mannum;
  int i, j;
  while (1) {
    scanf("%d", &mannum);
    if (mannum == 0)
      break;
    for (i = 0; i < mannum; i++) {
      scanf("%d", &mandata[i].id);
      for (j = 0; j < 9; j++) {
        scanf("%d", &score[j][0]);
        score[j][1] = 0;
        if (score[j][0] != 10)
          scanf("%d", &score[j][1]);
      }
      scanf("%d", &score[9][0]);
      scanf("%d", &score[9][1]);
      score[9][2] = 0;
      if (score[9][0] == 10 || score[9][0] + score[9][1] == 10)
        scanf("%d", &score[9][2]);
      mandata[i].score = 0;
      for (j = 0; j < 9; j++) {
        mandata[i].score += score[j][0] + score[j][1];
        if (score[j][0] == 10) {
          mandata[i].score += score[j + 1][0];
          if (score[j + 1][0] == 10 && j < 8)
            mandata[i].score += score[j + 2][0];
          else
            mandata[i].score += score[j + 1][1];
        } else if (score[j][0] + score[j][1] == 10) {
          mandata[i].score += score[j + 1][0];
        }
      }
      mandata[i].score += score[9][0] + score[9][1] + score[9][2];
    }
    qsort(mandata, mannum, sizeof(man_t), compare);
    for (i = 0; i < mannum; i++) {
      printf("%d %d\n", mandata[i].id, mandata[i].score);
    }
  }
  return 0;
}