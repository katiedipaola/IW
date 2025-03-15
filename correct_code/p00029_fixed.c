#include <stdio.h>
#include <string.h>

int main() {

  int i, j, k, count[200] = {0}, max, midx, lidx;
  char s[1000], tmp[200][32];

  fgets(s, 1000, stdin);
  i = 0;
  j = 0;
  k = 0;
  max = 0;
  while (s[i] != '\0') {
    if (s[i] == ' ') {
      tmp[j][k] = '\0';
      j++;
      i++;
      k = 0;
      continue;
    }

    tmp[j][k++] = s[i++];
  }
  tmp[j++][k - 1] = '\0';

  for (i = 0; i < j; i++) {
    for (k = i + 1; k < j; k++) {
      if (!strcmp(tmp[i], tmp[k]))
        count[i]++;
    }
  }
  for (i = 0; i < j; i++) {
    if (count[i] > max) {
      max = count[i];
      midx = i;
    }
  }
  max = 0;
  for (i = 0; i < j; i++) {
    if (strlen(tmp[i]) > max) {
      max = strlen(tmp[i]);
      lidx = i;
    }
  }
  printf("%s %s\n", tmp[midx], tmp[lidx]);

  return 0;
}