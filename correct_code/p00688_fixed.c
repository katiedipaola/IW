#include <stdio.h>

/* 最大公約数を返す */
int gcd(int a, int b) {
  int r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return (a < 0) ? -a : a;
}

/* 値を入れ換える */
void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}

int main(void) {
  int a, b, c; /* 与えられる値 */
  int p, q, r, s;
  int f; /* 解が存在するか */

  /* データセット毎の処理 */
  while (scanf("%d%d%d", &a, &b, &c) == 3 && a > 0) {
    int d = b * b - 4 * a * c; /* 二次方程式の判別式D */
    f = 0;

    if (d == 0) {
      int g;
      /* 重解 -b / 2a */
      f = 1;
      p = 2 * a;
      q = b; /* 符号に注意 */
      /* 約分 */
      g = gcd(p, q);
      p /= g;
      q /= g;

      r = p;
      s = q;
    } else if (d > 0) {
      /* 異なる二つの実数解 (-b +- √d) / 2a */
      int i;
      for (i = 1; i * i < d; i++)
        ; /* D の正整数平方根を求める */

      /* Dの平方根が整数であるなら整数 p, q, r, s が存在する */
      if (i * i == d) {
        int g;
        f = 1;

        p = 2 * a;
        r = 2 * a;
        q = -(-b - i);
        s = -(-b + i);

        /* 約分 */
        g = gcd(p, q);
        p /= g;
        q /= g;
        g = gcd(r, s);
        r /= g;
        s /= g;

        /* 問題の条件に合わせて解の順番を入れ換える */
        if (!(p > r || (p == r && q >= s))) {
          swap(&p, &r);
          swap(&q, &s);
        }
      }
    }

    /* 結果を出力する */
    if (f)
      printf("%d %d %d %d\n", p, q, r, s);
    else
      printf("Impossible\n");
  }

  return 0;
}