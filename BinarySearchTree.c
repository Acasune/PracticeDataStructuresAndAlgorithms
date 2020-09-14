#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTreeNode
{
  int data;
  struct BinarySearchTreeNode *Left;
  struct BinarySearchTreeNode *Right;
} BSTN;

struct BinarySearchTreeNode *find(BSTN *pRoot, int data)
{
  if (pRoot == NULL)
    return NULL;
  if (data < pRoot->data)
    return find(pRoot->Left, data);
  if (data > pRoot->data)
    return find(pRoot->Right, data);
  return pRoot;
};

struct BinarySearchTreeNode *findMin(BSTN *pRoot)
{
  if (pRoot == NULL)
    return NULL;
  if (pRoot->Left == NULL)
    return pRoot;
  else
    return findMin(pRoot->Left);
};

struct BinarySearchTreeNode *findMax(BSTN *pRoot)
{
  if (pRoot == NULL)
    return NULL;
  if (pRoot->Right == NULL)
    return pRoot;
  else
    return findMax(pRoot->Right);
};

struct BinarySearchTreeNode *insert(BSTN *pRoot, int data)
{
  if (pRoot == NULL)
  {
    pRoot = (BSTN *)malloc(sizeof(BSTN));
    if (pRoot == NULL)
    {
      printf("Memory Error");
      return NULL;
    }
    else
    {
      pRoot->data = data;
      pRoot->Left = pRoot->Right = NULL;
    }
  }
  else
  {
    if (data <= pRoot->data)
    {
      pRoot->Left = insert(pRoot->Left, data);
    }

    if (data > pRoot->data)
    {
      pRoot->Right = insert(pRoot->Right, data);
    }
  }
  return pRoot;
}

struct BinarySearchTreeNode *delete (BSTN *pRoot, int data)
{
  BSTN *tmp = pRoot;
  if (pRoot == NULL)
  {
    printf("data is not found.\n");
    return NULL;
  }
  else if (data < pRoot->data)
  {
    pRoot->Left = delete (pRoot->Left, data);
  }
  else if (data > pRoot->data)
  {
    pRoot->Right = delete (pRoot->Right, data);
  }
  else
  {
    if (pRoot->Left && pRoot->Right)
    {
      tmp = findMax(pRoot->Left);
      pRoot->data = tmp->data;
      pRoot->Left = delete (pRoot->Left, tmp->data);
    }
    else
    {
      tmp = pRoot;
      if (pRoot->Right == NULL)
      {
        BSTN *temp = pRoot->Left;
        free(pRoot);
        return temp;
      }
      if (pRoot->Left == NULL)
      {
        BSTN *temp = pRoot->Right;
        free(pRoot);
        return temp;
      }
    }
    // free(tmp);
  }

  return pRoot;
}

void display(BSTN *pRoot)
{
  if (pRoot == NULL)
    return;
  if (pRoot->Left)
  {
    display(pRoot->Left);
  }
  printf("%d\t", pRoot->data);
  if (pRoot->Right)
  {
    display(pRoot->Right);
  }
}

int main()
{
  BSTN *pRoot = insert(NULL, 8);
  insert(pRoot, 4);
  insert(pRoot, 2);
  insert(pRoot, 16);
  insert(pRoot, 32);
  display(pRoot);
  printf("\n");
  delete (pRoot, 4);
  delete (pRoot, 16);
  display(pRoot);
  printf("\n");

  return 0;
}
