#include <stdio.h>
#include <string.h>

static const char *e;
static int p, q, r;

static int expr(void);

static int term(void) {
  int res;

  switch (*(e++)) {
  case '-':
    res = expr();
    switch (res) {
    case 0:
      res = 2;
      break;
    case 2:
      res = 0;
      break;
    }
    break;
  case 'P':
    res = p;
    break;
  case 'Q':
    res = q;
    break;
  case 'R':
    res = r;
    break;
  case '0':
    res = 0;
    break;
  case '1':
    res = 1;
    break;
  case '2':
    res = 2;
    break;
  }

  return (res);
}

static int nanikaka(void) {
  int lt, rt;
  char opr;
  int res;

  lt = expr();
  opr = *(e++);
  rt = expr();

  switch (opr) {
  case '*':
    res = 1;
    if (lt == 0 || rt == 0)
      res = 1;
    if (lt == 2 && rt == 2)
      res = 2;
    break;
  case '+':
    res = 0;
    if (lt == 1 || rt == 1)
      res = 1;
    if (lt == 2 || rt == 2)
      res = 2;
    break;
  }

  return (res);
}

static int expr(void) {
  int lt, rt, res;

  switch (*e) {
  case '(':
    ++e;
    res = nanikaka();
    ++e;
    break;
  default:
    res = term();
    break;
  }

  return (res);
}

/** Application main entry point. */
int main(int argc, char *argv[]) {
  char s[128];

  for (;;) {
    int res = 0;

    scanf(" %s", s);
    if (!strcmp(s, "."))
      break;

    for (p = 0; p <= 2; ++p)
      for (q = 0; q <= 2; ++q)
        for (r = 0; r <= 2; ++r) {
          e = s;
          res += !!(expr() == 2);
        }

    printf("%d\n", res);
  }

  return (0);
}