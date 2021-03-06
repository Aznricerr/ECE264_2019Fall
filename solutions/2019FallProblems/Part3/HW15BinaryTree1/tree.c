// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
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

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

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


TreeNode * buildUtil(int * inArray, int * postArray, int inStrt, int inEnd, int * pIndex)
{
  if ( inStrt > inEnd)
	return NULL;
  
  TreeNode * node = newNode(postArray[*pIndex]);
  (*pIndex) --;

  
  if (inStrt == inEnd)
	return node;

   int iIndex = search(inArray, inStrt, inEnd, node -> value);
   
   node -> right = buildUtil (inArray, postArray, iIndex + 1, inEnd, pIndex);
   node -> left = buildUtil ( inArray, postArray, inStrt, iIndex -1, pIndex);

   return node;
}
Tree * buildTree(int * inArray, int * postArray, int size)
{
 int pIndex = size -1;
 Tree * built = malloc(sizeof(Tree));
 built -> root = buildUtil(inArray, postArray, 0, size - 1, &pIndex);
 return built;
}
#endif
