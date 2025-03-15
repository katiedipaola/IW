#include <stdio.h>
#define max_len 100010
#define Min(a, b) a < b ? a : b
void initArray(char a[], int len) {
  for (int i = 0; i < len; i++) {
    a[i] = 0;
  }
}

int retlen(char a[]) {
  int len = 0;
  while (a[len]) {
    len++;
  }
  return len;
}

count_char_0(char a[], int len) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] == '0') {
      count++;
    }
  }
  return count;
}

int main(void) {
  char tiles[max_len];
  initArray(tiles, max_len);
  fgets(tiles, max_len, stdin);
  int len = retlen(tiles);
  if (len == 0) {
    puts("0");
    return 0;
  }
  char odd_tiles[max_len], even_tiles[max_len];
  initArray(odd_tiles, max_len);
  initArray(even_tiles, max_len);
  int iter = 0, odd_iter = 0, even_iter = 0;
  while (iter < len) {
    odd_tiles[odd_iter++] = tiles[iter++];
    even_tiles[even_iter++] = tiles[iter++];
  }
  int odd_len = retlen(odd_tiles);
  int even_len = retlen(even_tiles);

  int num_of_0_odd = count_char_0(odd_tiles, odd_len);
  int num_of_0_even = count_char_0(even_tiles, even_len);

  int need_odd_0 = (odd_len - num_of_0_odd) + num_of_0_even;
  int need_odd_1 = num_of_0_odd + (even_len - num_of_0_even);
  printf("%d\n", Min(need_odd_1, need_odd_0));
  return 0;
}