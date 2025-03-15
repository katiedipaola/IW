#include <stdio.h>
#include <string.h>

int main() {
  int loop;
  char w[101];
  int sum[26];
  int i = 0;
  int len;
  int loop1, loop2;

  scanf("%s", &w);
  len = strlen(w);
  for (loop = 0; loop < 26; loop++)
    sum[loop] = 0;

  for (loop1 = 0; loop1 < len; loop1++)
    for (loop2 = 0; loop2 < 26; loop2++) {
      if (w[loop1] == loop2 + 97)
        sum[loop2]++;
    }

  for (loop = 0; loop < 26; loop++)
    if (sum[loop] % 2 != 0)
      i++;

  if (i == 0)
    printf("Yes");
  else
    printf("No");
}