#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare_int(const void *a, const void *b) {
  //    return *(int*)a - *(int*)b;
  return *(long long *)a - *(long long *)b;
}
//  qsort(A, b, sizeof(int), compare_int);

int main() {

  int a, b, c, d, e, X, Y;
  //  double  c;
  //  long long  A[100003]={};
  int B[100003] = {};
  int C[100003] = {};

  int flag[103] = {};

  //  long long  a, b, c, d, X, Y;
  char s[101] = {};
  char t[101] = {};
  //  int N, M;
  //  int A[1000000001]={};
  //  long long  C[101]={};
  int i, j, k;
  //  int flag=0;
  int tmp = 0;
  //  int min=1000000;
  long long min = 100000001;
  int len = 0;
  int cnt = 0;
  int num = 0;
  double ans = 1000;
  int max = 0;
  //  char
  //  alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  //  a=0;
  //  scanf("%lld %lld", &a, &b);
  scanf("%s", &s);
  //  cnt = strlen(t);
  t[0] = s[0];
  t[1] = s[1];
  t[2] = s[2];
  t[3] = s[3];
  t[4] = "\0";
  cnt = atoi(t);

  if (cnt < 2019) {
    printf("Heisei\n");
    return 0;
  }
  t[0] = s[5];
  t[1] = s[6];
  t[2] = "\0";
  cnt = atoi(t);
  //     printf("%d\n", cnt);
  if (cnt < 4) {
    printf("Heisei\n");
    return 0;
  }

  printf("TBD\n");

  /*
  for(i=0;i<a;i++){
    scanf("%lld", &A[i]);
//    printf("%lld ",A[i]);
    if(A[i]==1) {
      printf("1\n");
      return 0;
    }
  }

  qsort(A, a, sizeof(long long), compare_int);

  for(i=0;i<a;i++){
    printf("%lld ",A[i]);



  }
*/
  //  //  if(flag==0)   printf("TLE\n");
  //    if(max < cnt - max)  printf("Yes\n");
  //    else  printf("No\n");

  return 0;
}
