#include <stdio.h>
int main() {
  int data[100005], next[100005], order[100005], n, k, first, temp, ex;
  scanf("%d%d%d", &first, &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    scanf("%d%d", &data[temp], &next[temp]);
  }
  temp = first;
  for (int i = 1; i <= n; ++i) {
    order[i] = temp;
    temp = next[temp];
    if (temp == -1) {
      n = i;
      break;
    }
  }
  for (int i = 1; i + k - 1 <= n; i += k) {
    for (int j = i; j <= i - 1 + k/2; ++j) {
      ex = 2*i + k - 1 - j;
      temp = order[j];
      order[j] = order[ex];
      order[ex] = temp;
    }
  }
  for (int i = 1; i < n; ++i) 
    printf("%05d %d %05d\n", order[i], data[order[i]], order[i+1]);
  printf("%05d %d -1\n", order[n], data[order[n]]);
  return 0;
}
