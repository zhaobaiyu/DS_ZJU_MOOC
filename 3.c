#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int xs, zs;
  struct node *next;
} node;
void insert(node *a, int temp_xs, int temp_zs) {
  node *temp;
  temp = (node *)malloc(sizeof(node));
  temp->zs = temp_zs;
  temp->xs = temp_xs;
  temp->next = a->next;
  a->next = temp;
}
node *add_poly(node *poly_a, node *poly_b) {
  node *poly_c = (node *)malloc(sizeof(node));
  poly_c->next = NULL;
  node *pa = poly_a->next, *pb = poly_b->next, *pc = poly_c;
  while (pa != NULL && pb != NULL) {
    if (pa->zs == pb->zs && pa->xs + pb->xs != 0) {
      insert(pc, pa->xs + pb->xs, pa->zs);
      pa = pa->next;
      pb = pb->next;
      pc = pc->next;
    } else if (pa->zs == pb->zs && pa->xs + pb->xs == 0) {
      pa = pa->next;
      pb = pb->next;
    } else if (pa->zs > pb->zs) {
      insert(pc, pa->xs, pa->zs);
      pa = pa->next;
      pc = pc->next;
    } else {
      insert(pc, pb->xs, pb->zs);
      pb = pb->next;
      pc = pc->next;
    }
  }
  if (pa != NULL) {
    while (pa != NULL) {
      insert(pc, pa->xs, pa->zs);
      pc = pc->next;
      pa = pa->next;
    }
  } else {
    while (pb != NULL) {
      insert(pc, pb->xs, pb->zs);
      pc = pc->next;
      pb = pb->next;
    }
  }
  return poly_c;
}
node *input_poly(int n) {
  node *temp = (node *)malloc(sizeof(node));
  temp->next = NULL;
  node *p = temp;
  int temp_xs, temp_zs;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &temp_xs, &temp_zs);
    insert(p, temp_xs, temp_zs);
    p = p->next;
  }
  return temp;
}
void print_poly(node *poly) {
  node *temp = poly->next;
  if (temp == NULL) {
    printf("0 0\n");
  } else {
    printf("%d %d", temp->xs, temp->zs);
    temp = temp->next;
    while (temp != NULL) {
      printf(" %d %d", temp->xs, temp->zs);
      temp = temp->next;
    }
    printf("\n");
  }
}
void free_poly(node *poly) {
  node *temp = poly, *temp_next;
  while (temp != NULL) {
    temp_next = temp->next;
    free(temp);
    temp = temp_next;
  }
}
int main() {
  int n, m;
  node *poly_n, *poly_m;
  scanf("%d", &n);
  poly_n = input_poly(n);
  scanf("%d", &m);
  poly_m = input_poly(m);
  // /* 乘法开始
  node *cj_nm = (node *)malloc(sizeof(node));
  cj_nm->next = NULL;
  node *ploy_l, *ps, *pl; // short or long poly
  if (n > m) {
    ps = poly_m->next;
    ploy_l = poly_n->next;
  } else {
    ps = poly_n->next;
    ploy_l = poly_m->next;
  }
  while (ps != NULL) { // short先遍历，这样能减少调用合并同类项的次数
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    node *p = temp;
    pl = ploy_l;
    while (pl != NULL) {
      insert(p, pl->xs*ps->xs, pl->zs + ps->zs);
      p = p->next;
      pl = pl->next;
    }
    ps = ps->next;
    cj_nm = add_poly(cj_nm, temp);
    free_poly(temp);
  }
  print_poly(cj_nm);
  free_poly(cj_nm);
  // */
  node *sum_nm = add_poly(poly_n, poly_m);
  free_poly(poly_n);
  free_poly(poly_m);
  print_poly(sum_nm);
  free_poly(sum_nm);
  return 0;
}
