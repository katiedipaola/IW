#include <stdio.h>
int main(void) {
  int n;
  scanf("%d", &n);
  long int t = 0;
  long int s = 0;
  long int x[200000] = {};
  long int y[200000] = {};
  int xmax = 0;
  int xmin = 0;
  int ymax = 0;
  int ymin = 0;
  long int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%ld %ld", &t, &s);
    x[i] = t + s;
    y[i] = t - s;
    // printf("%ld %ld\n",x[i],y[i]);

    if (!i) {
      xmax = i;
      xmin = i;
    } else if (x[i] > x[xmax]) {
      xmax = i;
    } else if (x[i] < x[xmin]) {
      xmin = i;
    }
    if (!i) {
      ymax = i;
      ymin = i;
    } else if (y[i] > y[ymax]) {
      ymax = i;
    } else if (y[i] < y[ymin]) {
      ymin = i;
    }
  }

  // printf("%ld %ld %ld %ld\n",x[xmax],x[xmin],y[ymax],y[ymin]);

  for (int i = 0; i < n; i++) {
    // printf(";%ld\n",(abs(x[i]-x[xmax])>=abs(y[i]-y[xmax])?abs(x[i]-x[xmax]):abs(y[i]-y[xmax])));
    //(abs(x[i]-x[xmax])>=abs(y[i]-y[xmax])?abs(x[i]-x[xmax]):abs(y[i]-y[xmax]))
    if (ans < (abs(x[i] - x[xmax]) >= abs(y[i] - y[xmax])
                   ? abs(x[i] - x[xmax])
                   : abs(y[i] - y[xmax])))
      ans = (abs(x[i] - x[xmax]) >= abs(y[i] - y[xmax]) ? abs(x[i] - x[xmax])
                                                        : abs(y[i] - y[xmax]));
    if (ans < (abs(x[i] - x[xmin]) >= abs(y[i] - y[xmin])
                   ? abs(x[i] - x[xmin])
                   : abs(y[i] - y[xmin])))
      ans = (abs(x[i] - x[xmin]) >= abs(y[i] - y[xmin]) ? abs(x[i] - x[xmin])
                                                        : abs(y[i] - y[xmin]));
    if (ans < (abs(x[i] - x[ymax]) >= abs(y[i] - y[ymax])
                   ? abs(x[i] - x[ymax])
                   : abs(y[i] - y[ymax])))
      ans = (abs(x[i] - x[ymax]) >= abs(y[i] - y[ymax]) ? abs(x[i] - x[ymax])
                                                        : abs(y[i] - y[ymax]));
    if (ans < (abs(x[i] - x[ymin]) >= abs(y[i] - y[ymin])
                   ? abs(x[i] - x[ymin])
                   : abs(y[i] - y[ymin])))
      ans = (abs(x[i] - x[ymin]) >= abs(y[i] - y[ymin]) ? abs(x[i] - x[ymin])
                                                        : abs(y[i] - y[ymin]));
  }
  printf("%ld\n", ans);
}