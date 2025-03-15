
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {

  char s[1000] = {};
  int w = 0;
  int len = 0;

  scanf("%s %d", s, &w);

  len = strlen(s);

  int count = len / w;
  int countA = len % w;
  if (countA != 0) {
    count++;
  }

  char result[1000] = {};
  int resultCount = 0;
  int plusW = 0;
  for (int i = 0; i < count; i++) {
    if (i != 0) {
      plusW = w * i;
    } else {
      plusW = i;
    }
    result[resultCount] = s[plusW];
    resultCount++;
  }

  printf("%s", result);

  return 0;
}