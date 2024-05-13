#include "binaryTree.h"
#include "studant.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  STUDANT data;
  struct node *left;
  struct node *right;
};

BINTREE *newBinTree() {
  BINTREE *root = (BINTREE *)malloc(sizeof(BINTREE));
  if (root != NULL) {
    *root = NULL;
  }
  return root;
}

static BINTREE removeActual(BINTREE actual) {
  BINTREE node1, node2;

  if (actual->left == NULL) {
    node2 = actual->right;
    free(actual->data);
    free(actual);
    return node2;
  }
  node1 = actual;
  node2 = actual->left;
  while (node2->right != NULL) {
    node1 = node2;
    node2 = node2->right;
  }
  if (node1 != actual) {
    node1->right = node2->left;
    node2->left = actual->left;
  }
  node2->right = actual->right;
  free(actual->data);
  free(actual);
  return node2;
}

int removeElement(BINTREE *root, int id) {
  if (root == NULL)
    return 0;

  BINTREE prev = NULL;
  BINTREE actual = *root;

  while (actual != NULL) {

    if (id == getID(actual->data)) {
      if (actual == *root) {
        *root = removeActual(actual);
      } else {
        if (prev->right == actual) {
          prev->right = removeActual(actual);
        } else {
          prev->left = removeActual(actual);
        }
      }
      return 1;
    }
    prev = actual;

    if (id > getID(actual->data)) {
      actual = actual->right;
    } else {
      actual = actual->left;
    }
  }
  return 0;
}

static void freeNode(struct node *node) {
  if (node == NULL)
    return;

  freeNode(node->left);
  freeNode(node->right);
  free(node->data);
  free(node);
}

void freeBinTree(BINTREE *tree) {
  if (tree == NULL)
    return;
  freeNode(*tree);
  free(tree);
}

void preOrder(BINTREE *root) {
  if (root == NULL)
    return;

  if (*root != NULL) {
    printf("%d\n\n", getID((*root)->data));
    preOrder(&((*root)->left));
    preOrder(&((*root)->right));
  };
}

void inOrder(BINTREE *root) {
  if (root == NULL)
    return;

  if (*root != NULL) {
    inOrder(&((*root)->left));
    printf("%d\n\n", getID((*root)->data));
    inOrder(&((*root)->right));
  };
}

void postOrder(BINTREE *root) {
  if (root == NULL)
    return;

  if (*root != NULL) {
    postOrder(&((*root)->left));
    postOrder(&((*root)->right));
    printf("%d\n\n", getID((*root)->data));
  };
}

int insertInTree(BINTREE *root, STUDANT st) {
  if (root == NULL)
    return 0;

  BINTREE new = (BINTREE)malloc(sizeof(struct node));

  if (new == NULL)
    return 0;

  new->data = st;
  new->left = NULL;
  new->right = NULL;
  if (*root == NULL) {
    *root = new;
  } else {
    BINTREE actual = *root;
    BINTREE prev = NULL;
    while (actual != NULL) {
      prev = actual;
      if (getID(st) == getID(actual->data)) {
        free(new);
        return 1;
      }
      if (getID(st) > getID(actual->data)) {
        actual = actual->right;
      } else {
        actual = actual->left;
      }
    }
    if (getID(st) > getID(prev->data)) {
      prev->right = new;
    } else {
      prev->left = new;
    }
    return 1;
  }
  return 0;
}

STUDANT queryByID(BINTREE *root, int id) {
  if (root == NULL)
    return 0;

  BINTREE node = *root;
  while (node != NULL) {
    if (id == getID(node->data)) {
      printf("%p\n", node->data);
      return node->data;
    }
    if (id > getID(node->data)) {
      node = node->right;
    } else {
      node = node->left;
    }
  }
  printf("Error: Element not find");
  return 0;
}
