// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
  FILE *fl = fopen(filename, "r");

  if(fl == NULL)
  {
    return false;
  }
  if(arithlist == NULL)
  {
    return false;
  }

  char *hold = malloc(sizeof(char) * WORDLENGTH);
  memset(hold, '\0', sizeof(char) * WORDLENGTH);

  while(fgets(hold, WORDLENGTH, fl) != NULL)
  {
    if(hold[WORDLENGTH-1] != '\n' && hold[WORDLENGTH-1] != '\0')
    {
      deleteList(arithlist);
      fclose(fl);
      return false;
    }
    addNode(arithlist, hold);
  }
  
  free(fl);
  free(hold);

  return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{
  ListNode * temp = arithlist -> head;
  ListNode * rtemp = NULL;
  if(arithlist == NULL)
  {
    return;
  }
  while(temp != NULL)
  {
    rtemp = temp;
    temp = temp -> next;
    free(rtemp);
  }
  (arithlist -> head) = NULL;
  
  free(arithlist);
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
  ListNode * temp = malloc(sizeof(ListNode));

  strcpy(temp -> word, word);
  temp -> next = NULL;
  temp -> prev = NULL;

  if(arithlist -> head == NULL)
  {
    arithlist -> head = temp;
    arithlist -> tail = temp;
  }
  else
  {
    arithlist -> tail -> next = temp;
    temp -> prev = arithlist -> tail;
    arithlist -> tail = temp;
  }
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
  /*ListNode * temp = arithlist -> head;
  ListNode * hold = arithlist -> tail;
  
  if(arithlist == NULL)
  {
    return false;
  }
  if(ln == NULL)
  {
    return false;
  } 
 
  if(ln == temp)
  {
    // Remove first element in the list
    temp = ln->next;
    temp -> prev = NULL;
  }
  else if (ln == hold)
  {
    // Remove last element in list
    hold = ln->prev;
    hold -> next = NULL;
  }
  else
  {
    // Skip over this element in the list
    ln -> prev -> next = ln -> next;
    ln -> next -> prev = ln -> prev;
  } 

  free(ln);
  return true;
  */
  if(arithlist == NULL)
  {
    return false;
  }
  if(ln == NULL)
  {
    return false;
  } 

  if(ln == arithlist->head)
  {
    arithlist->head = ln->next;
    arithlist->head->prev = NULL;
  }
  else if (ln==arithlist->tail)
  {
    arithlist->tail = ln->prev;
    arithlist->tail->next = NULL;
  }
  else
  {
    ln->prev->next = ln->next;
    ln->next->prev = ln->prev;
  }
  free(ln);

  return true;
}
#endif

