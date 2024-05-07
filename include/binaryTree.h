#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "studant.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node *BINTREE;

BINTREE *newBinTree();

void freeBinTree(BINTREE *tree);

void inOrder(BINTREE *root);
void preOrder(BINTREE *root);
void postOrder(BINTREE *root);
int insertInTree(BINTREE *root, STUDANT st);
int removeElement(BINTREE *root, int id);

STUDANT queryByID(BINTREE *root, int id);

#endif
