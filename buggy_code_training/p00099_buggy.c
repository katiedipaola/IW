#include <stdio.h>

int main(void) {
  int n, q, num, fish, i, j, vic = 0, max = 0, get[100];

  scanf("%d %d", &n, &q);

  for (i = 1; i <= n; i++) {
    get[i] = 0;
  }
  for (i = 0; i < q; i++) {
    scanf("%d %d", &num, &fish);
    get[num] += fish;
    if (fish < 0 && num == vic) {
      max = 0;
      for (j = n; j > 0; j--) {
        if (max <= get[j]) {
          max = get[j];
          vic = j;
        }
      }
    } else if (get[num] > max || (get[num] == max && vic > num)) {
      max = get[num];
      vic = num;
    }
    printf("%d %d\n", vic, get[vic]);
  }

  return 0;
}