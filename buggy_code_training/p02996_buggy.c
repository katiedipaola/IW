#include <stdio.h>
#include <stdlib.h>

typedef struct JOB {
  long long a;
  long long b;
} tagjob;

int cmp(const tagjob *x, const tagjob *y) {
  return x->b > x->a ? 1 : x->b < x->a ? -1 : 0;
}

int main(void) {
  int n;
  int i;
  long long ttl = 0;
  scanf("%d", &n);

  tagjob job[n], tmp;

  for (i = 0; i < n; i++) {
    scanf("%ld%ld", &job[i].a, &job[i].b);
  }

  qsort(job, n, sizeof(tagjob), (int (*)(const void *, const void *))cmp);
  for (i = 0; i < n; i++) {
    ttl = ttl + job[i].a;
    if (ttl > job[i].b) {
      printf("No");
      return 0;
    }
  }
  printf("Yes");
  return 0;
}
