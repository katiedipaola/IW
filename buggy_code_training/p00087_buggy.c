#include <math.h>
#include <stdio.h>

double stack[200];
int sp;

void push(double n) { stack[sp++] = n; }

double pop(void) { return (stack[--sp]); }

int main(void) {
  char str[1000];
  char *p;
  double a, b;

  while (fgets(str, 1000, stdin) != NULL) {
    p = str;
    sp = 0;
    while (*p != '\0' && *p != '\n') {
      switch (*p) {
      case '+':
        a = pop();
        b = pop();
        push(b + a);
        p++;
        break;

      case '*':
        a = pop();
        b = pop();
        push(b * a);
        p++;
        break;

      case '/':
        a = pop();
        b = pop();
        push(b / a);
        p++;
        break;

      case ' ':
      case '\n':
        p++;
        break;

      case '-':
        if ('0' <= *(p + 1) && *(p + 1) <= '9') {
          //				    a = atof(p);
          //					push(a);
          push(atof(p));
          p++;
          while ('0' <= *p && *p <= '9') {
            p++;
          }
        } else {
          a = pop();
          b = pop();
          push(b - a);
          p++;
        }
        break;

      default:
        //			    a = atof(p);
        //				push(a);
        push(atof(p));
        while ('0' <= *p && *p <= '9') {
          p++;
        }
        break;
      }
    }
    //		printf("%f\n", stack[0]);
    printf("%lf\n", pop());
  }
  return (0);
}