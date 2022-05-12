// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  FILE *fl = fopen(filename,"r");
  *sum = 0;
  if(fl == NULL)
    return false;

  int num = 0;
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  while(fscanf(fl, "%d", &num) > 0)
  {
    *sum += num;
  }
  
  fclose(fl);

  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //
  FILE *fl = fopen(filename, "w");
  
  if(fl == NULL)
    return false;

  fprintf(fl, "%d\n", sum);
  
  fclose(fl);
  return true;
}
#endif
