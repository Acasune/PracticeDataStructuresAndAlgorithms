#include <stdio.h>
#include <stdlib.h>

typedef struct AVLTreeNode
{
  int data;
  int height;
  struct AVLTreeNode *Left;
  struct AVLTreeNode *Right;
} AVLTN;

int getHeight(AVLTN *pRoot)
{
  if (!pRoot)
    return -1;
  else
    return pRoot->height;
}

AVLTN *SingleRotateLeft(AVLTN *X)
{
  AVLTN *W = X->Left;
  W->Right = X;
  X->height = max(getHeight(X->Left), getHeight(X->Right)) + 1;
  W->height = max(getHeight(W->Left), X->height) + 1;
  return W;
}

AVLTN *SingleRotateRight(AVLTN *W)
{
  AVLTN *X = W->Right;
  W->Right = X->Left;
  X->Left = W;
  X->height = max(getHeight(X->Right), getHeight(X->Left)) + 1;
  W->height = max(getHeight(W->Left), X->height) + 1;
  return W;
}
