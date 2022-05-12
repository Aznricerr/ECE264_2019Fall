#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void divide(CardDeck origDeck, CardDeck* leftDeck, CardDeck* rightDeck);
void interleave(CardDeck leftDeck, CardDeck rightDeck, int round);
void removed(CardDeck leftDeck, CardDeck rightDeck, CardDeck dropped, int round);
CardDeck rm1(CardDeck *deck, CardDeck dropped);

static void printDeck(CardDeck tDeck)
{
  int ind;
  for (ind = 0; ind < tDeck.size; ind ++)
    {
      printf("%c ", tDeck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right tDecks
// Each pair divides the original tDeck into two non-overlapping tDecks and
// together they form the original tDeck.
//
// You can think of the left tDeck held by the left hand taking some
// cards (at least one) from the top of the original tDeck.
//
// The right tDeck is held by the right hand taking some (at least one)
// cards from the bottom of the original tDeck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  int s = origDeck.size;
  int g1; //left tDeck
  int g2; //right tDeck
  for(int i = 0; i < s-1; i++)
  {
    g1 = i+1;
    g2 = s-1;
    memcpy(leftDeck[i].cards, origDeck.cards, g1 * sizeof(origDeck.cards[0]));
    leftDeck[i].size = g1;
    memcpy(rightDeck[i].cards, &origDeck.cards[g1], g2 * sizeof(origDeck.cards[0]));
    rightDeck[i].size = g2;
  }
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two tDecks to generate all possible results.
//
// If the leftDeck is {'A'} and the right tDeck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right tDeck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left tDeck, the left tDeck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left tDeck or the right tDeck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removedd for grading other parts of the
// program.
void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
  CardDeck last =
  {
    .size = 0,
    .cards = {0}
  };
  removed(leftDeck, rightDeck, last, round);
}

void removed(CardDeck leftDeck, CardDeck rightDeck, CardDeck last,int round)
{
  if (leftDeck.size == 0)
  {
    for(;rightDeck.size > 0;)
    {
      last = rm1(&rightDeck, last);
    }
    shuffle(last, round - 1);    
    printDeck(last);
    return;
  }
  else if (rightDeck.size == 0)
  {
    for(;leftDeck.size > 0;) 
    {
      last = rm1(&leftDeck, last); 
    }
    shuffle(last, round - 1);
    printDeck(last);
    return;
  }
  else
  {
    CardDeck rLeft, rRight;
    memcpy(&rLeft, &leftDeck, sizeof(CardDeck));
    memcpy(&rRight, &rightDeck, sizeof(CardDeck));
    CardDeck dropLeft = rm1(&rLeft, last);
    CardDeck dropRight = rm1(&rRight, last);
    removed(rLeft, rightDeck, dropLeft, round);
    removed(leftDeck, rRight, dropRight, round);
  }
}

CardDeck rm1(CardDeck *tDeck, CardDeck rDeck)
{
  tDeck->size -= 1;
  memcpy(&rDeck.cards[rDeck.size++], &tDeck->cards[0], sizeof(tDeck->cards[0]));
  memcpy(&tDeck->cards[0], &tDeck->cards[1], tDeck->size * sizeof(tDeck->cards[0]));
  return rDeck;
}

#endif

void shuffle(CardDeck origDeck, int round)
{
  int size = origDeck.size - 1;

  CardDeck *lDecks = malloc(size * sizeof(CardDeck));
  CardDeck *rDecks = malloc(size * sizeof(CardDeck));
  divide(origDeck, lDecks, rDecks);
  
  int i = 0;
  while(i < size)
  {
    interleave(lDecks[i],rDecks[i],round);
    i++;
  }
  
  free(lDecks);
  free(rDecks);
}

