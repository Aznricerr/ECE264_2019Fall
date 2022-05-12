// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
  {
    return;
  }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
  {
    // nothing to delete
    return;
  }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE

TreeNode * newNode(int data)
{
  TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode));
  node -> value = data;
  node -> left = node -> right = NULL;
  return(node);
}

int search ( int * inArray, int inStrt, int inEnd, int value)
{
  int i;
  for (i = inStrt; i <= inEnd; i++)
  {
    if(inArray[i] == value)
      break;
  }
  return i;
}


TreeNode * builttil(int * inArray, int * postArray, int inStrt, int inEnd, int * pIndex)
{
  if ( inStrt > inEnd)
    return NULL;
  
   TreeNode * node = newNode(postArray[*pIndex]);
  (*pIndex) --;

  if (inStrt == inEnd)
    return node;

  int iIndex = search(inArray, inStrt, inEnd, node -> value);

  node -> right = builttil (inArray, postArray, iIndex + 1, inEnd, pIndex);
  node -> left = builttil ( inArray, postArray, inStrt, iIndex -1, pIndex);

  return node;
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
  int pIndex = size - 1;
  Tree *built = malloc(sizeof(Tree));
  built->root = builttil(inArray, postArray, 0, size - 1, &pIndex);
  return built;
}
#endif

#ifdef TEST_PRINTPATH
void printAssist(TreeNode * Node, int * val) {
  if( Node -> left != NULL)
  {
    printAssist(Node -> left, val);
  }
  if( Node -> right != NULL)
  {
    printAssist(Node -> right, val);
  }
  if(Node -> right != NULL)
  {
    if(Node -> right -> value == *val)
    {
      printf("%d\n", *val);
      *val = Node -> value;
      return;
    }
  }
  if (Node -> left != NULL)
  {
    if(Node -> left -> value == *val)
    {
      printf("%d\n", *val);
      *val = Node -> value;
      return;
    }
  }
  return;   
}

void printPath(Tree * tr, int val)
{
  if (tr -> root -> value == val)
  {
    printf("%d\n", val);
    return;
  }
  int * v = &val;
  printAssist(tr -> root, v);
  printf("%d\n", tr -> root -> value);

  return;
}
#endif
