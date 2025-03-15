#include <stdio.h>
#include <string.h>
int n;
int price[100];
char item[100][101];
char target[101], material[101], whatWeWant[101];

int get_price(char *s) {
  int i;
  for (i = 0; i < n && strcmp(s, item[i]); i++)
    ;
  return i;
}

int main(int argc, char const *argv[]) {
  int i, j, m, r, cost;
  int target_price;
  while (scanf("%d", &n), n) {
    for (i = 0; i < n; i++)
      scanf("%s%d", item[i], &price[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
      cost = 0;
      scanf("%s%d", target, &r);
      for (j = 0; j < r; j++) {
        scanf("%s", material);
        cost += price[get_price(material)];
      }
      target_price = price[get_price(target)];
      price[get_price(target)] = (cost < target_price ? cost : target_price);
    }
    scanf("%s", whatWeWant);
    printf("%d\n", price[get_price(whatWeWant)]);
  }

  return 0;
}