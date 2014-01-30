#include "list.h"
#include <stdio.h>

int main(void) {
  IntList *l1 = mk_list();
  IntList *l2 = mk_list();

  push_back(l1, 1);
  push_back(l1, 2);
  push_back(l1, 3);
  push_back(l2, 4);
  push_back(l2, 5);
  push_back(l2, 6);
  print_list(l1);
  print_list(l2);
  printf("\n");
  l1 = append3(l1, l2);
  IntList *l3 = append1(l1, l2);
  
  print_list(l1);
  print_list(l2);
  print_list(l3);
  
  free_list(l1);
  free_list(l2);
  free_list(l3);
  return 0;
}
