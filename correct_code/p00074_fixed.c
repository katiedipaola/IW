main(h, m, s) {
  for (; scanf("%d%d%d", &h, &m, &s), ~h;) {
    int left = 7200 - (60 * (60 * h + m) + s);
    printf("%02d:%02d:%02d\n", left / 3600, left % 3600 / 60, left % 60);
    left *= 3;
    printf("%02d:%02d:%02d\n", left / 3600, left % 3600 / 60, left % 60);
  }
  exit(0);
}