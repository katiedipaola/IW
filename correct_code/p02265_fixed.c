#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int key;
  struct node *n;
  struct node *p;
} Node;

Node *nil;

Node *search(int key) {
  Node *res = nil->n;
  while (res != nil && res->key != key)
    res = res->n;
  return res;
}

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->n = nil;
  nil->p = nil;
}

void print() {
  Node *res = nil->n;
  int i;
  while (1) {
    if (res == nil)
      break;
    if (i++ > 0)
      printf(" ");
    printf("%d", res->key);
    res = res->n;
  }
  printf("\n");
}

void delete (Node *t) {
  if (t == nil)
    return;
  t->p->n = t->n;
  t->n->p = t->p;
  free(t);
}

void deleteFirst() { delete (nil->n); }

void deleteLast() { delete (nil->p); }

void deleteKey(int key) { delete (search(key)); }

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->n = nil->n;
  nil->n->p = x;
  nil->n = x;
  x->p = nil;
}

int main() {
  int i, n;
  int key;
  char com[20];

  scanf("%d", &n);

  init();
  for (i = 0; i < n; i++) {
    scanf("%s %d", com, &key);
    if (com[0] == 'i') {
      insert(key);
    } else {
      if (strlen(com) > 6) {
        if (com[6] == 'F')
          deleteFirst();
        else if (com[6] == 'L')
          deleteLast();
      } else {
        deleteKey(key);
      }
    }
  }

  print();

  return 0;
}