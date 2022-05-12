// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTWORD
int countWord(char * filename, char * word, char * line, int size)
{
  // filename: name of the input file
  // word: the word to search
  // line: temporary space to store what is read from the file
  // size: size of line
  // open a file whose name is filename for reading
  // if fopen fails, return -1. 
  // if fopen succeeds, set sum to zero
  // use fgets to read the file
  // if word appears in a line, add one to sum
  //
  FILE *fl = fopen(filename, "r");
  if(fl == NULL)
    return -1;

  int sum = 0;
  char *p;
  int wordlen = strlen(word);
  while(!feof(fl))
  {
    fgets(line, size, fl);
    for(int i = 0; i < size;)
    {
      p = strstr(&line[i], word);
      if(p)
      {
        i = p - line + wordlen;
        sum++; 
      }
      else
      {
        i = size;
      }
    }
    memset(line, 0, size);
  }
  return sum;
  // It is possible that the same word appears multiple times in a line
  // If this word is split in two or more lines, do not count the word.
  //
  // It is also possible that a long line is split by fgets. If this happens,
  // do not count the word.
  //
  // return sum
  //
  // If a line is "aaaaa" and the word is "aa", how is the count defined?
  // In this assignment, the first two letters are consumed when the
  // the first match occurs. Thus, the next match starts at the third
  // character. For this case, the correct answer is 2, not 4.
  fclose(fl);

  return 0;
}
#endif
