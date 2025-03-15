#include <stdio.h>

main() {
  int s1, s2, i, a, max = 0;

  while (1) {

    for (i = 0; i < 5; i++) {
      scanf("%d %d", &s1, &s2);
      if (s1 == 0 && s2 == 0)
        break;
      if (max < s1 + s2) {
        max = s1 + s2;
        a = i;
      }
    }
    if (s1 == 0 && s2 == 0)
      break;

    switch (a) {
    case 0:
      printf("A ");
      break;
    case 1:
      printf("B ");
      break;
    case 2:
      printf("C ");
      break;
    case 3:
      printf("D ");
      break;
    case 4:
      printf("E ");
      break;
    }

    printf("%d\n", max);
  }
  return 0;
}