#include <stdio.h>
#include <string.h>

typedef struct {
  int top, front, right, left, back, bottom;
} dice;

void diceroll(dice *d, char c);

int main(void) {
  dice d[100];
  int i, j, n;
  int c = 0;
  scanf("%d", &n);

  for (i = 0; i < n; i++)
    scanf("%d %d %d %d %d %d", &d[i].top, &d[i].front, &d[i].right, &d[i].left,
          &d[i].back, &d[i].bottom);

  for (i = 1; i < n; i++) {
    if (d[i].top == d[0].front)
      diceroll(&d[i], 'S');
    else if (d[i].bottom == d[0].front)
      diceroll(&d[i], 'N');
    else if (d[i].right == d[0].front)
      diceroll(&d[i], 'W'), diceroll(&d[i], 'S');
    else if (d[i].left == d[0].front)
      diceroll(&d[i], 'E'), diceroll(&d[i], 'S');
    else if (d[i].back == d[0].front)
      diceroll(&d[i], 'S'), diceroll(&d[i], 'S');
  }

  for (i = 0; i < 4; i++) {
    for (j = 1; j < n; j++) {
      if (d[0].top == d[j].top && d[0].bottom == d[j].bottom &&
          d[0].right == d[j].right && d[0].left == d[j].left &&
          d[0].back == d[j].back) {
        printf("No\n");
        return 0;
      }
      diceroll(&d[j], 'E');
    }
  }

  printf("Yes\n");

  return 0;
}

void diceroll(dice *d, char c) {
  int temp;

  switch (c) {
  case 'E':
    temp = d->top;
    d->top = d->left;
    d->left = d->bottom;
    d->bottom = d->right;
    d->right = temp;
    break;
  case 'N':
    temp = d->top;
    d->top = d->front;
    d->front = d->bottom;
    d->bottom = d->back;
    d->back = temp;
    break;
  case 'S':
    temp = d->top;
    d->top = d->back;
    d->back = d->bottom;
    d->bottom = d->front;
    d->front = temp;
    break;
  case 'W':
    temp = d->top;
    d->top = d->right;
    d->right = d->bottom;
    d->bottom = d->left;
    d->left = temp;
    break;
  case 'R':
    temp = d->front;
    d->front = d->left;
    d->left = d->back;
    d->back = d->right;
    d->right = temp;
    break;
  case 'L':
    temp = d->front;
    d->front = d->right;
    d->right = d->back;
    d->back = d->left;
    d->left = temp;
    break;
  case 's':
    temp = d->right;
    d->right = d->left;
    d->left = temp;
    break;
  case 'b':
    temp = d->front;
    d->front = d->back;
    d->front = temp;
    break;
  case 'B':
    temp = d->top;
    d->top = d->bottom;
    d->bottom = temp;
    break;
  default:
    break;
  }
}