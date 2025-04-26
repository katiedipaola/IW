#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mymalloc(p, n)                                                         \
  {                                                                            \
    p = malloc((n) * sizeof(*p));                                              \
    if ((p) == NULL) {                                                         \
      printf("not enough memory?\n");                                          \
      exit(1);                                                                 \
    };                                                                         \
  }

typedef struct node {
  struct node *parent;
  struct node *right;
  struct node *left;
  long key;
} node;

typedef struct {
  struct node *root;
} tree;

node *createNode(long n) {
  node *node;
  mymalloc(node, 1);
  node->parent = NULL;
  node->right = NULL;
  node->left = NULL;
  node->key = n;
  return node;
}

void insert(tree *T, node *z) {
  node *x, *y;
  y = NULL;
  x = T->root;
  while (x != NULL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NULL) {
    T->root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

node *find(tree *T, long key) {
  node *x;
  x = T->root;
  while (x != NULL) {
    if (key == x->key) {
      return x;
    }
    if (key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  return NULL;
}

node *findNext(node *x) {
  node *y;
  y = x->right;
  while (y->left != NULL) {
    y = y->left;
  }
  return y;
}

void delete (node *x) {
  int dim;
  node *y;
  y = NULL;
  dim = 0;
  if (x->left != NULL) {
    y = x->left;
    dim++;
  } else if (x->right != NULL) {
    y = x->right;
    dim++;
  }
  if (dim == 2) {
    y = findNext(x);
    x->key = y->key;
    delete (y);
  } else {
    if (x->parent != NULL) {
      if (x == x->parent->left) {
        x->parent->left = y;
      } else {
        x->parent->right = y;
      }
    }
    if (dim == 1) {
      y->parent = x->parent;
    }
    free(x);
  }
}

void preorder(node *root) {
  printf(" %ld", root->key);
  if (root->left != NULL) {
    preorder(root->left);
  }
  if (root->right != NULL) {
    preorder(root->right);
  }
}

void inorder(node *root) {
  if (root->left != NULL) {
    inorder(root->left);
  }
  printf(" %ld", root->key);
  if (root->right != NULL) {
    inorder(root->right);
  }
}

void freeNode(node *root) {
  if (root->left != NULL) {
    freeNode(root->left);
  }
  if (root->right != NULL) {
    freeNode(root->right);
  }
  free(root);
}

void printTree(node *root) {
  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
}

main() {
  long i, n, m;
  tree *T;
  node *obj;
  char s[10];
  mymalloc(T, 1);
  T->root = NULL;
  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf(" %s", s);
    if (strcmp(s, "print") == 0) {
      printTree(T->root);
    } else {
      scanf(" %ld", &m);
      if (strcmp(s, "insert") == 0) {
        obj = createNode(m);
        insert(T, obj);
      } else {
        if (strcmp(s, "find") == 0) {
          if (find(T, m) != NULL) {
            puts("yes");
          } else {
            puts("no");
          }
        } else {
          if (strcmp(s, "delete") == 0) {
            delete (find(T, m));
          }
        }
      }
    }
  }
  freeNode(T->root);
  free(T);
  return 0;
}