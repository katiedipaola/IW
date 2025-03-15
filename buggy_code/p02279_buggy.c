#include <stdio.h>
#define NIL -1
typedef struct {
  int p;
  int l;
  int r;
  int id;
} Tree;

Tree tree[1000000];
int depth(int u) {
  int depth = 0;
  while (tree[u].p != NIL) {
    ++depth;
    u = tree[u].p;
  }
  return depth;
}
void print_child(int i) {
  if (tree[i].l == NIL) {
    printf("[]");
    return;
  }
  printf("[");
  int child = tree[i].l;
  while (1) {
    printf("%d", tree[child].id);
    child = tree[child].r;
    if (child == NIL)
      break;
    else
      printf(", ");
  }
  printf("]");
}
void print_node(int i) {
  if (tree[i].p == -1) {
    printf("root, ");
    print_child(i);
  } else if (tree[i].l != -1) {
    printf("internal node, ");
    print_child(i);
  } else
    printf("leaf, []");
}
void print(int n) {
  for (int i = 0; i < n; ++i) {
    printf("node: %d: parent = %d, ", tree[i].id, tree[i].p);
    printf("depth = %d, ", depth(i));
    print_node(i);
    printf("\n");
  }
}
int main() {
  int n, id, k, c[100000];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    tree[i].p = NIL;
    tree[i].l = NIL;
    tree[i].r = NIL;
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &id, &k);
    tree[id].id = id;
    for (int j = 0; j < k; ++j) {
      scanf("%d", &c[j]);
      tree[c[j]].p = id;
      if (j == 0)
        tree[id].l = c[j];
      else
        tree[c[j - 1]].r = c[j];
    }
  }
  print(n);
  return 0;
}
