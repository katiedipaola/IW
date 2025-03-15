#include <stdio.h>

#define ULL unsigned long long

int length(char S[101]) {
  int i = 0;
  while (1) {
    if (S[i] == '\0') {
      break;
    }
    i++;
  }

  return i;
}

int sn(char s) { return s - 48; }

int main() {
  char S[101];
  unsigned long long k;
  scanf("%s", S);
  scanf("%lld", &k);

  int len = length(S);

  int ans;
  for (int i = 0; i < len; i++) {
    if (sn(S[i]) == 1) {
      if (i + 1 == k) {
        ans = 1;
        break;
      }
    } else {
      ans = sn(S[i]);
      break;
    }
  }

  printf("%d\n", ans);

  return 0;
}
