#include <stdio.h>
int main() {
  int m, n, k, a[1005], s[1005];
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j)
      scanf("%d", &a[j]);
    int pop_max = 0;
    int stack_sum = 0;
    int not_match = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] < 1 || a[j] > n) {
        not_match = 1;
        break;
      }
      else if (a[j] > pop_max) {
        if (a[j] - pop_max + stack_sum > m) {
          not_match = 1;
          break;
        } else {
          for (int ii = pop_max + 1; ii < a[j]; ++ii)
            s[stack_sum++] = ii;
          pop_max = a[j];
        }
      } else {
        if (a[j] != s[stack_sum - 1]) {
          not_match = 1;
          break;
        } else {
          --stack_sum;
        }
      }
    }
    if (not_match)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
