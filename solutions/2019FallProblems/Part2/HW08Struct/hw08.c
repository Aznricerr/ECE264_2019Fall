// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  FILE *fl = fopen(filename, "r");
  Vector vtr;
  int count = 0;
  // You must not use fscanf(, "%d", ) 
  //
  // If fopen fails, return -1
  if(fl == NULL)
    return -1;
  //
  // For the mode of fopen, you may use "r" without b
  //
  while(fread(&vtr, sizeof(Vector), 1, fl) > 0)
  {
    count++;
  }
  return count;
  fclose(fl);
  

}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // read Vectors from the file.
  FILE *fl = fopen(filename, "r");
  int cnt = countVector(filename);
  if(fl == NULL)
    return false;
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  if(cnt != size)
    return false; 
  // if everything is fine, fclose and return true
  //
  fread(vecArr, sizeof(Vector), size, fl);
  return true;
  fclose(fl);

}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  // compare the x attribute first
  const Vector * vec1 = p1;
  const Vector * vec2 = p2;
  // If the first vector's x is less than the second vector's x
  // return -1
  if(vec1->x < vec2->x)
    return -1;
  // If the first vector's x is greater than the second vector's x
  // return 1
  if(vec1->x > vec2->x)
    return 1;
  // If the two vectors' x is the same, compare the y attribute
  if(vec1->x == vec2->x)
  {
    if(vec1->y < vec2->y)
    return -1;
    if(vec1->y > vec2->y)
    return 1;
  }
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  if(vec1->y == vec2->y)
  {
    if(vec1->z < vec2->z)
    return -1;
    if(vec1->z > vec2->z)
    return 1;
  }

  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
  return 0;
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  FILE *fl = fopen(filename, "w");
  if(fl == NULL)
    return false;
  // write the array to file using fwrite
  fwrite(vecArr, sizeof(Vector), size, fl);
  fclose(fl);
  // need to check how many have been written
  // if not all are written, fclose and return false
  if(countVector(filename) != size)
    return false;
  // fclose and return true
  return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
