#define MAX 10000
#define NIL -1

typedef struct {
  int p, l, r;
} Node;

Node T[MAX];
int n;

void preParse(int u) {
  if (u == NIL)
    return;
  printf(" %d", u);
  preParse(T[u].l);
  preParse(T[u].r);
}

void inParse(int u) {
  if (u == NIL)
    return;
  inParse(T[u].l);
  printf(" %d", u);
  inParse(T[u].r);
}

void posParse(int u) {
  if (u == NIL)
    return;
  posParse(T[u].l);
  posParse(T[u].r);
  printf(" %d", u);
}

int main() {
  int i, v, l, r, root;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    T[i].p = NIL;

  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &v, &l, &r);
    T[v].l = l;
    T[v].r = r;
    if (l != NIL)
      T[l].p = v;
    if (r != NIL)
      T[r].p = v;
  }

  for (i = 0; i < n; i++) {
    if (T[i].p == NIL) {
      root = i;
    }
  }

  printf("Preorder\n");
  preParse(root);
  printf("\n");
  printf("Inorder\n");
  inParse(root);
  printf("\n");
  printf("Posorder\n");
  posParse(root);
  printf("\n");

  return 0;
}
