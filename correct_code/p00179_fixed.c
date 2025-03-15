S[1 << 20], Q[1 << 20], q;
b, u, x, i, n;
main(c) {
  for (; read(0, &c, 1);)
    if (c - 10)
      b = b * 4 + c % 3 + 1, u = u * 4 + 1;
    else {
      for (c = S[q = b] = 0; b % u; c = S[b = Q[b]])
        for (x = b ^ b / 4, i = 0; x > 3; i += 2, x /= 4)
          (n = x & 3) && !Q[n = b & ~(15 << i) ^ n * 5 << i]
              ? S[q = Q[q] = n] = c + 1
              : 0;
      b - 1 ? b ? printf("%d\n", S[b]) : puts("NA") : 0;
      memset(Q, c = b = u = 0, 4 << 20);
    }
}