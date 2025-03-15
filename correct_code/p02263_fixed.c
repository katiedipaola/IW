#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define Max 100

void push(int, int *);
int pop(int *);

int sp = 0;

int main() {

  int op2;
  int K[Max];
  char A[8];

  while (scanf("%s", A) == 1) {
    if (A[0] == '+') {
      push(pop(K) + pop(K), K);
    } else if (A[0] == '*') {
      push(pop(K) * pop(K), K);
    } else if (A[0] == '-') {
      op2 = pop(K);
      push(pop(K) - op2, K);
    } else {
      push(atoi(A), K);
    }
  }

  printf("%d\n", K[0]);

  return 0;
}

void push(int f, int K[]) { K[sp++] = f; }

int pop(int K[]) { return K[--sp]; }
