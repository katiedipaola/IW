#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, i;

  struct restaurant {
    char s[11];
    int p;
    int num;
    struct restaurant *next;
  };
  struct restaurant r[1000];
  struct restaurant *start, *tmp, *pre;

  if (scanf("%d", &n) < 1) {
    exit(1);
  }

  for (i = 0; i < n; i++) {
    if (scanf("%s %d", r[i].s, &r[i].p) < 2) {
      exit(1);
    }
    r[i].num = i + 1;
  }

  start = &r[0];
  for (i = 1; i < n; i++) {
    pre = NULL;
    tmp = start;
    while (1) {
      if (strcmp(tmp->s, r[i].s) > 0) {
        r[i].next = tmp;
        if (pre != NULL) {
          pre->next = &r[i];
        }
        if (tmp == start) {
          start = &r[i];
        }
        break;

      } else if (strcmp(tmp->s, r[i].s) < 0) {
        if (tmp->next != NULL) {
          pre = tmp;
          tmp = tmp->next;
        } else {
          tmp->next = &r[i];
          break;
        }

      } else {
        if (tmp->p < r[i].p) {
          r[i].next = tmp;
          if (pre != NULL) {
            pre->next = &r[i];
          }
          if (tmp == start) {
            start = &r[i];
          }
          break;
        } else {
          if (tmp->next != NULL) {
            pre = tmp;
            tmp = tmp->next;
          } else {
            tmp->next = &r[i];
            break;
          }
        }
      }
    }
  }
  tmp = start;

  for (i = 0; i < n; i++) {
    printf("%d\n", tmp->num);
    tmp = tmp->next;
  }

  return 0;
}
