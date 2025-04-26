#include <stdio.h>
int main() {
  int string = 0, i;
  int cnt[26] = {0};

  while ((string = getchar()) != EOF) {
    if ('A' <= string && string <= 'Z') { // oomoji
      cnt[string - 'A']++;                //-'A'
    } else if ('a' <= string && string <= 'z') {
      cnt[string - 'a' - 'A']++;
    }
  }
  for (i = 0; i <= 25; i++) {
    printf("%c : %d\n", 'a' + 1, cnt[i]);
  }
  return 0;
}