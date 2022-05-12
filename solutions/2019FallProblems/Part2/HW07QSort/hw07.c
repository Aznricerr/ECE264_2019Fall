// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1
  FILE *fl = fopen(filename, "r");
  int sum = 0;
  int num = 0;
  if(fl == NULL)
    return -1;

  while(fscanf(fl, "%d", &num) > 0)
  {
    sum++;
  }
  
  return sum;
  // remember to fclose if fopen succeeds
  fclose(fl);
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  FILE *fl = fopen(filename, "r");
  int num = 0;
  int sum = 0;
  int ind = 0;

  if(fl == NULL)
    return false;
  // read integers from the file.
  while(fscanf(fl, "%d", &num) > 0)
  {
    intArr[ind] = num;
    sum++;
    ind++;
  }
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  if(sum != size)
  {
    return false;
  }
  // if everything is fine, fclose and return true
  fclose(fl);
  
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  return (*(int*)p1 - *(int*)p2 );
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  FILE *fl = fopen(filename, "w");

  if(fl == NULL)
    return false;
  // write integers to the file.
  // one integer per line
  for(int i = 0; i < size; i++)
  {
    fprintf(fl, "%d\n", intArr[i]);
  } 

  // fclose and return true
  fclose(fl);
  return true;

}
#endif
