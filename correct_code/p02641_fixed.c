/*
 * main.c
 *
 *  Created on: 2020/03/28
 *      Author: family
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
typedef long long int ll;
typedef unsigned long long int ull;

int sort_inc(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int sort_dec(const void *a, const void *b) { return (*(int *)b - *(int *)a); }
int sort_dec_ll(const void *a, const void *b) {
  ll da = *(ll *)a, db = *(ll *)b;
  int val = 0;
  if (da > db) {
    val = -1;
  } else if (da == db) {
    val = 0;
  } else {
    val = 1;
  }
  return val;
}
int sort_inc_ll(const void *a, const void *b) {
  ll da = *(ll *)a, db = *(ll *)b;
  int val = 0;
  if (da > db) {
    val = 1;
  } else if (da == db) {
    val = 0;
  } else {
    val = -1;
  }
  return val;
}
int sort_dic(const void *a, const void *b) {
  char *pa = (char *)a;
  char *pb = (char *)b;
  int i = 0, val = 0, N = 10;
  for (i = 0; i < N; i++) {
    char da = pa[i], db = pb[i];
    if (da == db)
      continue;
    if (da > db)
      val = 1;
    else
      val = -1;
    break;
  }
  return val;
}

void yesno(int ans) {
  if (ans == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return;
}

void okng(int ans) {
  if (ans == 1) {
    printf("OK\n");
  } else {
    printf("NG\n");
  }
  return;
}

int p[111] = {0};
int main() {
  int X = 0, N = 0;
  scanf("%d %d", &X, &N);
  int i = 0;
  for (i = 0; i < N; i++) {
    int a = 0;
    scanf("%d", &a);
    p[a] = 1;
  }
  if (N == 0) {
    printf("%d\n", X);
    return 0;
  }
  int p1 = 0;
  for (i = X; i >= 0; i--) {
    if (p[i] == 0) {
      p1 = i;
      break;
    }
  }

  int p2 = 0;
  for (i = X; i <= 110; i++) {
    if (p[i] == 0) {
      p2 = i;
      break;
    }
  }
  int ans = 0;
  if (abs(X - p1) > abs(X - p2)) {
    ans = p2;
  } else if (abs(X - p1) < abs(X - p2)) {
    ans = p1;
  } else {
    ans = MIN(p1, p2);
  }
  printf("%d\n", ans);
  // yesno(ans);
  // okng(ans);
  return 0;
}
