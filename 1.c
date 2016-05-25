#include <stdio.h>
int main() {
  int k, temp;
  scanf("%d", &k);
  int max_sum = 0, this_sum = 0;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &temp);
    this_sum += temp;
    if (this_sum > max_sum)
      max_sum = this_sum;
    else if (this_sum < 0)
      this_sum = 0;
  }
  printf("%d\n", max_sum);
  return 0;
}
