#include <math.h>
#include <stdio.h>
struct points {
  double x;
  double y;
};
int main(void) {

  struct points eigenvector;
  int p1x, p1y, p2x, p2y, px, py;
  double length;
  int q;
  int i;
  scanf("%d%d%d%d", &p1x, &p1y, &p2x, &p2y);
  struct points p1, p2;
  p1.x = p1x;
  p1.y = p1y;

  p2.x = p2x;
  p2.y = p2y;
  length = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  eigenvector.x = (p2.x - p1.x) / length;
  eigenvector.y = (p2.y - p1.y) / length;

  scanf("%d", &q);

  for (i = 0; i < q; ++i) {
    scanf("%d%d", &px, &py);
    // double  returnqx, returnqy;
    double length1 = (px - p1.x) * eigenvector.x + (py - p1.y) * eigenvector.y;
    printf("%.10f,%.10f\n", p1.x + length1 * eigenvector.x,
           p1.y + length1 * eigenvector.y);
  }

  return 0;
}