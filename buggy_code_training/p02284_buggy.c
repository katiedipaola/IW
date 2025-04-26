#include <stdio.h>
#include <stdlib.h>

#define NIL NULL

typedef struct node {
  int key;
  struct node *right;
  struct node *left;
  struct node *parent;
} * Node;

Node root;

void insert(int k) {

  Node y = NIL;
  Node x = root;
  Node z;

  z = malloc(sizeof(struct node));

  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;

  if (y == NIL) {
    root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}
Node treeMinimum(Node x) {
  while (x->left != NIL)
    x = x->left;
}

void inorder(Node x) {
  if (x != NIL) {
    inorder(x->left);
    printf(" %d", x->key);
    inorder(x->right);
  }
}
void preorder(Node x) {

  if (x != NIL) {
    printf(" %d", x->key);
    preorder(x->left);
    preorder(x->right);
  }
}

Node treeSearch(Node u, int k) {
  while (u != NIL && k != u->key) {
    if (k < u->key) {
      u = u->left;
    } else
      u = u->right;
  }
  return u;
}

int main() {

  int n, i, x;
  char com[20];
  root = NIL;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s", com);

    if (com[0] == 'f') {
      scanf("%d", &x);
      Node t = treeSearch(root, x);
      if (t != NIL)
        printf("\nyes\n");
      else
        printf("no\n");
    } else if (com[0] == 'i') {
      scanf("%d", &x);
      insert(x);
    } else if (com[0] == 'p') {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }
  return 0;
}