#include <stdio.h>
#include <string.h>

int main(void) {
  char S[200002], T[200002];
  int n, x[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         i, j, ans = 0;
  scanf("%s %s", S, T);
  n = strlen(S);
  for (i = 0; i < n; i++) {
    if (S[i] == 'a') {
      if (x[1] == 0) {
        x[1] = T[i];
      } else {
        if (x[1] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'b') {
      if (x[2] == 0) {
        x[2] = T[i];
      } else {
        if (x[2] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'c') {
      if (x[3] == 0) {
        x[3] = T[i];
      } else {
        if (x[3] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'd') {
      if (x[4] == 0) {
        x[4] = T[i];
      } else {
        if (x[4] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'e') {
      if (x[5] == 0) {
        x[5] = T[i];
      } else {
        if (x[5] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'f') {
      if (x[6] == 0) {
        x[6] = T[i];
      } else {
        if (x[6] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'g') {
      if (x[7] == 0) {
        x[7] = T[i];
      } else {
        if (x[7] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'h') {
      if (x[8] == 0) {
        x[8] = T[i];
      } else {
        if (x[8] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'i') {
      if (x[9] == 0) {
        x[9] = T[i];
      } else {
        if (x[9] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'j') {
      if (x[10] == 0) {
        x[10] = T[i];
      } else {
        if (x[10] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'k') {
      if (x[11] == 0) {
        x[11] = T[i];
      } else {
        if (x[11] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'l') {
      if (x[12] == 0) {
        x[12] = T[i];
      } else {
        if (x[12] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'm') {
      if (x[13] == 0) {
        x[13] = T[i];
      } else {
        if (x[13] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'n') {
      if (x[14] == 0) {
        x[14] = T[i];
      } else {
        if (x[14] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'o') {
      if (x[15] == 0) {
        x[15] = T[i];
      } else {
        if (x[15] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'p') {
      if (x[16] == 0) {
        x[16] = T[i];
      } else {
        if (x[16] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'q') {
      if (x[17] == 0) {
        x[17] = T[i];
      } else {
        if (x[17] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'r') {
      if (x[18] == 0) {
        x[18] = T[i];
      } else {
        if (x[18] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 's') {
      if (x[19] == 0) {
        x[19] = T[i];
      } else {
        if (x[19] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 't') {
      if (x[20] == 0) {
        x[20] = T[i];
      } else {
        if (x[20] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'u') {
      if (x[21] == 0) {
        x[21] = T[i];
      } else {
        if (x[21] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'v') {
      if (x[22] == 0) {
        x[22] = T[i];
      } else {
        if (x[22] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'w') {
      if (x[23] == 0) {
        x[23] = T[i];
      } else {
        if (x[23] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'x') {
      if (x[24] == 0) {
        x[24] = T[i];
      } else {
        if (x[24] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'y') {
      if (x[25] == 0) {
        x[25] = T[i];
      } else {
        if (x[25] != T[i]) {
          ans = 1;
          break;
        }
      }
    } else if (S[i] == 'z') {
      if (x[0] == 0) {
        x[0] = T[i];
      } else {
        if (x[0] != T[i]) {
          ans = 1;
          break;
        }
      }
    }
  }
  for (i = 0; i < 25; i++) {
    for (j = i + 1; j < 26; j++) {
      if (x[i] != 0 && x[j] != 0 && x[i] == x[j])
        ans = 1;
    }
  }
  if (ans == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
