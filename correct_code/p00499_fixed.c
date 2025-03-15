L;
main(A, B, C, D) {
  scanf("%d%d%d%d%d", &L, &A, &B, &C, &D);
  L = !printf("%.f\n", L - fmax(--A / C, --B / D) - 1);
}