#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
typedef long double ld;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define repp(i, l, r, k) for (ll i = (l); i < (r); i += (k))
#define rrep(i, l, r) for (ll i = (l); i >= (r); i--)
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 17)
#define YES printf("Yes\n")
#define NO printf("No\n")
#define PN printf("\n")
#define charsize 100005 // 10^5+5

void swap(ll *a, ll *b) {
  ll c;
  c = *b;
  *b = *a;
  *a = c;
}
// void fill(ll n, ll a[n], ll value){ rep(i,0,n) a[i] = value; }
void cin(ll *n) { scanf("%lld", &(*n)); }
void cin2(ll *a, ll *b) { scanf("%lld%lld", &(*a), &(*b)); }
void cin3(ll *a, ll *b, ll *c) { scanf("%lld%lld%lld", &(*a), &(*b), &(*c)); }
ll max2(ll a, ll b) { return a >= b ? a : b; }
ll min2(ll a, ll b) { return a >= b ? b : a; }
ll min3(ll a, ll b, ll c) { return (a <= b && a <= c) ? a : b <= c ? b : c; }
ll max3(ll a, ll b, ll c) { return (a >= b && a >= c) ? a : b >= c ? b : c; }
ll minn(ll n, ll a[n]) {
  ll b = INF;
  rep(i, 0, n) b = min2(b, a[i]);
  return b;
}
ll maxn(ll n, ll a[n]) {
  ll b = -INF;
  rep(i, 0, n) b = max2(b, a[i]);
  return b;
}
ll ABS(ll a) { return a >= 0 ? a : (-a); }
ll POW(ll a, ll b) {
  ll c = 1;
  rep(i, 0, b) c *= a;
  return c;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod_MOD1(ll n) {
  n += n < 0 ? ((-n) / MOD1 + 1) * MOD1 : 0;
  return n %= MOD1;
}
ll mod_p(ll n, ll p) {
  n += n < 0 ? ((-n) / p + 1) * p : 0;
  return n %= p;
}
ll change_into_num(char s[], ll len, ll p) {
  return !p ? 0
            : POW(10, p - 1) * (s[len - p] - '0') +
                  change_into_num(s, len, p - 1);
}

int upll(const void *a, const void *b) {
  return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0;
}
int downll(const void *a, const void *b) {
  return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0;
}
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }
// int int_sort( const void * a , const void * b ) {
//   return strcmp(( char * )a , ( char * )b );
// }
//     qsort((void*)s,n,sizeof(s[0]),int_sort );

typedef struct {
  ll a, b;
} fr;
int cmp1(const void *p, const void *q) { return ((fr *)p)->a - ((fr *)q)->a; }
int cmp2(const void *p, const void *q) { return ((fr *)q)->a - ((fr *)p)->a; }
void strsortup(fr *a, int n) { qsort(a, n, sizeof(fr), cmp1); }
void strsortdown(fr *a, int n) { qsort(a, n, sizeof(fr), cmp2); }

void lr_lower(int *l, int *r, ll am, ll val, int type) {
  (type < 3) ? (am < val ? (*l = (*l + *r) / 2) : (*r = (*l + *r) / 2))
             : (am <= val ? (*l = (*l + *r) / 2) : (*r = (*l + *r) / 2));
  // if(type==1){
  //     am < val ?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 );
  // }
  // if(type==2){
  //     am < val ?  ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 );
  // }
  // if(type==3){
  //     am <= val ? ( *l = (*l+*r)/2 ) : ( *r= (*l+*r)/2 );
  // }
}
int cmp_lower(ll a, ll b, int type) {
  return (type == 1)   ? (a == b ? 1 : 0)
         : (type == 2) ? (a >= b ? 1 : 0)
                       : (a > b ? 1 : 0);
  // if(type==1) return a==b ? 1 : 0;
  // if(type==2) return a>=b ? 1 : 0;
  // if(type==3) return a>b ? 1 : 0;

  // return 0;
}
/*
 return p  which meets them
 a[p] =  val : type 1
 a[p] >= val : type 2
 a[p] >  val : type 3
*/
ll lower_bound(ll a[], int l, int r, ll val, int type) {
  while (r - l > 1) {
    // int m = (l+r)/2;
    lr_lower(&l, &r, a[(l + r) / 2], val, type);
    // if(a[m]>val) r=m;
    // else l=m;
  }
  return cmp_lower(a[l], val, type) ? l : cmp_lower(a[r], val, type) ? r : -1;
}

ll upper_bound(ll a[], int l, int r, ll val) {
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (a[m] > val)
      r = m;
    else
      l = m;
  }
  return a[r] == val ? r : a[l] == val ? l : -1;
}

/*ai(i=l~r)のうち、ai=xとなるiの個数*/
ll count(ll n, ll a[], ll l, ll r, ll x) {
  ll p = lower_bound(a, l, r, x, 1);
  return p == -1 ? 0 : upper_bound(a, p, r, x) - p + 1;
}

int main(void) {
  // char ;
  ll n;
  ll ans = 0;
  cin(&n);
  // cin(&);
  // cin(&);
  // cin2(&,&);
  // cin3(&,&,&);
  // scanf("%s",);
  ll a[n], sub[n - 1], used[n], mark = 0, sub2[n - 1];
  rep(i, 0, n) used[i] = 0;
  rep(i, 0, n) {
    cin(&a[i]);
    if (i) {
      sub[i - 1] = a[i] - (i + 1);
    }
    if (i != n - 1) {
      sub2[i] = -a[i] - (i + 1);
    }
  }
  // sortup(sub,n-1);
  sortup(sub2, n - 1);

  // rep(i,0,n-1) printf("%lld ",sub[i]);
  // PN;
  // rep(i,0,n-1) printf("%lld ",sub2[i]);
  // PN;
  // rep(i,0,n-1){
  //     ll val= -a[i]-(i+1),judge=0;
  //     rep(j,0,mark){
  //         if(val == used[j]){
  //             judge++;
  //         }
  //     }
  //     printf("%lld ",val);
  //     printf("%lld %lld ",lower_bound4(n-1,sub,0,n-2,val) ,
  //     upper_bound(n-1,sub,0,n-2,val)  ); ans+=count(n-1,sub,0,n-2,val);
  //     // printf("%lld ",ans);
  //     ans-=judge;
  //     used[mark] = a[i]-(i+1);
  //     printf("%lld \n",ans);
  //     mark++;
  // }

  rep(i, 0, n - 1) {
    ll p = count(n - 1, sub2, 0, n - 2, sub[i]);
    // printf("%lld ",p);
    ans += p;
  }

  printf("%lld\n", ans);
  return 0;
}
