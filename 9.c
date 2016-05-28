#include <stdio.h>
typedef struct {
  int left, right;
} tree;
void make_tree(tree t[], int n) {
  for (int i = 1; i <= n; ++i) {
    t[i].left = 0;
    t[i].right = 0;
  }
  int temp, node, root;
  scanf("%d", &root);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &temp);
    node = root;
    for ( ; ; ) {
      if (temp < node) {
        if (t[node].left == 0) {
          t[node].left = temp;
          break;
        } else {
          node = t[node].left;
        }
      } else {
        if (t[node].right == 0) {
          t[node].right = temp;
          break;
        } else {
          node = t[node].right;
        }
      }
    }
  }
  /* test
  printf("**************\n");
  for (int i = 1; i <= n; ++i) {
    printf("%d %d %d\n", i, t[i].left, t[i].right);
  }
  printf("**************\n");
  */
  
}
int cmp_tree(tree a[], tree b[], int n) {
  for (int i = 1; i <= n; ++i) 
    if (a[i].left != b[i].left || a[i].right != b[i].right) {
      return 0;
      break;
    }
  return 1;
}

int main() {
  int n, l;
  while(scanf("%d", &n) && n != 0) {
    scanf("%d", &l);
    tree a[11];
    make_tree(a, n);
    for (int i = 0; i < l; ++i) {
      tree b[11];
      make_tree(b, n);
      if (cmp_tree(a, b, n))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}
