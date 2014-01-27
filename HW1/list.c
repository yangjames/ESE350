#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// done
IntList* mk_list(void) {
  IntList *ret = (IntList*)malloc(sizeof(IntList));
  ret->first = NULL;
  return ret;
}

// done
void free_list(IntList *list) {
  Node *n = list->first;
  if (n == NULL) {
    free(list);
    return;
  }
  Node *t;
  while (n->next != NULL) {
    while (n->next != NULL) {
      t = n;
      n = n->next;
    }
    free(n);
    t->next = NULL;
    n = list->first;
  }
  free(n);
  free(list);
}

// done
void print_list(IntList *list) {
  if (is_empty(list)) {
    printf("[]\n");
    return;
  }
  int len = length(list);
  printf("list length: %d\n", len);
  Node *n = list->first;
  int it = 1;
  printf("[");
  while (n != NULL) {
    if (it++ < len)
      printf("%d, ", n->value);
    else
      printf("%d]\n", n->value);
    n = n->next;
  }
}

// done
bool is_empty(IntList *list) {
  return list->first == NULL;
}

// done
int length(IntList *list) {
  if (list->first == NULL)
    return 0;
  Node *n = list->first;
  int counter = 1;
  while (n->next != NULL) {
    counter++;
    n = n->next;
  }
  return counter;
}

// done
int sum(IntList *list) {
  if (is_empty(list))
    return 0;
  int sum = 0;
  Node *n = list->first;
  while (n != NULL) {
    sum += n->value;
    n = n->next;
  }
  return sum;
}

// done
bool index_of(IntList *list, int value, int *ret) {
  int idx = 0;
  if (is_empty(list))
    return false;
  Node *n = list->first;
  while (n != NULL) {
    if (n->value == value) {
      *ret = idx;
      return true;
    }
    idx++;
    n = n->next;
  }
  *ret = -1;
  return false;
}

// done
void push_back(IntList *list, int value) {
  if (list->first == NULL) {
    list->first = (Node*)malloc(sizeof(Node));
    list->first->next = NULL;
    list->first->value = value;
    return;
  }
  Node *n = list->first;
  while (n->next != NULL) {
    n = n->next;
  }
  Node *t = (Node*)malloc(sizeof(Node));
  t->value = value;
  t->next = NULL;
  n->next = t;
}

// done
void push_front(IntList *list, int value) {
  if (list->first == NULL) {
    list->first = (Node*)malloc(sizeof(Node));
    list->first->next = NULL;
    list->first->value = value;
    return;
  }
  Node *n = list->first;
  Node *t = (Node*)malloc(sizeof(Node));
  t->value = value;
  t->next = n;
  list->first = t;
}

// done
bool insert(IntList *list, int value, int n) {
  if (n > length(list) || n < 0)
    return false;
  if (n == 0) {
    push_front(list, value);
    return true;
  }
  Node *no = list->first;
  int idx = 0;
  while (idx++ != n - 1)
    no = no->next;
  Node *t = (Node*)malloc(sizeof(Node));
  t->value = value;
  t->next = no->next;
  no->next = t;
  return true;
}

// done
void intersparse(IntList *list, int value) {
  if (is_empty(list) || length(list) == 1)
    return;
  Node *n = list->first;
  int counter = -1;
  while (n->next != NULL) {
    counter++;
    counter %= 2;
    if (counter == 0) {
      Node *t = (Node*)malloc(sizeof(Node));
      t->value = value;
      t->next = n->next;
      n->next = t;
    }
    n = n->next;
  }
}

// done
bool pop_front(IntList *list, int *ret) {
  if (is_empty(list)) {
    *ret = -1;
    return false;
  }
  Node *n = list->first;
  *ret = n->value;
  list->first = list->first->next;
  free(n);
  return true;
}

bool del(IntList *list, int n, int *ret) {
  if (is_empty(list) || n < 0 || n >= length(list)) {
    *ret = -1;
    return false;
  }
  Node *no = list->first;
  int counter = 0;
  while (counter++ != n - 1)
    no = no->next;
  Node *t = no->next;
  *ret = t->value;
  no->next = t->next;
  return true;
}

IntList* append1(IntList *l1, IntList *l2) {
}

IntList* append2(IntList *l1, IntList *l2) {
}

IntList* append3(IntList *l1, IntList *l2) {
}
