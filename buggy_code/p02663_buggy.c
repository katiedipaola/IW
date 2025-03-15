/*
 * FileName:     A
 * CreatedDate:  2020-05-30 20:53:32 +0900
 * LastModified: 2020-05-30 21:14:19 +0900
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int h_1, m_1, h_2, m_2, k;
  scanf("%d%d%d%d%d", &h_1, &m_1, &h_2, &m_2, &k);
  if (h_1 <= h_2 && m_1 <= m_2) {
    printf("%d\n", (h_2 - h_1) * 60 + (m_2 - m_1) - k);
    return 0;
  } else if (h_1 <= h_2 && m_1 > m_2) {
    printf("%d\n", (h_2 - h_1) * 60 + (m_2 + 60 - m_1) - k);
    return 0;
  } else if (h_1 > h_2 && m_1 <= m_2) {
    printf("%d\n", ((h_2 + 24) - h_1) * 60 + (m_2 - m_1) - k);
    return 0;
  }
  printf("%d\n", ((h_2 + 24) - h_1) * 60 + (m_2 + 60 - m_1) - k);
  return 0;
}
