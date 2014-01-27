#include "list.h"
#include <stdio.h>

int main(void) {
  IntList *ll = mk_list();
  push_back(ll, 6);
  push_back(ll, 7);  
  print_list(ll);
  free_list(ll);
  ll = mk_list();
  push_back(ll, 1);
  push_back(ll, 2);
  push_back(ll, 3);
  push_back(ll, 4);
  push_front(ll, 5);
  print_list(ll);
  int idx;
  index_of(ll, 6, &idx);
  printf("%d %d\n", sum(ll), idx);
  insert(ll, 10, 4);
  print_list(ll);
  intersparse(ll, 77);
  int ret;
  print_list(ll);
  del(ll, 0, &ret);
  print_list(ll);

  return 0;
}
