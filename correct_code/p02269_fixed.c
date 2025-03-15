#include <stdio.h>
#include <string.h>

#define M 1000033 /* your task*/
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch) {
  if (ch == 'A')
    return 1;
  else if (ch == 'C')
    return 2;
  else if (ch == 'G')
    return 3;
  else if (ch == 'T')
    return 4;
}

/* convert a string into an integer value */
long long getKey(char str[]) {
  long long sum = 0, p = 1, i;
  for (i = 0; i < strlen(str); i++) {
    sum += p * (getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h(int key, int i) { return (h1(key) + i * h2(key)) % M /* your task */; }
int h1(int key) { return key % M /* your task */; }
int h2(int key) { return 1 + key % (M - 1) /* your task */; }

int find(char str[]) {
  int i = 0, k = getKey(str), m = h(k, i);

  while (H[m][0] != '\0') {

    if (strcmp(str, H[m]) == 0) {

      return 1;
    }
    i++;
    m = h(k, i);
  }
  return 0;
  /* your task */
}

int insert(char str[]) {

  int i = 0, k = getKey(str), m;
  while (1) {
    m = h(k, i);
    if (H[m][0] == '\0') {
      strcpy(H[m], str);
      return 7;
    }
    i++;
  }

  /* your task */
}

int main() {
  int i, n, h;
  char str[L], com[9];
  for (i = 0; i < M; i++)
    H[i][0] = '\0';

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s %s", com, str);

    if (com[0] == 'i') {
      insert(str);
    } else {
      if (find(str)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }

  return 0;
}