#include <stdio.h>

int main(void) {
  float weight;

  while (scanf("%f", &weight) != EOF) {
    if (weight <= 48.0) {
      puts("light fly");
    } else if (weight <= 51.0) {
      puts("fly");
    } else if (weight <= 54.0) {
      puts("bantam");
    } else if (weight <= 57.0) {
      puts("feather");
    } else if (weight <= 60.0) {
      puts("light");
    } else if (weight <= 64.0) {
      puts("light welter");
    } else if (weight <= 69.0) {
      puts("welter");
    } else if (weight <= 75.0) {
      puts("light middle");
    } else if (weight <= 81.0) {
      puts("middle");
    } else if (weight <= 91.0) {
      puts("light heavy");
    } else {
      puts("heavy");
    }
  }

  return 0;
}