#include <stdio.h>

int main() {
  int n, temp, i;
  int l[100];
  int max = 0;
  int sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &temp);
    if (temp > max) {
      max = temp;
      l[i] = temp;
    } else {
      l[i] = temp;
    }
  }
  for (i = 0; i < n; i++) {
    sum = sum + l[i];
  }
  sum = sum - max;
  if (max < sum) {
    printf("Yes");
  } else {
    printf("No");
  }
}