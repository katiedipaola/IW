#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323

// int calc1(float a,float b,float c,float d,float e,float f,float *x,float *y);
// void quick(int *,long long,long long);
// int comp(char *a,char *b);

int main() {

  char a;
  while (scanf("%c", &a) != EOF)
    if (a <= 'a' && a >= 'z')
      printf("%c", a - 'a' + 'A');
    else
      printf("%c", a);
  return 0;
}