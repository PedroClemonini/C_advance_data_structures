#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "studant.h"

int main(void){

BINTREE *root;
STUDANT st,stfind;

root = newBinTree();

st = newStudant();
addData(st,100,"Pedro",7.8);
insertInTree(root,st);


st = newStudant();
addData(st,110,"Joao",8.5);
insertInTree(root,st);

removeElement(root,110);
postOrder(root);



return 0;
}
