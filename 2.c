// 这题陷阱还是挺多的
#include <stdio.h>
int main() {
  int k, temp, max_sum = -1, this_sum = 0, x = 0, y = 0, temp_x, reset = 1, all_neg = 1; // 默认最大子列和为-1，因为当序列中出现0的时候需要标记
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &temp);
    if (reset && (temp >= 0 || i == 1)) temp_x = temp; // 第一个元素要标记，其次当前面子列和为0且当前非负时标记
    reset = 0; 
    this_sum += temp;
    if (this_sum > max_sum) { // 发现新的最大子列和，标记前后元素，且标记序列不全为负
      max_sum = this_sum;
      x = temp_x;
      y = temp;
      all_neg = 0;
    }
    else if (this_sum < 0) { 
      reset = 1;
      this_sum = 0;
    }
  }
  if (all_neg) {
    x = temp_x;
    y = temp;
  }
  if (max_sum < 0) max_sum = 0;
  printf("%d %d %d\n", max_sum, x, y);
  return 0;
}
