#include "list.h"
#include <stdio.h>
#define DOORS_COUNT 5
void add_door_test(struct node *elem, struct door *door);
void remove_door_test(struct node *elem, struct node *root);

int main() {
  struct door doors[DOORS_COUNT];
  struct node *root = init(&doors[0]);
  add_door_test(root, &doors[1]);
  add_door_test(root, &doors[2]);
  add_door_test(root, &doors[3]);
  remove_door_test(root->next->next->next, root);
  remove_door_test(root->next->next, root);
  remove_door_test(root->next, root);
  destroy(root);
  return 0;
}

void add_door_test(struct node *elem, struct door *door) {
  struct node *result = add_door(elem, door);
  if (result->door == door) {
    printf("SUCCESS\n");
  } else {
    printf("FAIl\n");
  }
  result = find_door(result->door->id, elem);
}

void remove_door_test(struct node *elem, struct node *root) {
  struct node *expected = elem->next;
  struct node *result = remove_door(elem, root);
  if (result->next == expected) {
    printf("SUCCESS\n");
  } else {
    printf("FAIl\n");
  }
}
