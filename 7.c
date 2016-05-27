#include <stdio.h>
#include <ctype.h>
int check[10];
int main() {
  struct {
    int left, right;
  } node[10];
  int n;
  char cl, cr;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; ++i) { // 程序不能自动终止，最后需要EOF ctrl+D，但最后正常accepted。不过还是找找scanf什么毛病吧，还是搞清楚吧。
    scanf("%c %c\n", &cl, &cr);
    if (cl != '-') {
      node[i].left = cl - '0';
      check[node[i].left] = 1;
    } else {
      node[i].left = -1;
    }
    if (cr != '-') {
      node[i].right = cr - '0';
      check[node[i].right] = 1;
    } else {
      node[i].right = -1;
    }
  }
  int root;
  for (int i = 0; i < n; ++i) 
    if (check[i] == 0) {
      root = i;
      break;
    }
  int queue[12], front = 0, rear = 0, size = 0;
  queue[++rear] = root;
  size++;
  while (size > 0) {
    int temp = queue[++front];
    --size;

    if (node[temp].left != -1) {
      queue[++rear] = node[temp].left;
      size++;
    }
    if (node[temp].right != -1) {
      queue[++rear] = node[temp].right;
      size++;
    }
    if (node[temp].left == -1 && node[temp].right == -1) {
      printf("%d", temp);
      if (size != 0)
        printf(" ");
    }    
  }
  printf("\n");
  return 0;
}
