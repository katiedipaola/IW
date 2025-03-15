#include <stdio.h>
#include <string.h>

typedef struct {
  char name[12];
  int disp_num;
  int disp_time[30];
  int points;
} kyara_t;

int kyara_num;
kyara_t kyara[20];

int all_disp_num[30];

int main(void) {
  int i, j;
  int min_id;
  while (1) {
    scanf("%d", &kyara_num);
    if (kyara_num == 0)
      break;
    memset(kyara, 0, sizeof(kyara));
    memset(all_disp_num, 0, sizeof(all_disp_num));
    for (i = 0; i < kyara_num; i++) {
      scanf("%s%d", kyara[i].name, &kyara[i].disp_num);
      for (j = 0; j < kyara[i].disp_num; j++) {
        scanf("%d", &kyara[i].disp_time[j]);
      }
    }
    for (i = 0; i < kyara_num; i++) {
      for (j = 0; j < kyara[i].disp_num; j++) {
        kyara[i].points += kyara_num;
        all_disp_num[kyara[i].disp_time[j]]++;
      }
    }
    for (i = 0; i < kyara_num; i++) {
      for (j = 0; j < kyara[i].disp_num; j++) {
        kyara[i].points -= all_disp_num[kyara[i].disp_time[j]] - 1;
      }
    }
    for (i = 1, min_id = 0; i < kyara_num; i++) {
      if (kyara[i].points < kyara[min_id].points) {
        min_id = i;
      } else if (kyara[i].points == kyara[min_id].points) {
        if (strcmp(kyara[i].name, kyara[min_id].name) > 0) {
          min_id = i;
        }
      }
    }
    printf("%d %s\n", kyara[min_id].points, kyara[min_id].name);
  }
  return 0;
}