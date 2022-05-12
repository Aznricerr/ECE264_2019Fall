// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"


// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char *word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind++)
  {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
    {
      return ind;
    }
  }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the convert function
// ***
//

void cPrint(List * arithlist)
{
  if (arithlist == NULL)
    {
      return;
    }
  ListNode * ln = arithlist -> head;
  ListNode * p;

  while (ln != NULL)
    {
      p = ln -> next;
      printf("%s", ln -> word); // no need to add '\n'
      ln = p;
    }
}

#ifdef TEST_CONVERT

void handleP(List *opList, List *output);
int getPrecidence(int op, int lastOp);

bool convert(List *arithlist)
{
  if (arithlist == NULL)
  {
    return true;
  }
  if ((arithlist->head) == NULL)
  {
    return true;
  }

  List * opList;
  opList = malloc(sizeof(List));
  opList -> head = NULL;
  opList -> tail = NULL;

  List * out;
  out = malloc(sizeof(List));
  out -> head = NULL;
  out -> tail = NULL;

  ListNode *curNode = arithlist->head;

  while(curNode != NULL)
  {
    int op = isOperator(curNode->word);
    if(op == -1) // Char found
    {
      addNode(out, curNode->word);
    }
    else
    {
      // Add first operator
      if(opList->head == NULL)
      {
        addNode(opList, curNode->word);
      }
      else
      {      
        if(op == 4) // ) reached, pop until we see (
        {
          handleP(opList, out);
        }
        else
        {
          int lastOp = isOperator(opList->tail->word);

          if (getPrecidence(op, lastOp)) // Higher presidence to add, push to stack
          {
            addNode(opList, curNode->word);
          }
          else
          {
            // Pop last operator to the output
            addNode(out, opList->tail->word);
            deleteNode(opList, opList->tail);
            addNode(opList, curNode->word);
          }
        }

      }
    }
    

    curNode = curNode->next;
  }


  curNode = opList->tail;
  // Empty operator stack
  while(curNode != NULL)
  {
    addNode(out, curNode->word);
    curNode = curNode->prev;
  }

  // Copy over output to arithlist
  deleteList(opList);

  curNode = arithlist->head;
  while(curNode != NULL)
  {
    ListNode *next = curNode->next;
    free(curNode);
    curNode = next;
  }
  arithlist->head = NULL;
  arithlist->tail = NULL;
  
  curNode = out->head;
  while(curNode != NULL)
  {
    addNode(arithlist, curNode->word);
    curNode = curNode -> next;
  }

  deleteList(out);

  return true;
}

int getPrecidence(int op, int lastOp)
{
  if(op == 3 || lastOp == 3)
  {
    return 1;
  }
  if(op == 1 && lastOp == 0)
  {
    return 0;
  }
  return op > lastOp;
}

void handleP(List *opList, List *output)
{
  ListNode *curNode = opList->tail;
  // Loop until a '(' is seen
  while(curNode != NULL && isOperator(curNode->word) != 3)
  {
    // Current node is not a (, add it to the output
    addNode(output, curNode->word);

    // Go to the next node
    ListNode *temp = curNode->prev;
    deleteNode(opList, curNode);
    curNode = temp;
  }
  // Remove last '('
  deleteNode(opList, curNode);
}



#endif
