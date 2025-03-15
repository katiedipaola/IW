b, o, s;
main(a) {
  for (scanf("%d"); ~scanf("%s", &a);)
    b += a % 3 ? a & 1 ? ++o % 3 ? 0
                                 : (s = !printf("%d\n", b > 3 ? s + b - 3 : s))
                       : 1
               : (s += b + 1, -b);
}