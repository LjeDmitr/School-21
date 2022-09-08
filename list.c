#include "list.h"
#include <stdlib.h>

struct node *init(struct door *door) {
  struct node *node = malloc(sizeof(struct node));
  node->door = door;
  node->next = NULL;
  return node;
}

struct node *add_door(struct node *elem, struct door *door) {
  struct node *new = init(door);
  if (elem->next == NULL) {
    elem->next = new;
  } else {
    new->next = elem->next;
    elem->next = new;
  }
  return new;
}

struct node *find_door(int door_id, struct node *root) {
  if (root == NULL) {
    return NULL;
  }
  for (struct node *cur = root; cur->next != NULL; cur = cur->next) {
    if (cur->door->id == door_id) {
      return cur;
    }
  }
  return NULL;
}

struct node *remove_door(struct node *elem, struct node *root) {
  if (root == NULL) {
    return NULL;
  }
  for (struct node *cur = root; cur->next != NULL; cur = cur->next) {
    if (cur->next == elem) {
      cur->next = elem->next;
      free(elem);
      return cur;
    }
  }
  return NULL;
}

void destroy(struct node *root) {
  if (root == NULL) {
    return;
  }
  struct node *next = root->next;
  free(root);
  while (next->next != NULL) {
    struct node *prev = root->next;
    next = next->next;
    free(prev);
    prev = next;
  }
}
