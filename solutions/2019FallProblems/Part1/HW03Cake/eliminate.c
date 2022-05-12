// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  // j variable keeps track of counting
  for(int i = 0; i < n; i++)
  {
    arr[i] = i;
  } 
  int index = 0; //keeps track of index of the array
  int numleft = n;

  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  while(numleft > 1)
  {
     for(int j = 0; j < k;)
     {
       if(arr[index] != -1)
       {
         j++;
       }
       if(j == k)
       {
         arr[index] = -1;
         printf("%d\n", index);
         numleft--;
       }
       
         index++;
         index = index % n;
       
     }
   }
  //print last num
  for(int s = 0; s < n; s++)
  {
   if(arr[s] != -1)
     index = s;
  }
  printf("%d\n", index); 




  // release the memory of the array
  free (arr);
}
#endif
