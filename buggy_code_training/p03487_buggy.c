#include <stdio.h>

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
  // printf("search for %d from %d - %d \n",x, 1, n);
  long l, h, m;
  l = 1;
  h = n;
  while (l <= h) {
    m = (l + h) / 2;
    // printf("m=%d: ", m);
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
  long i;
  long idx = 1;
  long id;
  for (i = 1; i <= n; i++) {
    if ((id = search(A[i], B, i)) == -1) {
      B[idx++] = A[i];
      C[idx - 1] += 1;
    } else {
      C[id] += 1;
    }
  }
  // printf("Finished!\n");
  return idx;
}

/*
void print(long a[], long n)
{
for (long i = 1; i <= n; i++){
printf("[%d] ", a[i]);
}
}
*/
int main(void) {
  long N, i, cnt;
  scanf("%ld", &N);
  long a[100001], b[100001] = {0}, c[100001] = {0};
  for (i = 1; i <= N; i++) {
    scanf("%ld", &a[i]);
  }
  // printf("Start Count\n");
  long idx = count(a, b, c, N);
  // printf("Counted\n");
  // print(a, N);
  // puts("");
  // print(b, idx);
  // puts("");
  // print(c, idx);
  // puts("");
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