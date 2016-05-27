// 这一题略复杂，我基本是分析堆栈使用情况写的程序，别人好的解题方法是push和pop操作分别对应前序和中序序列，然后通过他们得出后序序列，可是我没想到……
// 另外，NowCoder网站就是个坑，我第一次提交仅仅就是没有考虑到push数字为两位数情况，可是牛客网的测试数据是有问题的，差点误导了我，都准备重写了……所以牛客网刷PAT是很不靠谱的！
#include <stdio.h>
#include <ctype.h>
int stod() { // convert string to digit
  char str[10];
  fgets(str, 10, stdin);
  if (str[1] == 'o') {
    return 0;
  } else {
    if (isdigit(str[6])) 
      return (str[5] - '0') * 10 + (str[6] - '0');
    else
      return str[5] - '0';
  }
  /* // 第一次提交，没有考虑到数字为两位数时的情况，细心细心细心！！！！！！！！！！！！！！！！！！！！！！！！！
  else 
    return str[5] - '0';
  */
}
struct {
  int left, right;
} node[31];
int root;
void post_order(int n) {
  if (n != 0) {
    post_order(node[n].left);
    post_order(node[n].right);
    printf("%d", n);
    if (n == root)
      printf("\n");
    else
      printf(" ");
  }
}
int main() {
  int n;
  scanf("%d\n", &n);
  int s[31], top = 0;
  root = stod();
  s[top++] = root;
  int just_pop = 0;
  for (int i = 1; i < n + n; ++i) {
    int op = stod();
    // printf("%d\n", op); //
    if (op != 0) {
      if (just_pop == 0) {
        node[s[top-1]].left = op;
      } else {
        node[just_pop].right = op;
      }
      s[top++] = op;
      just_pop = 0;
    } else {
      if (just_pop == 0) {
        node[s[top-1]].left = 0;
      } else {
        node[just_pop].right = 0;
      }
      just_pop = s[--top];
    }
    /* test
      for (int i = 1; i <= n; ++i) 
    printf("%d %d %d\n", i, node[i].left, node[i].right);
      printf("\n");
    */
  }
  
  node[just_pop].right = 0;
  post_order(root);
  /*  test
  printf("last\n");
  for (int i = 1; i <= n; ++i) 
    printf("%d %d %d\n", i, node[i].left, node[i].right);
  */
  return 0;
  
}
    
