#include <stdio.h>
int main() {
  int h[1001];
  h[0] = -10005;
  int n, m, temp, j;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &temp);
    j = i;
    while (h[j/2] > temp) {
      h[j] = h[j/2];
      j /= 2;
    }
    h[j] = temp;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &temp);
    while (temp > 1) {
      printf("%d ", h[temp]);
      temp /= 2;
    }
    printf("%d\n", h[1]);
  }
  return 0;
}
