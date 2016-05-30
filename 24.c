#include <stdio.h>
#include <stdlib.h>
int cmp(const void *pa, const void *pb) {
  return *(int *)pa - *(int *)pb;
}
int a[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  qsort(a, n, sizeof(int), cmp);
  printf("%d", a[0]);
  for (int i = 1; i < n; ++i) printf(" %d", a[i]);
  printf("\n");
  return 0;
}
