#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  int Aprice, Bprice, Cprice;
  int numA, numB;

  scanf("%d %d %d %d %d", &Aprice, &Bprice, &Cprice, &numA, &numB);

  long ans = 5000000000;
  int numMAX = 0;
  if (numA > numB)
    numMAX = numA;
  else
    numMAX = numB;

  long price;

  for (int i = 0; i <= numMAX; i++) {
    if (numA >= i && numB >= i)
      price = Aprice * (numA - i) + Bprice * (numB - i) + Cprice * 2 * i;
    else if (numA >= i && numB < i)
      price = Aprice * (numA - i) + Cprice * 2 * i;
    else if (numA < i && numB >= i)
      price = Bprice * (numB - i) + Cprice * 2 * i;

    if (price < ans)
      ans = price;
  }

  printf("%ld\n", ans);

  return 0;
}
