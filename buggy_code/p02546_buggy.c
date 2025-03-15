#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {
  char buf[1000] = "  ";
  char *const word = buf + 2;
  scanf("%s", word);
  char *tail = word + strlen(word) - 1;
  if (strchr("sox", *tail) != NULL) {
    strcpy(tail + 1, "es");
  } else {
    strcpy(tail + 1, "s");
  }
  printf("%s\n", word);
}