#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c, d, e, f;
  int i, j, k, l;
  k = 0;
  l = 0;
  int *water;
  int *suger;
  int solute, solution;
  solute = 0;
  solution = 0;
  double x;
  double limit;
  double dens;
  dens = 0.0;
  suger = (int *)malloc(sizeof(int) * 3001 * 3001);
  water = (int *)malloc(sizeof(int) * 31 * 31);

  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

  limit = (double)e * 100 / (e + 100);

  for (i = 0; i < 31; i++) {
    for (j = 0; j < 31; j++) {
      if (f >= a * 100 * i + b * 100 * j) {
        water[k] = a * 100 * i + b * 100 * j;
        k++;
      }
    }
  }

  for (i = 0; i < 3001; i++) {
    for (j = 0; j < 3001; j++) {
      if (f >= c * i + d * j) {
        suger[l] = c * i + d * j;
        l++;
      }
    }
  }

  for (i = 0; i < k; i++) {
    for (j = 0; j < l; j++) {
      if (water[i] == 0) {
        continue;
      }
      if (water[i] + suger[j] <= f &&
          limit >= (double)100 * suger[j] / (water[i] + suger[j])) {
        if (x = (double)100 * suger[j] / (water[i] + suger[j]), dens < x) {
          dens = x;
          solute = suger[j];
          solution = water[i] + suger[j];
        }
      }
    }
  }

  if (solute == 0 && solution == 0) {
    for (i = 0; i < k; k++) {
      if (solution < water[i]) {
        solution = water[i];
      }
    }
  }

  printf("%d %d\n", solution, solute);

  return 0;
}