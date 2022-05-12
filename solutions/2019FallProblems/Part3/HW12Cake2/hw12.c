// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw12.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createList(int valn)
{
  ListNode* list_head = NULL;  // start of list
  ListNode* list_tail = NULL;  // end of list
  
  for(int i = 0; i < valn; i++)
  {
     // Creating first node
     if(i == 0)
     {
        list_head = list_tail = malloc(sizeof(ListNode));
        list_head -> value = i;
        list_tail -> next = NULL;
     }
     // Creating other nodes
     else
     {
        list_tail -> next = malloc(sizeof(ListNode)); 
        list_tail = list_tail -> next; 
        list_tail -> value = i;
        list_tail -> next = NULL;
     }
  }
  return list_head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  /*ListNode * todelete = malloc(sizeof(ListNode));
  todelete = head;
  if(todelete == NULL)
    return;
     
  int n = 6;
  int i = 1;
  //head = deleteNode(head, todelete);
  printListNode(head);
  while(n > 1)
  {
    for(i = 0;i < valk;i++)
    {
      if(todelete -> next == NULL)
      {
        todelete = head;
      }
      todelete = todelete -> next;
    }
    head = deleteNode(head, todelete);
    printListNode(todelete);
    printf("%d", todelete -> value);
    printf("\n");
    n--;
  }*/

  ListNode * p;
  p = head;
  while(head->next != NULL)
  {
    for(int i = 1; i < valk; i++)
    {
      p = p -> next;
      if(p == NULL)
      {
        p = head;
      }
    }
    ListNode * todelete = p;
#ifdef DEBUG
  // this #ifdef ... #endif should be inside the condition *BEFORE* a
  // node' value is printed and it is deleted
  printListNode(todelete);
#endif
    printf("%d\n", p-> value);
    p = p -> next;
    if(p == NULL)
    {
      p = head;
    }
    head = deleteNode(head, todelete);
  }
  printf("%d\n", head -> value);
  free(head);
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  // Store head node 
  ListNode * temp = head;
  ListNode * prev = NULL;
  ListNode * hold = head; 
  
  
  if (temp != NULL && temp == todelete) 
  { 
      head = temp -> next;   // Changed head 
      free(hold);               // free old head 
      return head; 
  } 
  
  prev = malloc(sizeof(ListNode));
  // Search for the key to be deleted, keep track of the 
  // previous node as we need to change 'prev->next' 
  while (temp != NULL && temp != todelete) 
  { 
      prev = temp; 
      temp = temp->next; 
  }

  // If key was not present in linked list 
  if (temp == NULL) 
    return head; 
  
  // Unlink the node from linked list 
  prev -> next = temp -> next; 
  
  free(temp);  // Free memory 

  return head;
}
#endif


