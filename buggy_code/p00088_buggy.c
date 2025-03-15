#include <stdio.h>
#include <string.h>
char encode[96][8];
char decode[32];
int main(void) {
  strcpy(encode[' '], "101");
  strcpy(encode['\n'], "");
  strcpy(encode['\''], "000000");
  strcpy(encode[','], "000011");
  strcpy(encode['-'], "10010001");
  strcpy(encode['.'], "010001");
  strcpy(encode['?'], "000001");
  strcpy(encode['A'], "100101");
  strcpy(encode['B'], "10011010");
  strcpy(encode['C'], "0101");
  strcpy(encode['D'], "0001");
  strcpy(encode['E'], "110");
  strcpy(encode['F'], "01001");
  strcpy(encode['G'], "10011011");
  strcpy(encode['H'], "010000");
  strcpy(encode['I'], "0111");
  strcpy(encode['J'], "10011000");
  strcpy(encode['K'], "0110");
  strcpy(encode['L'], "00100");
  strcpy(encode['M'], "10011001");
  strcpy(encode['N'], "10011110");
  strcpy(encode['O'], "00101");
  strcpy(encode['P'], "111");
  strcpy(encode['Q'], "10011111");
  strcpy(encode['R'], "1000");
  strcpy(encode['S'], "00110");
  strcpy(encode['T'], "00111");
  strcpy(encode['U'], "10011100");
  strcpy(encode['V'], "10011101");
  strcpy(encode['W'], "000010");
  strcpy(encode['X'], "10010010");
  strcpy(encode['Y'], "10010011");
  strcpy(encode['Z'], "10010000");
  int n, i, k;
  char type[200], code[10000];
  for (i = 0; i < 26; i++) {
    decode[i] = 'A' + i;
  }
  decode[26] = ' ';
  decode[27] = '.';
  decode[28] = ',';
  decode[29] = '-';
  decode[30] = '\'';
  decode[31] = '?';
  while (fgets(type, 10000, stdin) != NULL) {
    code[0] = '\0';
    n = strlen(type);
    for (i = 0; i < n; i++) {
      strcat(code, encode[type[i]]);
    }
    n = strlen(code);
    for (i = 0; i < n; i += 5) {
      k = 0;
      if (code[i] == '1')
        k += 16;
      if (code[i + 1] == '1' && i + 1 < n)
        k += 8;
      if (code[i + 2] == '1' && i + 2 < n)
        k += 4;
      if (code[i + 3] == '1' && i + 3 < n)
        k += 2;
      if (code[i + 4] == '1' && i + 4 < n)
        k += 1;
      printf("%c", decode[k]);
    }
    printf("\n");
  }
  return 0;
}