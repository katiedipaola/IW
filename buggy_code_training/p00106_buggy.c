#include <stdio.h>

#define A_MAX 25 // A店25*200=5000
#define B_MAX 16 // B店16*300=4800
#define C_MAX 10 // C店10*500=5000

#define A_PRICE 380 // A店のそば粉1袋の金額
#define B_PRICE 550 // B店のそば粉1袋の金額
#define C_PRICE 850 // C店のそば粉1袋の金額

#define A_QUANT 200 // A店の1袋辺りの内容量
#define B_QUANT 300 // B店の1袋辺りの内容量
#define C_QUANT 500 // C店の1袋辺りの内容量

void simulation(int input, int *result); //購入金額をシミュレートする関数

main() {
  int n = 0, result = 0;
  while (scanf("%d", &n), n != 0) {
    simulation(n, &result);
    printf("%d\n", result);
  }
  return 0;
}
void simulation(int input, int *result) {
  int a = 0, b = 0, c = 0; //制御変数
  int price = 0;           //価格を代入する変数

  int a_low = 0, a_high = 0; // a_low:割引される袋数,a_high:割引されない袋数
  int b_low = 0, b_high = 0; // b_low:割引される袋数,b_high:割引されない袋数
  int c_low = 0, c_high = 0; // c_low:割引される袋数,c_high:割引されない袋数

  for (a = 0; a <= A_MAX; a++) {
    for (b = 0; b <= B_MAX; b++) {
      for (c = 0; c <= C_MAX; c++) {
        if (((a * A_QUANT) + (b * B_QUANT) + (c * C_QUANT)) == input) {

          a_high = a % 5, a_low = a - a_high;
          b_high = b % 4, b_low = b - b_high;
          c_high = c % 3, c_low = c - c_high;

          price = (((A_PRICE * a_low) * 0.8) + (A_PRICE * a_high)) +
                  (((B_PRICE * b_low) * 0.85) + (B_PRICE * b_high)) +
                  (((C_PRICE * c_low) * 0.88) + (C_PRICE * c_high));

          if (*result == 0) {
            *result = price;
          }
          if (*result > price) {
            *result = price;
          }
        }
      }
    }
  }
}