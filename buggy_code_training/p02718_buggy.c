#include <stdio.h>
void A(void);
void B(void);
void C(void);

int main(void) {
  B();
  return 0;
}

void A(void) {
  int a, b, c, k;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d %d %d", c, a, b);
}

void B(void) {
  int n, m, i, k = 0, sum = 0;
  int array[1000];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
    sum += array[i];
  }
  for (i = 0; i < n; i++) {
    if (array[i] >= sum / (4 * m))
      k++;
  }
  if (k >= m) {
    printf("Yes");
  } else {
    printf("No");
  }
}