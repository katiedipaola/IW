
#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  int array[N];
  int count = 0;

  int stop = 0;

  for (int i = 0; i <= N - 1; i++) {
    scanf("%d", &array[i]);
  }

  while (stop == 0) {
    int start = -1;
    int end = -1;
    int min = 101;

    for (int i = 0; i <= N - 1; i++) {
      if (array[i] != 0 && start == -1) {
        start = i;
        min = array[i];
        continue;
      }
      if (start != -1) {
        if (array[i] != 0) {
          if (min >= array[i]) {
            min = array[i];
          }
        } else {
          end = i - 1;
          break;
        }
      }
    }
    if (start == -1) {
      break;
    }
    if (end == -1) {
      end = N - 1;
    }
    for (int i = start; i <= end; i++) {
      array[i] = array[i] - min;
    }
    count = count + min;
  }
  printf("%d", count);

  return 0;
}
