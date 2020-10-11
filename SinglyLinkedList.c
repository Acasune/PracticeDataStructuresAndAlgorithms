#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
  int data;
  struct ListNode *next;
} NODE, *Nodep;

void InsertInLinkedList(struct ListNode **head, int data, int position)
{
  int k = 0;
  struct ListNode *p, *q, *newNode;
  newNode = (Nodep)malloc(sizeof(NODE));
  if (!newNode)
  {
    printf("Memory Error");
    return;
  }
  newNode->data = data;
  p = *head;
  // Insert at head;
  if (position == 0)
  {
    newNode->next = p;
    *head = newNode;
    return;
  }
  // traverse all elements of the list
  while ((p != NULL) && (k < position))
  {
    k++;
    q = p;
    p = p->next;
  }
  q->next = newNode;
  newNode->next = p;
};

void DeleteNodeFromLinkedList(struct ListNode **head, int position)
{
  int k = 0;
  struct ListNode *p, *q;
  if (head == NULL)
  {
    printf("List Empty");
    return;
  }
  p = *head;
  if (position == 0)
  {
    *head = (*head)->next;
    free(p);
    return;
  }
  while ((p != NULL) && (k < position))
  {
    k++;
    q = p;
    p = p->next;
  }
  if (p == NULL)
    printf("Position does not exist.");
  else
  {
    q->next = p->next;
    free(p);
  }
}

void displist(Nodep fp);

Nodep first_p;

int main()
{
  first_p = (Nodep)malloc(sizeof(NODE));
  first_p->data = 1;
  first_p->next = (Nodep)malloc(sizeof(NODE));
  first_p->next->data = 5;
  first_p->next->next = (Nodep)malloc(sizeof(NODE));
  first_p->next->next->data = 9;
  first_p->next->next->next = NULL;

  printf("---Initial State---\n");
  displist(first_p);

  printf("---Add Some Values---\n");
  InsertInLinkedList(&first_p, 3, 3);
  InsertInLinkedList(&first_p, 10, 2);
  InsertInLinkedList(&first_p, 100, 1);
  InsertInLinkedList(&first_p, 1000, 0);
  displist(first_p);

  printf("---Delete 3rd and Initial Values---\n");
  DeleteNodeFromLinkedList(&first_p, 2);
  DeleteNodeFromLinkedList(&first_p, 0);
  displist(first_p);
}

void displist(Nodep fp)
{
  printf("List");
  if (fp == NULL)
  {
    printf(" is empty\n");
    return;
  }
  for (; fp != NULL; fp = fp->next)
  {
    printf("%5d", fp->data);
  }
  printf("\n");
};
