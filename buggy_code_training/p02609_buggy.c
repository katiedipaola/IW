#include <math.h>
#include <stdio.h>
#include <string.h>

#define B_MAX 200001

char in_bit[200002];
int org_bit[200001]; //先頭が最下位bit

long long int q_list[200001]; // 10進数
// int divid_list[200001];//q_listの余りから入れていく
int a_list[200001]; // q_listの対

int main() {
  int n, org_b = 0;
  long long int x = 1, x_p_m = 1, x_m_m = 1, x_p_f = 0, x_m_f = 0;

  scanf("%d", &n);
  scanf("%s", in_bit);

  for (int i = 0; i < n; i++) {
    if (in_bit[(n - 1) - i] == '0') {
      org_bit[i] = 0;
    } else {
      org_bit[i] = 1;
      org_b++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (org_bit[i] == 1) {
      x_p_f += x_p_m;
      x_m_f += x_m_m;

      q_list[i] = -x_m_m;
    } else {
      q_list[i] = +x_p_m;
    }

    x_p_m *= 2;
    if (x_p_m > B_MAX)
      x_p_m = x_p_m % (org_b + 1);

    x_m_m *= 2;
    if (x_m_m > B_MAX) {
      if (org_bit != 1)
        x_m_m = x_m_m % (org_b - 1);
      else
        x_m_m = 0;
      a_list[i] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    long long int target;
    int answer = 1, tmp_bit;

    tmp_bit = org_b + 1 - 2 * org_bit[i];

    if (tmp_bit == 0) {

      target = 0;
    } else {
      if (org_bit[i] == 0) {
        target = ((q_list[i] + x_p_f) % (tmp_bit));
      } else {
        target = ((q_list[i] + x_m_f) % (tmp_bit));
      }

      answer++;
    }

    while (target != 0) {
      int tmp_tmp_bit = 0;
      long long int tmp_tmp_target = target;

      for (; tmp_tmp_target > 0;) {
        tmp_tmp_bit += (1) & (tmp_tmp_target);
        tmp_tmp_target = tmp_tmp_target >> 1;
      }

      target = target % tmp_tmp_bit;
      answer++;
      tmp_bit = tmp_tmp_bit;
    }

    a_list[i] = answer;
  }

  for (int i = (n - 1); i >= 0; i--) {
    printf("%d\n", a_list[i]);
  }

  return 0;
}