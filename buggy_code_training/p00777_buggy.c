#include <stdio.h>
#include <stdlib.h>
#define tree_valtype int

typedef struct tree_edge_sub tree_edge;

typedef struct {
  int num;
  int nearnum;
  tree_edge *near;
} tree_vertex_sub;

struct tree_edge_sub {
  tree_vertex_sub *v;
  int w;
  tree_edge *next;
};

typedef struct tree_v_sub tree_vertex;

struct tree_v_sub {
  int num;
  tree_valtype val;
  tree_vertex *parent;
  int pareweight;
  int chilnum;
  tree_vertex **children;
  int *chilweight;
};

typedef struct {
  int N;
  int root;
  tree_vertex_sub **v_s;
  tree_vertex **v;
  tree_vertex **sorted_v;
} tree;

//頂点数N, 根の番号root, 各頂点の初期値ini_valの木を作る
tree *make_tree(int N, int root, tree_valtype ini_val) {
  int i;
  tree *t = (tree *)malloc(sizeof(tree));
  t->N = N;
  t->root = root;
  t->v_s = (tree_vertex_sub **)malloc(sizeof(tree_vertex_sub *) * N);
  t->v = (tree_vertex **)malloc(sizeof(tree_vertex *) * N);
  t->sorted_v = (tree_vertex **)malloc(sizeof(tree_vertex *) * N);
  tree_vertex *parent_in_law = (tree_vertex *)malloc(sizeof(tree_vertex));
  parent_in_law->num = -1;
  parent_in_law->val = ini_val;
  parent_in_law->parent = NULL;
  parent_in_law->pareweight = -1;
  parent_in_law->chilnum = 0;
  parent_in_law->children = NULL;
  parent_in_law->chilweight = NULL;
  for (i = 0; i < N; i++) {
    (t->v_s)[i] = (tree_vertex_sub *)malloc(sizeof(tree_vertex_sub));
    (t->v_s)[i]->num = i;
    (t->v_s)[i]->nearnum = 0;
    (t->v_s)[i]->near = NULL;
    (t->v)[i] = (tree_vertex *)malloc(sizeof(tree_vertex));
    (t->v)[i]->num = i;
    (t->v)[i]->val = ini_val;
    (t->v)[i]->parent = parent_in_law;
    (t->v)[i]->pareweight = -1;
    (t->v)[i]->chilnum = 0;
    (t->v)[i]->children = NULL;
    (t->v)[i]->chilweight = NULL;
    (t->sorted_v)[i] = NULL;
  }
  return t;
}

//木tの頂点aと頂点bの間に重みwの無向辺を張る (0 <= a, b <= N - 1)
void set_edge_tree(int a, int b, int w, tree *t) {
  tree_edge *new1 = (tree_edge *)malloc(sizeof(tree_edge));
  new1->v = (t->v_s)[b];
  new1->w = w;
  new1->next = (t->v_s)[a]->near;
  (t->v_s)[a]->near = new1;
  (t->v_s)[a]->nearnum++;

  tree_edge *new2 = (tree_edge *)malloc(sizeof(tree_edge));
  new2->v = (t->v_s)[a];
  new2->w = w;
  new2->next = (t->v_s)[b]->near;
  (t->v_s)[b]->near = new2;
  (t->v_s)[b]->nearnum++;
}

// set_edge_tree後に呼び出す
void build_tree(tree *t) {
  int i, j;
  tree_vertex_sub **v_s = t->v_s;
  tree_vertex **v = t->v;
  tree_vertex **sorted_v = t->sorted_v;
  sorted_v[0] = v[t->root];
  tree_vertex *nowv;
  tree_edge *nowe;
  for (i = 0, j = 1; j - i > 0; i++) {
    nowv = sorted_v[i];
    if (i == 0) {
      v_s[nowv->num]->nearnum++;
    }
    nowv->children = (tree_vertex **)malloc(sizeof(tree_vertex *) *
                                            (v_s[nowv->num]->nearnum - 1));
    nowv->chilweight =
        (int *)malloc(sizeof(int) * (v_s[nowv->num]->nearnum - 1));
    if (i == 0) {
      v_s[nowv->num]->nearnum--;
    }
    for (nowe = v_s[nowv->num]->near; nowe != NULL; nowe = nowe->next) {
      if (nowe->v->num != nowv->parent->num) {
        (nowv->children)[nowv->chilnum] = v[nowe->v->num];
        (nowv->chilweight)[nowv->chilnum] = nowe->w;
        nowv->chilnum++;
        v[nowe->v->num]->parent = nowv;
        v[nowe->v->num]->pareweight = nowe->w;
        sorted_v[j] = v[nowe->v->num];
        j++;
      }
    }
  }
  sorted_v[0]->parent = NULL;
}

int main() {
  int N, i;
  while (1) {
    scanf("%d", &N);
    if (N == 0) {
      return 0;
    }
    tree *t = make_tree(N, 0, 0);
    int *p = (int *)malloc(sizeof(int) * N);
    int *d = (int *)malloc(sizeof(int) * N);
    for (i = 1; i < N; i++) {
      scanf("%d", &p[i]);
    }
    int dsum = 0;
    for (i = 1; i < N; i++) {
      scanf("%d", &d[i]);
      dsum += d[i];
    }
    for (i = 1; i < N; i++) {
      set_edge_tree(i, p[i] - 1, d[i], t);
    }
    for (i = 0; t->v_s[i]->nearnum == 1; i++) {
    }
    t->root = i;
    //	printf("t->root = %d\n", t->root);
    build_tree(t);
    tree_vertex *nowv;
    int l = t->v[0]->num;
    int dinsum = 0;
    for (i = 1; i < N; i++) {
      //		printf("i = %d\n", i);
      nowv = t->sorted_v[i];
      nowv->val = nowv->parent->val + nowv->pareweight;
      if (nowv->chilnum != 0) {
        dinsum += nowv->pareweight;
        if (t->v[l]->val < nowv->val) {
          l = nowv->num;
        }
      }
    }
    tree *t2 = make_tree(N, l, 0);
    t2->v_s = t->v_s;
    build_tree(t2);
    l = t2->v[0]->num;
    //	printf("t2->root = %d\n", t2->root);
    for (i = 1; i < N; i++) {
      nowv = t2->sorted_v[i];
      nowv->val = nowv->parent->val + nowv->pareweight;
      if (nowv->chilnum != 0) {
        if (t2->v[l]->val < nowv->val) {
          l = nowv->num;
        }
      }
    }
    //	printf("dsum = %d\n", dsum);
    //	printf("dinsum = %d\n", dinsum);
    printf("%d\n", dsum + 2 * dinsum - t2->v[l]->val);
  }
}
