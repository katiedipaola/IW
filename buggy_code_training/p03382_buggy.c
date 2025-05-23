#include <math.h>
#include <stdio.h>

/* クイックソートを行う */
void QSort(long x[], long left, long right) {
  int i, j;
  int pivot;

  i = left;  /* ソートする配列の一番小さい要素の添字 */
  j = right; /* ソートする配列の一番大きい要素の添字 */

  pivot = x[(left + right) / 2]; /* 基準値を配列の中央付近にとる */

  while (1) { /* 無限ループ */

    while (x[i] < pivot) /* pivot より大きい値が */
      i++;               /* 出るまで i を増加させる */

    while (pivot < x[j]) /* pivot より小さい値が */
      j--;               /*  出るまで j を減少させる */
    if (i >= j)          /* i >= j なら */
      break;             /* 無限ループから抜ける */

    Swap(x, i, j); /* x[i] と x[j]を交換 */
    i++;           /* 次のデータ */
    j--;
  }
  if (left < i - 1)         /* 基準値の左に 2 以上要素があれば */
    QSort(x, left, i - 1);  /* 左の配列を Q ソートする */
  if (j + 1 < right)        /* 基準値の右に 2 以上要素があれば */
    QSort(x, j + 1, right); /* 右の配列を Q ソートする */
}

/* 配列の要素を交換する */
void Swap(long x[], int i, int j) {
  long temp;

  temp = x[i];
  x[i] = x[j];
  x[j] = temp;
}

int search(long a[], long target, int left, int right) {
  int m;
  if (left > right)
    return 0;
  m = (left + right) / 2;
  if (target == a[m])
    return 1;
  else if (left == right)
    return 0;
  else if (target < a[m]) {
    return search(a, target, left, m - 1);
  } else {
    return search(a, target, m + 1, right);
  }
}

int main() {
  int n, i, j;
  long a[200000], x[200000], max = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  QSort(a, 0, n - 1);
  max = a[n - 1];
  for (i = 0; i < n; i++) {
    if (labs(a[i] - (a[n - 1] / 2)) <= max) {
      j = a[i];
      max = labs(a[i] - (a[n - 1] / 2));
    }
  }
  printf("%ld %ld\n", a[n - 1], j);
}