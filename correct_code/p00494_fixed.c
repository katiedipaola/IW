#include <stdio.h>

int main(void) {
  int n1, n2, n3, max = 0;

  while (~scanf("%*[^J]")) {
    n1 = n2 = n3 = 0;
    scanf("%*[J]%n%*[O]%n%*[I]%n", &n1, &n2, &n3);
    n3 -= n2;
    n2 -= n1;

    if (n1 >= n2 && n2 <= n3)
      if (max < n2)
        max = n2;
  }

  printf("%d\n", max);

  return 0;
}