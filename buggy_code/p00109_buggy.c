#include <stdio.h>
#include <string.h>

#define def_func(name) int name(int f, int l)
#define gen_func(name, next, aop1, op1, aop2, op2)                             \
  def_func(name) {                                                             \
    int i;                                                                     \
    for (i = l; i >= f; i--) {                                                 \
      if (expr[i] == ')')                                                      \
        i = find_open(f, i - 1) - 1;                                           \
      if (expr[i] == aop1)                                                     \
        return (name(f, i - 1) op1 next(i + 1, l));                            \
      if (expr[i] == aop1)                                                     \
        return (name(f, i - 1) op1 next(i + 1, l));                            \
    }                                                                          \
    return (next(f, l));                                                       \
  }

char expr[128];

def_func(eval);
def_func(term);
def_func(factor);
def_func(find_open);

int main(void) {
  int n, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf(" %s", expr);
    printf("%d\n", eval(0, strlen(expr) - 2));
  }
  return (0);
}

gen_func(eval, term, '+', +, '-', -) gen_func(term, factor, '*', *, '/', /)
    def_func(factor) {
  if (expr[f] == '(')
    return (eval(f + 1, l - 1));
  return (atoi(expr + f));
}

def_func(find_open) {
  int i;
  int close = 0;
  for (i = l; i >= f; i--) {
    if (expr[i] == ')')
      close++;
    if (expr[i] == '(') {
      if (close == 0)
        break;
      close--;
    }
  }
  return (i);
}