// 想了一天都没想到合适的方案，可是看了一眼别人的解析，就瞬间恍然大悟，唉，想不到方法真的很悲哀啊……
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *pa, const void *pb) {
    return *(int *)pa - *(int *)pb;
}
int cbt[1005], a[1005], n, temp = 0;
void inorder(int i) {
  if (2*i <= n)
    inorder(2*i);
  cbt[i] = a[temp++];
  if (2*i + 1 <= n)
    inorder(2*i + 1);
}
    
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  qsort(a, n, sizeof(int), cmp);
  inorder(1);
  printf("%d", cbt[1]);
  for (int i = 2; i <= n; ++i)
    printf(" %d", cbt[i]);
  printf("\n");
  return 0;
}
