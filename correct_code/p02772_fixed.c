#include <stdio.h>
int main() {
  int n, i, sum = 0, count = 0;
  scanf("%d", &n);
  int arr[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      sum++;

      if (arr[i] % 3 == 0 || arr[i] % 5 == 0) {
        count++;
      }
    }
  }
  if (sum == count) {
    printf("APPROVED");
  } else {
    printf("DENIED");
  }
  return 0;
}
