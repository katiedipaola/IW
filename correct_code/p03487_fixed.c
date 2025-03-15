#include <stdio.h>

/*
void print(long a[], long n)
{
        for (long i = 1; i <= n; i++){
                printf("[%d] ", a[i]);
        }
        puts("");
}
*/
void sort(long data[], long left, long right) {
  long sample = data[left], lptr = left, rptr = right;
  if (lptr < rptr) {
    while (lptr != rptr) {
      while ((sample < data[rptr]) && (lptr != rptr))
        rptr--;
      if (lptr != rptr)
        data[lptr++] = data[rptr];
      while ((data[lptr] < sample) && (lptr != rptr))
        lptr++;
      if (lptr != rptr)
        data[rptr--] = data[lptr];
    }
    data[lptr] = sample;
    sort(data, left, lptr - 1);
    sort(data, rptr + 1, right);
  }
}

long search(long x, long B[], long n) {

  long l, h, m;
  l = 1;
  h = n;
  while (l <= h) {
    // printf("search for %d from %d - %d \n",x, l, h);
    m = (l + h) / 2;
    // printf("m=%d:\n ", m);
    if (x == B[m]) {
      // printf("found>>%d\n", m);
      return m;
    }
    if (x > B[m])
      l = m + 1;
    else
      h = m - 1;
  }
  // printf("Cannot Find\n");
  return -1;
}

long count(long A[], long B[], long C[], long n) {
  sort(A, 1, n);
  // print(A, n);
  long i;
  long idx = 1;
  long id;
  for (i = 1; i <= n; i++) {
    if ((id = search(A[i], B, idx)) == -1) {
      B[idx++] = A[i];
      C[idx - 1] += 1; /*print(B, idx);*/
    } else {
      C[id] += 1;
    }
  }
  // printf("Finished!\n");
  return idx;
}

int main(void) {
  long N, i, cnt;
  scanf("%ld", &N);
  long a[100001], b[100001] = {0}, c[100001] = {0};
  for (i = 1; i <= N; i++) {
    scanf("%ld", &a[i]);
  }
  // printf("Start Count\n");
  long idx = count(a, b, c, N);
  /*printf("Counted\n");
  print(a, N);

  print(b, idx);

  print(c, idx);
  */
  cnt = 0;
  long x;
  for (i = 1; i < idx; i++) {
    if (c[i] > 0) {
      if (c[i] > b[i]) {
        x = c[i] - b[i];
      }
      if (c[i] < b[i]) {
        x = c[i];
      }
      if (c[i] == b[i]) {
        x = 0;
      }
      cnt += x;
    } else
      continue;
  }
  printf("%d\n", cnt);
  return 0;
}