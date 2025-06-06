#include <stdio.h>
#define LEN 100005

typedef struct pp {
  char name[100];
  int t;
} P;

P Q[LEN + 1];
int head, tail, n;

void enqueue(P x) {
  Q[tail] = x;
  if (tail + 1 == LEN)
    tail = 0;
  else
    tail++;
}

P dequeue() {
  P x;
  x = Q[head];
  if (head + 1 == LEN)
    head = 0;
  else
    head++;
  return x;
}

int main() {
  int elaps = 0, c = 0, a;
  int i, q;
  P u;
  int cont = 0;
  scanf("%d %d", &n, &q);
  head = 1;
  tail = n + 1;
  for (i = 1; i <= n; i++) {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
  }

  /*  a=Q[i].t-100; */
  /*   if(a<=0){ */
  /*     c++; */
  /*     elaps+=Q[i].t; */
  /*     printf("%s %d\n",Q[i].name,Q[i].t); */
  /*   } */
  /*   else enqueue(Q[i]); */
  /* } */
  while (head != tail) {
    u = dequeue();
    if (u.t > 100) {
      u.t = u.t - 100;
      elaps += 100;
      enqueue(u);
    } else {
      elaps += u.t;
      printf("%s %d\n", u.name, elaps);
    }
  }
  return 0;
}
