#include <stdio.h>
#include <string.h>

int main(void) {
  char road[150];
  int str;
  int i;
  char aka;

  while (scanf("%s", road)) {
    if (road[0] == '#') {
      break;
    }
    str = strlen(road);

    aka = 'A';
    for (i = 0; i < str; i++) {
      switch (aka) {
      case 'A':
        if (road[i] == '0') {
          aka = 'X';
        } else {
          aka = 'Y';
        }
        break;

      case 'X':
        if (road[i] == '0') {
          aka = 0;
        } else {
          aka = 'Z';
        }
        break;

      case 'Y':
        if (road[i] == '0') {
          aka = 'X';
        } else {
          aka = 0;
        }
        break;

      case 'Z':
        if (road[i] == '0') {
          aka = 'W';
        } else {
          aka = 'B';
        }
        break;

      case 'W':
        if (road[i] == '0') {
          aka = 'B';
        } else {
          aka = 'Y';
        }
        break;

      case 'B':
        if (road[i] == '0') {
          aka = 'Y';
        } else {
          aka = 'X';
        }
        break;

      default:
        i = str;
        break;
      }
    }

    if (aka == 'B') {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return (0);
}