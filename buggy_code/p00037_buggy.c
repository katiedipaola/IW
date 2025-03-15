#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_UNIT_SIZE 10000
#define MAX_LINE_LENGTH 1000

typedef struct {
  int x, y;
} vector_t;

void complex_mul(const vector_t *v1, const vector_t *v2, vector_t *t) {
  t->x = v1->x * v2->x - v1->y * v2->y;
  t->y = v1->x * v2->y + v1->y * v2->x;
}

char *bufp[100], *wall[1000], path[10000];
const vector_t next_dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const char dir_char[][3] = {{' ', 'U', ' '}, {'L', ' ', 'R'}, {' ', 'D', ' '}};

int main(void) {
  int W, H, i;
  int buf_idx, buf_len, path_idx, nx, ny;
  char *buf;
  vector_t pos, dir, ndir;

  buf_idx = 0;
  buf_len = 0;
  buf = (char *)malloc(BUF_UNIT_SIZE * sizeof(char));
  bufp[buf_idx++] = buf;
  for (i = 0, W = 0; gets(buf) != NULL; i++) {
    wall[i] = buf;
    if (W == 0)
      W = strlen(buf);
    buf_len += strlen(buf) + 1;
    if (buf_len + MAX_LINE_LENGTH > BUF_UNIT_SIZE) {
      buf = (char *)malloc(BUF_UNIT_SIZE * sizeof(char));
      bufp[buf_idx++] = buf;
      buf_len = 0;
    } else {
      buf += strlen(buf) + 1;
    }
  }
  H = i;

  path_idx = 0;
  path[path_idx++] = 'R';
  pos.x = 0;
  pos.y = 0;
  dir.x = 1;
  dir.y = 0;
  while (1) {
    for (i = 0; i < 3; i++) {
      complex_mul(&dir, &next_dir[i], &ndir);
      if ((pos.y & 1) == 0) {
        ny = pos.y + ndir.y;
        nx = pos.x + ndir.x + (dir.x > 0) * ((ny + 2) & 1);
      } else {
        ny = pos.y + ndir.y + dir.y;
        nx = pos.x + ndir.x - (ndir.x > 0);
      }
      if (nx < 0 || W + (ny & 1) <= nx || ny < 0 || H <= ny)
        continue;
      if (wall[ny][nx] == '1')
        break;
    }
    if (i == 3) {
      dir.x = -dir.x;
      dir.y = -dir.y;
    } else {
      pos.x = nx;
      pos.y = ny;
      dir.x = ndir.x;
      dir.y = ndir.y;
    }
    path[path_idx++] = dir_char[1 + dir.y][1 + dir.x];

    if ((pos.x == 0 && pos.y == 0 && dir.x == -1) ||
        (pos.x == 0 && pos.y == 1 && dir.y == -1))
      break;
  }

  path[path_idx] = '\0';
  puts(path);

  for (i = 0; i < buf_idx; i++) {
    free(bufp[i]);
  }
  return 0;
}