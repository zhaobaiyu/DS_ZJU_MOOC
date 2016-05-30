#include <stdio.h>
int a[51];
int main() {
  int n, temp;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    ++a[temp];
  }
  for (int i = 0; i < 51; ++i)
    if (a[i] != 0) 
      printf("%d:%d\n", i, a[i]);
  return 0;
}
