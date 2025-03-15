#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  char c;

  scanf("%c", &c);

  switch (c) {
  case 'a':
  case 'i':
  case 'u':
  case 'e':
  case 'o':
    printf("vowel");
    break;
  default:
    printf("consonat");
    break;
  }
}