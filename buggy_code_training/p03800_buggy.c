#include <stdio.h>

int main() {
  int n;
  int a = 0;
  scanf("%d", &n);
  char s[100005], sw[100005] = {0}, ss[100005] = {0}, ws[100005] = {0},
                  ww[100005] = {0};
  sw[0] = 'S';
  sw[1] = 'W';
  ss[0] = 'S';
  ss[1] = 'S';
  ww[0] = 'W';
  ww[1] = 'W';
  ws[0] = 'W';
  ws[1] = 'S';
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%c", &s[i]);
  }
  for (int i = 0; i < 4; i++) {
    a = 0;
    if (i == 0) {
      for (int j = 1; j < n; j++) {
        if (j != n - 1) {
          if (s[j] == 'o') {
            if (ss[j - 1] == 'S' && ss[j] == 'S') {
              ss[j + 1] = 'S';
            } else if (ss[j - 1] == 'S' && ss[j] == 'W') {
              ss[j + 1] = 'W';
            } else if (ss[j - 1] == 'W' && ss[j] == 'S') {
              ss[j + 1] = 'W';
            } else if (ss[j - 1] == 'W' && ss[j] == 'W') {
              ss[j + 1] = 'S';
            }
          } else {
            if (ss[j - 1] == 'S' && ss[j] == 'S') {
              ss[j + 1] = 'W';
            } else if (ss[j - 1] == 'S' && ss[j] == 'W') {
              ss[j + 1] = 'S';
            } else if (ss[j - 1] == 'W' && ss[j] == 'S') {
              ss[j + 1] = 'S';
            } else if (ss[j - 1] == 'W' && ss[j] == 'W') {
              ss[j + 1] = 'W';
            }
          }
        } else {
          if (s[j] == 'o') {
            if (ss[j - 1] == 'S' && ss[j] == 'S') {
              if (ss[0] == 'S') {
                if (s[0] == 'o') {
                  if (ss[j] == ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                } else {
                  if (ss[j] != ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ss[j - 1] == 'W' && ss[j] == 'S') {
              if (ss[0] == 'W') {
                if (s[0] == 'o') {
                  if (ss[j] != ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                } else {
                  if (ss[j] == ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ss[j - 1] == 'S' && ss[j] == 'W') {
              if (ss[0] == 'W') {
                if (s[0] == 'o') {
                  if (ss[j] != ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                } else {
                  if (ss[j] == ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ss[j - 1] == 'W' && ss[j] == 'W') {
              if (ss[0] == 'S') {
                if (s[0] == 'o') {
                  if (ss[j] == ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                } else {
                  if (ss[j] != ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                }
              }
            }
          } else {
            if (ss[j - 1] == 'S' && ss[j] == 'S') {
              if (ss[0] == 'W') {
                if (s[0] == 'o') {
                  if (ss[j] != ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                } else {
                  if (ss[j] == ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ss[j - 1] == 'W' && ss[j] == 'S') {
              if (ss[0] == 'S') {
                if (s[0] == 'o') {
                  if (ss[j] == ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                } else {
                  if (ss[j] != ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ss[j - 1] == 'S' && ss[j] == 'W') {
              if (ss[0] == 'S') {
                if (s[0] == 'o') {
                  if (ss[j] == ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                } else {
                  if (ss[j] != ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ss[j - 1] == 'W' && ss[j] == 'W') {
              if (ss[0] == 'W') {
                if (s[0] == 'o') {
                  if (ss[j] != ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                } else {
                  if (ss[j] == ss[1]) {
                    printf("%s", ss);
                    a = 1;
                    break;
                  }
                }
              }
            }
          }
        }
      }
      if (a = 1) {
        break;
      } else {
        a = 0;
      }
    } else if (i == 1) {
      for (int j = 1; j < n; j++) {
        if (j != n - 1) {
          if (s[j] == 'o') {
            if (sw[j - 1] == 'S' && sw[j] == 'S') {
              sw[j + 1] = 'S';
            } else if (sw[j - 1] == 'S' && sw[j] == 'W') {
              sw[j + 1] = 'W';
            } else if (sw[j - 1] == 'W' && sw[j] == 'S') {
              sw[j + 1] = 'W';
            } else if (sw[j - 1] == 'W' && sw[j] == 'W') {
              sw[j + 1] = 'S';
            }
          } else {
            if (sw[j - 1] == 'S' && sw[j] == 'S') {
              sw[j + 1] = 'W';
            } else if (sw[j - 1] == 'S' && sw[j] == 'W') {
              sw[j + 1] = 'S';
            } else if (sw[j - 1] == 'W' && sw[j] == 'S') {
              sw[j + 1] = 'S';
            } else if (sw[j - 1] == 'W' && sw[j] == 'W') {
              sw[j + 1] = 'W';
            }
          }
        } else {
          if (s[j] == 'o') {
            if (sw[j - 1] == 'S' && sw[j] == 'S') {
              if (sw[0] == 'S') {
                if (s[0] == 'o') {
                  if (sw[j] == sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                } else {
                  if (sw[j] != sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (sw[j - 1] == 'W' && sw[j] == 'S') {
              if (sw[0] == 'W') {
                if (s[0] == 'o') {
                  if (sw[j] != sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                } else {
                  if (sw[j] == sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (sw[j - 1] == 'S' && sw[j] == 'W') {
              if (sw[0] == 'W') {
                if (s[0] == 'o') {
                  if (sw[j] != sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                } else {
                  if (sw[j] == sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (sw[j - 1] == 'W' && sw[j] == 'W') {
              if (sw[0] == 'S') {
                if (s[0] == 'o') {
                  if (sw[j] == sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                } else {
                  if (sw[j] != sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                }
              }
            }
          } else {
            if (sw[j - 1] == 'S' && sw[j] == 'S') {
              if (sw[0] == 'W') {
                if (s[0] == 'o') {
                  if (sw[j] != sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                } else {
                  if (sw[j] == sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (sw[j - 1] == 'W' && sw[j] == 'S') {
              if (sw[0] == 'S') {
                if (s[0] == 'o') {
                  if (sw[j] == sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                } else {
                  if (sw[j] != sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (sw[j - 1] == 'S' && sw[j] == 'W') {
              if (sw[0] == 'S') {
                if (s[0] == 'o') {
                  if (sw[j] == sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                } else {
                  if (sw[j] != sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (sw[j - 1] == 'W' && sw[j] == 'W') {
              if (sw[0] == 'W') {
                if (s[0] == 'o') {
                  if (sw[j] != sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                } else {
                  if (sw[j] == sw[1]) {
                    printf("%s", sw);
                    a = 1;
                    break;
                  }
                }
              }
            }
          }
        }
      }
      if (a = 1) {
        break;
      } else {
        a = 0;
      }
    } else if (i == 2) {
      for (int j = 1; j < n; j++) {
        if (j != n - 1) {
          if (s[j] == 'o') {
            if (ww[j - 1] == 'S' && ww[j] == 'S') {
              ww[j + 1] = 'S';
            } else if (ww[j - 1] == 'S' && ww[j] == 'W') {
              ww[j + 1] = 'W';
            } else if (ww[j - 1] == 'W' && ww[j] == 'S') {
              ww[j + 1] = 'W';
            } else if (ww[j - 1] == 'W' && ww[j] == 'W') {
              ww[j + 1] = 'S';
            }
          } else {
            if (ww[j - 1] == 'S' && ww[j] == 'S') {
              ww[j + 1] = 'W';
            } else if (ww[j - 1] == 'S' && ww[j] == 'W') {
              ww[j + 1] = 'S';
            } else if (ww[j - 1] == 'W' && ww[j] == 'S') {
              ww[j + 1] = 'S';
            } else if (ww[j - 1] == 'W' && ww[j] == 'W') {
              ww[j + 1] = 'W';
            }
          }
        } else {
          if (s[j] == 'o') {
            if (ww[j - 1] == 'S' && ww[j] == 'S') {
              if (ww[0] == 'S') {
                if (s[0] == 'o') {
                  if (ww[j] == ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                } else {
                  if (ww[j] != ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ww[j - 1] == 'W' && ww[j] == 'S') {
              if (ww[0] == 'W') {
                if (s[0] == 'o') {
                  if (ww[j] != ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                } else {
                  if (ww[j] == ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ww[j - 1] == 'S' && ww[j] == 'W') {
              if (ww[0] == 'W') {
                if (s[0] == 'o') {
                  if (ww[j] != ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                } else {
                  if (ww[j] == ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ww[j - 1] == 'W' && ww[j] == 'W') {
              if (ww[0] == 'S') {
                if (s[0] == 'o') {
                  if (ww[j] == ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                } else {
                  if (ww[j] != ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                }
              }
            }
          } else {
            if (ww[j - 1] == 'S' && ww[j] == 'S') {
              if (ww[0] == 'W') {
                if (s[0] == 'o') {
                  if (ww[j] != ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                } else {
                  if (ww[j] == ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ww[j - 1] == 'W' && ww[j] == 'S') {
              if (ww[0] == 'S') {
                if (s[0] == 'o') {
                  if (ww[j] == ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                } else {
                  if (ww[j] != ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ww[j - 1] == 'S' && ww[j] == 'W') {
              if (ww[0] == 'S') {
                if (s[0] == 'o') {
                  if (ww[j] == ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                } else {
                  if (ww[j] != ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ww[j - 1] == 'W' && ww[j] == 'W') {
              if (ww[0] == 'W') {
                if (s[0] == 'o') {
                  if (ww[j] != ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                } else {
                  if (ww[j] == ww[1]) {
                    printf("%s", ww);
                    a = 1;
                    break;
                  }
                }
              }
            }
          }
        }
      }
      if (a = 1) {
        break;
      } else {
        a = 0;
      }
    } else if (i == 3) {
      for (int j = 1; j < n; j++) {
        if (j != n - 1) {
          if (s[j] == 'o') {
            if (ws[j - 1] == 'S' && ws[j] == 'S') {
              ws[j + 1] = 'S';
            } else if (ws[j - 1] == 'S' && ws[j] == 'W') {
              ws[j + 1] = 'W';
            } else if (ws[j - 1] == 'W' && ws[j] == 'S') {
              ws[j + 1] = 'W';
            } else if (ws[j - 1] == 'W' && ws[j] == 'W') {
              ws[j + 1] = 'S';
            }
          } else {
            if (ws[j - 1] == 'S' && ws[j] == 'S') {
              ws[j + 1] = 'W';
            } else if (ws[j - 1] == 'S' && ws[j] == 'W') {
              ws[j + 1] = 'S';
            } else if (ws[j - 1] == 'W' && ws[j] == 'S') {
              ws[j + 1] = 'S';
            } else if (ws[j - 1] == 'W' && ws[j] == 'W') {
              ws[j + 1] = 'W';
            }
          }
        } else {
          if (s[j] == 'o') {
            if (ws[j - 1] == 'S' && ws[j] == 'S') {
              if (ws[0] == 'S') {
                if (s[0] == 'o') {
                  if (ws[j] == ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                } else {
                  if (ws[j] != ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ws[j - 1] == 'W' && ws[j] == 'S') {
              if (ws[0] == 'W') {
                if (s[0] == 'o') {
                  if (ws[j] != ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                } else {
                  if (ws[j] == ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ws[j - 1] == 'S' && ws[j] == 'W') {
              if (ws[0] == 'W') {
                if (s[0] == 'o') {
                  if (ws[j] != ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                } else {
                  if (ws[j] == ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ws[j - 1] == 'W' && ws[j] == 'W') {
              if (ws[0] == 'S') {
                if (s[0] == 'o') {
                  if (ws[j] == ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                } else {
                  if (ws[j] != ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                }
              }
            }
          } else {
            if (ws[j - 1] == 'S' && ws[j] == 'S') {
              if (ws[0] == 'W') {
                if (s[0] == 'o') {
                  if (ws[j] != ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                } else {
                  if (ws[j] == ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ws[j - 1] == 'W' && ws[j] == 'S') {
              if (ws[0] == 'S') {
                if (s[0] == 'o') {
                  if (ws[j] == ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                } else {
                  if (ws[j] != ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ws[j - 1] == 'S' && ws[j] == 'W') {
              if (ws[0] == 'S') {
                if (s[0] == 'o') {
                  if (ws[j] == ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                } else {
                  if (ws[j] != ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                }
              }
            } else if (ws[j - 1] == 'W' && ws[j] == 'W') {
              if (ws[0] == 'W') {
                if (s[0] == 'o') {
                  if (ws[j] != ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                } else {
                  if (ws[j] == ws[1]) {
                    printf("%s", ws);
                    a = 1;
                    break;
                  }
                }
              }
            }
          }
        }
      }
      if (a = 1) {
        break;
      } else {
        a = 0;
      }
    }
  }
  if (a != 1) {
    printf("-1");
  }
}