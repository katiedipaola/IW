#include <stdio.h>
char map[101][101];
int H, W;

void visit(int i, int j) {
  char temp;
  temp = map[i][j];
  if (temp == ".") {
    printf("%d %d\n", j, i);
    return;
  }
  if (temp == '@') {
    printf("LOOP\n");
    return;
  }
  map[i][j] = '@';
  if (temp == '>') {
    visit(i, j + 1);
  } else if (temp == '<') {
    visit(i, j - 1);
  } else if (temp == '^') {
    visit(i - 1, j);
  } else if (temp == 'v') {
    visit(i + 1, j);
  }
}

int main() {
  char x;
  int i, j;

  while (1) {
    scanf("%d %d", &H, &W);
    if (H == 0 && W == 0)
      break;
    for (i = 0; i < H; i++) {
      getchar();
      for (j = 0; j < W; j++) {
        scanf("%c", &x);
        map[i][j] = x;
      }
    }

    visit(0, 0);
  }
  return 0;
}