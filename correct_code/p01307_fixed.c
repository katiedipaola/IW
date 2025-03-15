/*
  AOJ 2189
  Title:Additon game
  @kankichi573
*/
#include <stdio.h>
#include <string.h>

char buf[1001];

main() {
  int i, j, len, sum, N, ret;

  scanf("%d ", &N);
  for (i = 0; i < N; i++) {
    scanf("%s", buf);
    len = strlen(buf);
    for (j = sum = 0; j < len; j++)
      sum += (buf[j] - '0');
    ret = (((sum - 1) / 9) & 1) ^ (len & 1);

    printf("%s wins.\n", ret ? "Audrey" : "Fabre");
  }
  return (0);
}