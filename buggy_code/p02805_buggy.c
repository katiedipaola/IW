N;
double x[50], y[50];
double cx, cy, cr;
double norm(double x1, double y1, double x2, double y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int in(int id) { return norm(x[id], y[id], cx, cy) < cr + 1e-10; }
void make2(int ia, int ib) {
  cx = (x[ia] + x[ib]) / 2;
  cy = (y[ia] + y[ib]) / 2;
  cr = norm(x[ia], y[ia], cx, cy);
}
void make3(int ia, int ib, int ic) {
  double A = norm(x[ib], y[ib], x[ic], y[ic]);
  double B = norm(x[ic], y[ic], x[ia], y[ia]);
  double C = norm(x[ia], y[ia], x[ib], y[ib]);
  double S =
      (x[ib] - x[ia]) * (y[ic] - y[ia]) - (x[ic] - x[ia]) * (y[ib] - y[ia]);
  S = 4 * S * S;
  cx = (A * (B + C - A) * x[ia] + B * (C + A - B) * x[ib] +
        C * (A + B - C) * x[ic]) /
       S;
  cy = (A * (B + C - A) * y[ia] + B * (C + A - B) * y[ib] +
        C * (A + B - C) * y[ic]) /
       S;
  cr = norm(x[ia], y[ib], cx, cy);
}
main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%lf%lf", &x[i], &y[i]);
  make2(0, 1);
  for (int i = 2; i < N; i++) {
    if (!in(i)) {
      make2(0, i);
      for (int j = 1; j < i; j++) {
        if (!in(j)) {
          make2(i, j);
          for (int k = 0; k < j; k++) {
            if (!in(k)) {
              make3(i, j, k);
            }
          }
        }
      }
    }
  }
  printf("%.16f\n", sqrt(cr));
}
