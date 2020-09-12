#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQueue
{
  int front, rear;
  int capacity;
  int *array;
} Que;

struct ArrayQueue *Queue(int size)
{
  struct ArrayQueue *Q = malloc(sizeof(Que));
  Q->capacity = size;
  Q->front = Q->rear = -1;
  Q->array = malloc(Q->capacity * sizeof(int));
  if (!Q->array)
    return NULL;
  return Q;
}

int IsEmptyQueue(Que *pQ)
{
  return (pQ->front == -1);
}

int IsFullQueue(Que *pQ)
{
  return ((pQ->rear + 1) % pQ->capacity == pQ->front);
}

int QueueSize(Que *pQ)
{
  return (pQ->capacity - pQ->front + pQ->rear + 1) % pQ->capacity;
}

void EnQueue(Que *pQ, int data)
{
  if (IsFullQueue(pQ))
    printf("Queue Overflow\n");
  else
  {
    pQ->rear = (pQ->rear + 1) % pQ->capacity;
    pQ->array[pQ->rear] = data;
    if (pQ->front == -1)
      pQ->front = pQ->rear;
    printf("%d is pushed.\n", data);
  }
}

void DeQueue(Que *pQ)
{
  int data = 0;
  if (IsEmptyQueue(pQ))
  {
    printf("Queue is Empty\n");
    return;
  }
  data = pQ->array[pQ->front];
  if (pQ->front == pQ->rear)
    pQ->front = pQ->rear = -1;
  else
    pQ->front = (pQ->front + 1) % pQ->capacity;
  printf("%d is poped.\n", data);
}

void DeleteQueue(Que *pQ)
{
  if (pQ)
  {
    if (pQ->array)
      free(pQ->array);
    free(pQ);
  }
}

int main()
{
  Que *pQueue = Queue(5);

  EnQueue(pQueue, 1);
  EnQueue(pQueue, 2);
  EnQueue(pQueue, 4);
  EnQueue(pQueue, 8);
  EnQueue(pQueue, 16);

  DeQueue(pQueue);
  DeQueue(pQueue);
  DeQueue(pQueue);
  DeQueue(pQueue);
  DeQueue(pQueue);
  DeQueue(pQueue);
  return 0;
}
