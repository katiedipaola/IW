b, r, g, c, s;
main(t) {
  for (; scanf("%d%d%d%d%d%d", &b, &r, &g, &c, &s, &t), ~b && t;)
    //    printf("%d\n",100-(t-s)*3+c*2+g*7+95*b+63*r);
    printf("%d\n", 100 - (t - s) * 3 + c * 2 + 95 * b + 7 * (9 * r + g));
}