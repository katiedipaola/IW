#include <stdio.h>

int main(int argc, char const *argv[]) {
  int s, w;
  scanf("%d%d", &s, &w);
  printf("%s\n", (s > w) ? "safe" : "unsafe");
  return 0;
}
