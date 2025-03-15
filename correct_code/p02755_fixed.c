#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(type, a, b)                                                       \
  {                                                                            \
    type tmp = a;                                                              \
    a = b;                                                                     \
    b = tmp;                                                                   \
  }
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

typedef struct LISTNODE {
  int data;
  struct LISTNODE *pNext;
  struct LISTNODE *pPrev;
} ListNode;

ListNode rootNode;

ListNode *getNode(int n);
int getListLength();
void addNode(int n, int val);
void deleteNode(int n);
void swapNode(int n1, int n2);
void sortList();
void showList(int n); // If n>0,you can see n-th Node in the List.Otherwise,you
                      // can see whole list.
void freeList();

int main() {
  rootNode.data = 0;
  rootNode.pNext = rootNode.pPrev = &rootNode;

  double a, b, xMin, xMax;
  scanf("%lf %lf", &a, &b);
  if ((b + 1) / 0.1 <= a / 0.08 || (a + 1) / 0.08 <= b / 0.1) {
    printf("%d", -1);
    return 0;
  }
  xMin = MAX(a / 0.08, b / 0.1);
  xMax = MIN((a + 1) / 0.08, (b + 1) / 0.1);
  if (xMin - (int)xMin == 0)
    printf("%d", (int)xMin);
  // else if ((int)xMin == (int)xMax)
  //     printf("%d", -1);
  else {
    printf("%d", (int)xMin + 1);
  }

  return 0;
}

ListNode *getNode(int n) {
  int i;
  ListNode *pNode = &rootNode;
  for (i = 0; i < n; i++, pNode = pNode->pNext)
    ;
  return pNode;
}

int getListLength() {
  int i;
  ListNode *pNode = rootNode.pNext;
  for (i = 0; pNode != &rootNode; pNode = pNode->pNext, i++)
    ;
  return i;
}

void addNode(int n, int val) {
  ListNode *pPrevNode = getNode(n - 1);
  ListNode *pNewNode = (ListNode *)malloc(sizeof(ListNode));
  pNewNode->data = val;
  pNewNode->pNext = pPrevNode->pNext;
  pPrevNode->pNext = pNewNode;
  (pNewNode->pNext)->pPrev = pNewNode;
  pNewNode->pPrev = pPrevNode;
}

void deleteNode(int n) {
  ListNode *pNode = getNode(n);
  (pNode->pPrev)->pNext = pNode->pNext;
  (pNode->pNext)->pPrev = pNode->pPrev;
  free(pNode);
}

void swapNode(int n1, int n2) {
  if (n1 > n2)
    SWAP(int, n1, n2)
  ListNode *pNode1 = getNode(n1), *pNode2 = getNode(n2);

  if (n2 - n1 == 1) {
    pNode1->pNext = pNode2->pNext;
    pNode2->pPrev = pNode1->pPrev;
    (pNode2->pPrev)->pNext = pNode2;
    (pNode1->pNext)->pPrev = pNode1;
    pNode2->pNext = pNode1;
    pNode1->pPrev = pNode2;
  } else if (n1 != n2) {
    ListNode *pNextNode1 = pNode1->pNext, *pPrevNode2 = pNode2->pPrev;
    pNode1->pNext = pNode2->pNext;
    pNode2->pPrev = pNode1->pPrev;
    (pNode1->pPrev)->pNext = pNode2;
    (pNode2->pNext)->pPrev = pNode1;
    pNode1->pPrev = pPrevNode2;
    pPrevNode2->pNext = pNode1;
    pNode2->pNext = pNextNode1;
    pNextNode1->pPrev = pNode2;
  }
}

void sortList() {
  int i, j, n = getListLength();
  ListNode *pNode;
  for (i = 0; i < n - 1; i++) {
    for (j = 1; j < n - i; j++) {
      pNode = getNode(j);
      if ((pNode->data) > ((pNode->pNext)->data))
        swapNode(j, j + 1);
    }
  }
}

void freeList() {
  ListNode *pFreeNode, *pTmpNode = rootNode.pNext;
  while (pTmpNode != &rootNode) {
    pFreeNode = pTmpNode;
    pTmpNode = pTmpNode->pNext;
    free(pFreeNode);
  }
}

void showList(int n) // If n>0,you can see n-th Node in the List.Otherwise,you
                     // can see whole list.
{
  ListNode *pNode;
  if (n > 0) {
    pNode = getNode(n);
    printf("%d", pNode->data);
  } else {
    for (pNode = rootNode.pNext; pNode != &rootNode; pNode = pNode->pNext) {
      printf("%d\n", pNode->data);
    }
  }
}