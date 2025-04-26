////#include <stdio.h>
////long long int n,a,b[100001],c[100001],num[100001]={},d[4001]={};
////	  int i,j,x=0;
////	  int sum=0;
////	   int main(){
////	  while(1){
////	  scanf("%lld",&n);
////	  if(n==0) break;
////	  for(i=0;i<n;i++){
////		  scanf("%lld %lld %lld",&a,&b[i],&c[i]);
////		  d[a] += b[i]*c[i];
////                            num[i]=a;
////	  }
////	  for(i=0;i<n;i++){
////		  if(d[num[i]]>=1000000){
////                                 for(j=1;j<i;j++){
////                                     if(num[j]==num[i]){
////                                             x=1;
////                                              break;
////                                    }} if(x==0){
////			  printf("%lld\n",a);
////			  sum++;
////			}
////		  }
////	  }
////	  if(sum==0){
////		  printf("NA\n");
////	  }
////	  sum = 0;
////	  for(i=1;i<=4000;i++){
////		  d[i]=0;
////	  }
////	  }
////	  return 0;
////  }
////
//#include <stdio.h>
// int main(void){
//	int n,i,j,x,y,z,f,a[4000];
//	long long t,b[4000];
//	for(;scanf("%d",&n),n;f||puts("NA"))
//		for(f=i=0;n--;){
//			scanf("%d%d%d",&x,&y,&z);
//			t=z;
//			for(j=i;--j>=0&&a[j]-x;);
//			if(j<0){a[j=i]=x;b[i++]=y*t;}
//			else if(b[j]>=0)b[j]+=y*t;
//			if(b[j]>=1000000)
//				b[j]=f=-printf("%d\n",a[j]);
//		}
//		return 0;
//}
#include <stdio.h>
int main() {
  int n, m, i;
  long long int x, y, z;
  long long int sum[4001];
  int q, a[4000];
  while (1) {
    scanf("%d ", &n);
    if (n == 0)
      break;
    m = 0;
    q = 0;
    for (i = 1; i < 4001; i++) {
      sum[i] = 0;
    }
    while (n--) {
      scanf("%lld %lld %lld ", &x, &y, &z);
      sum[x] += y * z;
      a[q] = x;
      q++;
    }
    for (i = 0; i < n; i++)
      if (1000000 <= sum[a[i]]) {
        printf("%d\n", a[i]);
        m = 1;
        sum[a[i]] = 0;
      }
    if (m == 0)
      printf("NA\n");
  }
  return 0;
}