int main() {
  long long I, O, T, J, L, S, Z;
  scanf("%lld%lld%lld%lld%lld%lld%lld", &I, &O, &T, &J, &L, &S, &Z);
  long long n = (I & 1 ? I - 1 : I) + (J & 1 ? J - 1 : J) + (L & 1 ? L - 1 : L);
  if (I && J && L) {
    long long m =
        (I & 1 ? I : I - 2) + (J & 1 ? J : J - 2) + (L & 1 ? L : L - 2) + 3;
    printf("%lld", (n < m ? m : n) + O);
  } else {
    printf("%lld", n + O);
  }
}