#include <stdio.h>
#include <ctype.h>
int a[10005];
int find(int i) {
  while (a[i] > 0) 
    i = a[i];
  return i;
}

int main() {
  int n, c1, c2, root1, root2;
  char c;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    a[i] = -1;
  }
  while(isspace(c = getchar())) ;
  while(c != 'S') {
    scanf("%d %d", &c1, &c2);
    if (c1 <= 0 || c1 > n || c2 <= 0 || c2 > n) {
      printf("no\n");
      continue;
    }
    if (c == 'C') {
      if (c1 == c2) {
        printf("yes\n");
      } else {
        root1 = find(c1);
        root2 = find(c2);
        if (root1 == root2)
          printf("yes\n");
        else
          printf("no\n");
      }
    } else {
      if (c1 != c2) {
        root1 = find(c1);
        root2 = find(c2);
        if (root1 != root2) {
          if (a[root1] < a[root2]) {
            a[root1] += a[root2];
            a[root2] = root1;
          } else {
            a[root2] += a[root1];
            a[root1] = root2;
          }
        }
      }
    }
    while (isspace(c = getchar())) ;
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) 
    if (a[i] < 0)
      ++sum;
  if (sum == 1)
    printf("The network is connected.\n");
  else
    printf("There are %d components.\n", sum);
  return 0;
}
