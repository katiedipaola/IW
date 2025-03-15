s, t;
main(x, i) {
  for (; ~scanf("%d", &x); i++ < 4 ? s += x : (t += x))
    ;
  s = !printf("%d\n", s > t ? s : t);
}