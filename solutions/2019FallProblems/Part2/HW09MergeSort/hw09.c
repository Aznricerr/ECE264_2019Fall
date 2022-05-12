// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  FILE *fl = fopen(filename, "r");
  if(fl == NULL)
    return false;


  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  if(!fseek(fl, 0, SEEK_END))
  {
    fclose(fl);
    return false;
  }


  // use ftell to determine the size of the file
  int fsize = ftell(fl);


  
  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  if(!fseek(fl, 0, SEEK_SET))
    return false;


  
  // if fseek fails, fclose and return false



  // the number of integers is the file's size divided by
  // size of int  
  
  int tmp_size = fsize/sizeof(int);


  

  // allocate memory for the array
  int *tmp_arr;
  

  tmp_arr = malloc(fsize);
 

  // if malloc fails, fclose and return false
  if(tmp_arr == NULL)
    return false;


  // use fread to read the number of integers in the file
  int num = fread(tmp_arr, sizeof(int), tmp_size, fl);



  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
  if(num != tmp_size)
  {
    free(fl);
    fclose(fl);
    return false;
  }



  
  // if fread succeeds
  // close the file
  fclose(fl);
  
  // update the argument for the array address
  *arr = tmp_arr;

  
  // update the size of the array
  *size = tmp_size;
  
  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  FILE *fl = fopen(filename, "w");


  // if fopen fails, return false
  if(fl == NULL)
    return false;

  // use fwrite to write the entire array to a file
  int w_size = fwrite(arr, sizeof(int), size, fl);


  // check whether all elements of the array have been written
  if(w_size != size)
  {
    fclose(fl);
    return false;
  }


  // fclose
  fclose(fl);
  
  
  // if not all elements have been written, return false



  // if all elements have been written, return true
  return true;




}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif

  // if one or both of the arrays are empty, do nothing





  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write




  // merge the two parts (each part is already sorted) of the array
  // into one sorted array

  int arr_size = (r - l + 1) * sizeof(int);
  int* sort = malloc(arr_size);

  if(!sort)
    return;
  
  int i = l;
  int j = m+1;
  int k = 0;

  for(;i <= m && j <=r;)
  {
    if(arr[i] <= arr[j])
    {
      sort[k++] = arr[i++];
    }
    else
    {
      sort[k++] = arr[j++];
    }
  } 

  for(;j <= r;)
  {
    sort[k++] = arr[i++];
  }
  
  for(;j <= r;)
  {
    sort[k++] = arr[j++];
  }
  
  for(int p = 0; p <= r; p++)
  {
    arr[p] = sort[p-1];
  } 
  
  free(sort);
  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif

  // if the array has no or one element, do nothing
  if(r < 2)
    return;


  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
  int h = (r + 1) / 2;
 
  mergeSort(arr, 1, h);
  mergeSort(arr, h + 1, r);
  merge(arr, 1, h, r);




} 
#endif
