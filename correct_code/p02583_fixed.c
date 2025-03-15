#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, count = 0;

  scanf("%d", &n);

  long long int num[n];

  for (int i = 0; i < n; i++)
    scanf("%lld", &num[i]);

  if (n < 3)
    printf("%d\n", count);
  else {
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
          if ((num[i] != num[j] && num[i] != num[k] && num[j] != num[k]) &&
              (num[i] + num[j] > num[k] && num[i] + num[k] > num[j] &&
               num[k] + num[j] > num[i]))
            count++;
    }

    printf("%d\n", count);
  }

  return 0;
}