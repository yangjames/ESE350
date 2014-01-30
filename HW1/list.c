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

// done
bool del(IntList *list, int n, int *ret) {
  if (is_empty(list) || n < 0 || n >= length(list)) {
    *ret = -1;
    return false;
  }
  Node *no = list->first;
  int counter = 0;
  if (n == 0)
    return pop_front(list, ret);
  while (counter != n - 1) {
    no = no->next;
    counter++;
  }
  Node *t = no->next;
  *ret = t->value;
  no->next = t->next;
  free(t);
  return true;
}


IntList* append1(IntList *l1, IntList *l2) {
  IntList *ret = mk_list();
  ret = append2(ret, l1);
  ret = append2(ret, l2);
  return ret;
}

// done
IntList* append2(IntList *l1, IntList *l2) {
  if (is_empty(l1) && is_empty(l2))
    return l1;
    
  Node *n2 = l2->first;

  if (is_empty(l1)) {
    push_back(l1, n2->value);
    Node *t = (Node*)malloc(sizeof(Node));
    t->value = n2->value;
    t->next = NULL;
    l1->first = t;
    n2 = n2->next;
  }
  // if l1 is first empty
  Node *n1 = l1->first;
  while (n1->next != NULL)
    n1 = n1->next;
  while (n2 != NULL) {
    Node *t = (Node*)malloc(sizeof(Node));
    t->value = n2->value;
    t->next = NULL;
    n1->next = t;
    n2 = n2->next;
    n1 = n1->next;
  }
  
  return l1;
}

IntList* append3(IntList *l1, IntList *l2) {
  int ret;
  while(pop_front(l2, &ret)) {
    push_back(l1, ret);
  }
  return l1;
}


/*
  1. Imagine that we have lists l1=[1,2,3] and l2=[4,5,6].
     For each append function describe what values l1 and
     l2 contain after execution of that function as well
     as the contents of any other lists that might exist.

     l3 = append1(l1, l2) -> l1=[1,2,3]
                             l2=[4,5,6]
			     l3=[1,2,3,4,5,6]

     l1 = append2(l1, l2) -> l1=[1,2,3,4,5,6]
                             l2=[4,5,6]

     l1 = append3(l1, l2) -> l1=[1,2,3,4,5,6]
                             l2=[]

  2. What are the trade-offs between using the various
     append functions? In particular how do they differ
     in space usage and likelihood of memory safety
     violations?

     append1 has the worst space complexity. Memory
     usage doubles, and both input linked lists remain
     occupied. append1 is the safest to use because it
     requires the declaration of a new linked list,
     making it impossible to accidentally have the two
     input linked list pointers from pointing to each
     other or some unallocated space.

     append2's space complexity grows linearly with l2.
     It's not as bad as append1's space complexity, but
     still wastes memory. It's easier to commit a
     memory safety violation because the return value
     is a pointer to the first linked list. Accidentally
     setting l2 = append2(l1, l2) could lead to a seg-fault.
     So could declaring a new pointer and setting it equal
     to append2
     i.e IntList *l3 = append2(l1, l2) -> seg-fault

     append3's space complexity is constant, but suffers
     from the same memory safety violations as append2.
     
  3. An alternative specification of append3 would involve
     _node sharing_. Rather than transferring nodes from
     l2 to l1, we could simply share the nodes so that l2
     still points to its nodes. Why is this not a good design?
     In particular, what kind of memory safety violation is
     more likely to happen with this design?

     l1 = append3(l1, l2);
     free_list(l2);
     print_list(l1); // SEGFAULT because l2 pointed to
                     // nodes in l1
 */
