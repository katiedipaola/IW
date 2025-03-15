#include <stdio.h>
#include <string.h>

int main(void) {
  char str[300], head[300], tail[300];
  int len, i;

  fgets(str, 300, stdin);
  len = strlen(str);

  //  printf("%d\n",len);

  if (len % 2)
    len = len - 3;
  else
    len = len - 2;

  // printf("%d\n",len);
  while (len >= 0) {
    //      printf("len = %d\n",len);
    for (i = 0; i < len / 2; i++) {
      head[i] = str[i];
      //  printf("head[%d] = %c\n",i,str[i]);
    }
    head[i] = '\0';

    for (i = 0; i < len / 2; i++) {
      tail[i] = str[len / 2 + i];
      // printf("tail[%d] = %c\n",i,str[len/2 + i]);
    }
    tail[i] = '\0';
    /*
    printf("head:");
    printf(head);
    printf("\n");
    printf("tail:");
    printf(tail);
    printf("\n");
    */
    // printf("strcmp = %d\n",strcmp(head,tail));

    if (strcmp(head, tail) == 0) {
      printf("%d\n", len);
      return 0;
    }
    len = len - 2;
  }

  return 0;
}
