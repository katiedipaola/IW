#include <stdio.h>

int main(void) {
  int menu;
  int hour, min, order_time;
  int hantei;
  int l_ac, d_ac, m_ac;
  int l_ord, d_ord, m_ord;
  int i;

  while (1) {
    scanf("%d", &menu);

    if (menu == 0) {
      break;
    }

    l_ord = d_ord = m_ord = l_ac = d_ac = m_ac = 0;

    for (i = 0; i < menu; i++) {
      scanf("%d%*c%d%d", &hour, &min, &order_time);

      if (11 <= hour && hour <= 14) {
        l_ord++;

        if (min > order_time) {
          hantei = order_time + 60 - min;
        }

        else {
          hantei = order_time - min;
        }

        if (hantei <= 8) {
          l_ac++;
        }
      }

      if (18 <= hour && hour <= 20) {
        d_ord++;

        if (min > order_time) {
          hantei = order_time + 60 - min;
        }

        else {
          hantei = order_time - min;
        }

        if (hantei <= 8) {
          d_ac++;
        }
      }

      if (21 <= hour && hour <= 23 || 0 <= hour && hour <= 1) {
        m_ord++;

        if (min > order_time) {
          hantei = order_time + 60 - min;
        }

        else {
          hantei = order_time - min;
        }

        if (hantei <= 8) {
          m_ac++;
        }
      }
    }
    printf("lunch ");

    if (l_ord == 0) {
      printf("no guest\n");
    }

    else {
      printf("%d\n", l_ac * 100 / l_ord);
    }

    printf("dinner ");

    if (d_ord == 0) {
      printf("no guest\n");
    }

    else {
      printf("%d\n", d_ac * 100 / d_ord);
    }

    printf("midnight ");

    if (m_ord == 0) {
      printf("no guest\n");
    }

    else {
      printf("%d\n", m_ac * 100 / m_ord);
    }
  }

  return (0);
}