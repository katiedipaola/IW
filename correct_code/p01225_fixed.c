#include <stdio.h>

int main(void) {

  char mark[9];
  int num[9], r_num[9], b_num[9], g_num[9], set, i, j;

  scanf("%d", &set); /* ???????????°?????\??? */
  int ans[set];

  for (i = 0; i < 9; i++) { /* ????????????????????? */
    r_num[i] = 0;
    g_num[i] = 0;
    b_num[i] = 0;
  }

  for (i = 0; i < set; i++) {
    ans[i] = 0;
  }

  for (i = 0; i < set; i++) { /* ???????????°?????°????????? */
    for (j = 0; j < 9; j++) {
      scanf("%d", &num[j]);
    }
    for (j = 0; j < 9; j++) {
      if (j == 9) {
        scanf("%c", &mark[j]);
      } else {
        scanf(" %c", &mark[j]);
      }
    }

    for (j = 0; j < 9; j++) { /* ????????¨?????????????????? */
      if (mark[j] == 'R') {
        r_num[j] = num[j];
      } else if (mark[j] == 'G') {
        g_num[j] = num[j];
      } else if (mark[j] == 'B') {
        b_num[j] = num[j];
      }
    }

    sort(r_num); /* ??????????????? */
    sort(g_num); /* ??????????????? */
    sort(b_num); /* ??????????????? */

    if (judge(r_num) == 1 && judge(g_num) == 1 &&
        judge(b_num) == 1) { /* ???????????? */
      ans[i] = 1;
    } else {

      ans[i] = 0;
    }

    for (j = 0; j < 9; j++) { /* ????????????????????? */
      r_num[j] = 0;
      g_num[j] = 0;
      b_num[j] = 0;
    }
  }

  for (i = 0; i < set; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}

void sort(int num[]) {

  int p, q, tmp;

  for (p = 0; p < 8; p++) {
    for (q = p + 1; q < 9; q++) {
      if (num[p] > num[q]) {
        tmp = num[p];
        num[p] = num[q];
        num[q] = tmp;
      }
    }
  }
}

int judge(int num[]) {

  int cnt = 0;
  int i, j, k;

  for (i = 0; i < 9; i++) {
    if (num[i] == 0) {
      cnt++; /* ???????????????0?????°??????????????? */
    }
  }
  if (cnt % 3 != 0) { /* 0?????°???3????????°??§???????????°0????????? */
    return 0;
  }

  for (i = cnt; i < 9; i++) { /* ???????????¶?????????????????????????????? */
    if (num[i] != 0) {
      for (j = cnt; j < 9; j++) {
        if (num[j] != 0 && j != i) {
          if (num[i] == num[j]) {
            for (k = cnt; k < 9; k++) {
              if (num[k] != 0 && (k != i && k != j)) {
                if (num[i] == num[k]) {
                  num[i] = 0;
                  num[j] = 0;
                  num[k] = 0;
                }
              }
            }
          }

          else if (num[j] - num[i] == 1) {
            for (k = cnt; k < 9; k++) {
              if (num[k] != 0 && (k != i && k != j)) {
                if (num[k] - num[j] == 1) {
                  num[i] = 0;
                  num[j] = 0;
                  num[k] = 0;
                }
              }
            }
          }
        }
      }
    }
  }
  cnt = 0;
  for (i = 0; i < 9; i++) {
    if (num[i] == 0) {
      cnt++;
    }
  }
  if (cnt == 9) {
    return 1;
  } else {
    return 0;
  }
}