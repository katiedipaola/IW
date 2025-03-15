#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

char s[51];
char origin[10] = "AKIHABARA";
int origin_num = 0;

int main() {
  for (int i = 0; i < 51; i++) {
    s[i] = '0';
  }
  scanf("%s", s);
  for (int i = 0; i < 50 && origin_num <= 9; i++) {
    //同じの場合
    if (s[i] == origin[origin_num]) {
      origin_num++;
    }
    // Aをひとつ飛ばしたら同じの場合
    else if (origin[origin_num] == 'A' && origin_num <= 8 &&
             origin[origin_num + 1] == s[i]) {
      origin_num += 2;
    } else {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}