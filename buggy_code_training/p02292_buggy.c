#include <math.h>
#include <stdio.h>
int main() {
  int n, ax, ay, bx, by, cx, cy, m, bax, bay, cax, cay, u;
  double t, x, y, p, q, r, s;
  scanf("%d%d%d%d", &ax, &ay, &bx, &by);
  scanf("%d", &n);
  bax = bx - ax;
  bay = by - ay;
  while (n--) {
    scanf("%d%d", &cx, &cy);
    cax = cx - ax;
    cay = cy - ay;
    t = (bax * cax + bay * cay) / (pow(bax, 2) + pow(bay, 2));
    x = ax + t * bax;
    y = ay + t * bay;
    m = -(cx - x) * bay + (cy - y) * bax;
    u = bax * cax + bay * cay;
    p = pow(u, 2);
    q = (pow(bax, 2) + pow(bay, 2)) * (pow(cax, 2) + pow(cay, 2));
    if (p == q && u < 0 && (ax != cx || ay != cy)) {
      puts("ONLINE_BACKE");
    } else if (p == q) {
      r = pow(bax, 2) + pow(bay, 2);
      s = pow(cax, 2) + pow(cay, 2);
      if (s > r) {
        puts("ONLINE_FRONT");
      } else {
        puts("ON_SEGMENT");
      }
    } else if (m > 0) {
      puts("COUNTER_CLOCKWISE");
    } else if (m < 0) {
      puts("CLOCKWISE");
    }
  }
  return 0;
}