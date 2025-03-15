#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Size 9
#define Queue_size 1024
#define Hash_size 1024
#define queue_next(i) (((i) + 1) % Queue_size)
struct hash_table {
  long data;
  struct hash_table *next;
};
struct hash_table *hash[Hash_size];
int swap_upper(int *, int *);
int swap_lower(int *, int *);
int swap_left(int *, int *);
int swap_right(int *, int *);
long board_val(int *);
void val_board(long, int *);
void hash_insert(long);
int hash_search(long);
int Bfs(int *, int *);
int main(void) {
  int i, result, init[Size], goal[Size] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  for (i = 0; i < Size; i++)
    scanf("%d", &init[i]);
  for (i = 0; i < Hash_size; i++)
    hash[i] = NULL;
  printf("%d\n", Bfs(init, goal));
}
int swap_upper(int *board, int *next) {
  int i, pos, e = sqrt(Size);
  for (i = 0; i < Size; i++) {
    if (!board[i])
      pos = i;
  }
  if (!(pos / e))
    return 0;
  else {
    memcpy(next, board, sizeof(int) * Size);
    next[pos] = board[pos - e];
    next[pos - e] = board[pos];
  }
  return 1;
}
int swap_lower(int *board, int *next) {
  int i, pos, e = sqrt(Size);
  for (i = 0; i < Size; i++) {
    if (!board[i])
      pos = i;
  }
  if ((pos / e) == e - 1)
    return 0;
  else {
    memcpy(next, board, sizeof(int) * Size);
    next[pos] = board[pos + e];
    next[pos + e] = board[pos];
  }
  return 1;
}
int swap_left(int *board, int *next) {
  int i, pos, e = sqrt(Size);
  for (i = 0; i < Size; i++) {
    if (!board[i])
      pos = i;
  }
  if (!(pos % e))
    return 0;
  else {
    memcpy(next, board, sizeof(int) * Size);
    next[pos] = board[pos - 1];
    next[pos - 1] = board[pos];
  }
  return 1;
}
int swap_right(int *board, int *next) {
  int i, pos, e = sqrt(Size);
  for (i = 0; i < Size; i++) {
    if (!board[i])
      pos = i;
  }
  if ((pos % e) == e - 1)
    return 0;
  else {
    memcpy(next, board, sizeof(int) * Size);
    next[pos] = board[pos + 1];
    next[pos + 1] = board[pos];
  }
  return 1;
}
long board_val(int *board) {
  int i, digit = 1;
  long val = 0;
  for (i = 0; i < Size; i++) {
    val += board[Size - 1 - i] * digit;
    digit *= 10;
  }
  return val;
}
void val_board(long val, int *board) {
  int i, digit = 1;
  for (i = 0; i < Size; i++) {
    board[Size - 1 - i] = (val / digit) % 10;
    digit *= 10;
  }
}
void hash_insert(long val) {
  struct hash_table *p = (struct hash_table *)malloc(sizeof(struct hash_table));
  p->data = val;
  p->next = hash[val % Hash_size];
  hash[val % Hash_size] = p;
}
int hash_search(long val) {
  struct hash_table *n;
  for (n = hash[val % Hash_size]; n != NULL; n = n->next) {
    if (val == n->data)
      return 1;
  }
  return 0;
}
int Bfs(int *init, int *goal) {
  int depth = 0, ptr_front = 0, ptr_back = 0;
  long queue[Queue_size][2];
  queue[ptr_back][0] = board_val(init);
  queue[ptr_back][1] = depth;
  ptr_back = queue_next(ptr_back);
  if (!memcmp(init, goal, sizeof(int) * Size))
    return depth;
  while (ptr_front != ptr_back) {
    int curr[Size], next[Size];
    long val;
    val = queue[ptr_front][0];
    val_board(val, curr);
    depth = queue[ptr_front][1];
    ptr_front = queue_next(ptr_front);
    depth++;
    hash_insert(val);
    if (swap_upper(curr, next)) {
      if (!hash_search(board_val(next))) {
        if (!memcmp(next, goal, sizeof(int) * Size))
          return depth;
        queue[ptr_back][0] = board_val(next);
        queue[ptr_back][1] = depth;
        ptr_back = queue_next(ptr_back);
      }
    }
    if (swap_lower(curr, next)) {
      if (!hash_search(board_val(next))) {
        if (!memcmp(next, goal, sizeof(int) * Size))
          return depth;
        queue[ptr_back][0] = board_val(next);
        queue[ptr_back][1] = depth;
        ptr_back = queue_next(ptr_back);
      }
    }
    if (swap_left(curr, next)) {
      if (!hash_search(board_val(next))) {
        if (!memcmp(next, goal, sizeof(int) * Size))
          return depth;
        queue[ptr_back][0] = board_val(next);
        queue[ptr_back][1] = depth;
        ptr_back = queue_next(ptr_back);
      }
    }
    if (swap_right(curr, next)) {
      if (!hash_search(board_val(next))) {
        if (!memcmp(next, goal, sizeof(int) * Size))
          return depth;
        queue[ptr_back][0] = board_val(next);
        queue[ptr_back][1] = depth;
        ptr_back = queue_next(ptr_back);
      }
    }
  }
}
