#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
  char ele, left, right;
} TreeNode;
TreeNode treeA[10], treeB[10];
char dtoa(char d, char ab) {
  TreeNode *node;
  if (ab == 'A')
    node = treeA;
  else
    node = treeB;
  if (isdigit(d))
    return node[d - '0'].ele;
  else
    return d;
}
int cmp(const void *pa, const void *pb) {
  return ((TreeNode *)pa)->ele - ((TreeNode *)pb)->ele;
}
int main() {
  char c;
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    while(isspace(c = getchar())) ;
    treeA[i].ele = c;
    while(isspace(c = getchar())) ;
    treeA[i].left = c;
    while(isspace(c = getchar())) ;
    treeA[i].right = c;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    while(isspace(c = getchar())) ;
    treeB[i].ele = c;
    while(isspace(c = getchar())) ;
    treeB[i].left = c;
    while(isspace(c = getchar())) ;
    treeB[i].right = c;        
  }
  if (n != m) {
    printf("No\n");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    treeA[i].left = dtoa(treeA[i].left, 'A');
    treeA[i].right = dtoa(treeA[i].right, 'A');
    treeB[i].left = dtoa(treeB[i].left, 'B');
    treeB[i].right = dtoa(treeB[i].right, 'B');
  }
  qsort(treeA, n, sizeof(TreeNode), cmp);
  qsort(treeB, n, sizeof(TreeNode), cmp);
  int is_right = 1;
  for (int i = 0; i < n; ++i) {
    if (treeA[i].ele != treeB[i].ele) {
      is_right = 0;
      break;
    } else if ((treeA[i].left != treeB[i].left) && (treeA[i].left != treeB[i].right)) {
      is_right = 0;
      break;
    } else if ((treeA[i].right != treeB[i].left) && (treeA[i].right != treeB[i].right)) {
      is_right = 0;
      break;
    }
  }
  if (is_right)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
