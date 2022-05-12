// HW17 Maze
//
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fStart(char * maze, int col, int r, int * pMaze, int d);

void printMaze(int *pMaze, int r, int col)
{
  int i = 0;
  for( i = 0; i < (r * col); i++)
  {
    if(pMaze[i] == -10)
    {
      printf("%4d\n",-1);
    }
    else
    {
    printf("%4d", pMaze[i]);
    }
   
  }
}


void traverseArr(int * pMaze, char * maze, int col, int r)
{
  int b = 0;
  int j = 0;
  int i = 0;
  while(j != (col*r))
  {
  while(i != (col * r))
  {
    if(maze[i] == 'b')
    {
      pMaze[i] = -1;
    }
    if(maze[i] == ' ')
    {
      pMaze[i] = col * r + 1;
    if((i - col) > 0)
    {
    if(maze[i - col] == 'x' && maze[i] == ' ')
    {
         b = 1;
      pMaze[i] = pMaze[i -col] + 1;
    }
    }
    if((i - 1) > 0)
    {
    if(maze[i - 1] == 'x' && maze[i] == ' ')
    {
      b = 1;
      if((pMaze[i - 1] +1 ) < pMaze[i])
      {
      pMaze[i] = pMaze[i - 1] + 1;
      }
    }
    }
    if((i + 1) > 0)
    {
    if(maze[i + 1] == 'x' && maze[i] == ' ')
    {
         b = 1;
      if((pMaze[i + 1] + 1) < pMaze[i])
      {
        
      pMaze[i] = pMaze[i + 1] + 1;
      }
    }
    }
    if((i + col) > 0)
    {
    if(maze[i + col] == 'x' && maze[i] == ' ')
    {
         b = 1;
      if((pMaze[i + col] + 1) < pMaze[i])
      {
      pMaze[i] = pMaze[i + col] + 1;
      }
    }
    if(b == 1)
    {
      maze[i] = 'x';
      b = 0;
    }
    }
    }
     if(maze[i] == '\n')
    {
      pMaze[i] = -10;
    }

    i++;
   }
   i = 0;
   j++;
  }
 }


/*void play(int * pMaze, char * maze, int col, int r, int d, int startarray, int startref, int m);

void helper(int * pMaze, char * maze, int col,int r, int *righttoside, int * lefttoside, int startarray, int startref, int d, int m)
{
  
  int endarray = startarray + col;
  if(startarray < 0)
  {
    return;
  }
  if(endarray > r * col)
  {
    return;
  }
  int minindex = -7;
  int * sum;
  sum = malloc(sizeof(int)*col);
  int i;
  int j = 0;
  int c = 0;
  int r;
  int f;
 //this loop finds the entrances in the current r to the left of the start 
  int l;
  for( i = 0; i <= col; i++)
  {
    if(lefttoside[i] == -2)
    {
      break;
    }
    if( m == 1)
    {
    l = lefttoside[i] - col;
    }
    else
    {
      l = lefttoside[i] + col;
    }
    if (maze[l] == 'b' || maze[l] == 'x')
    {
      lefttoside[i] = -3;
    }
    else
    {
      c++;
      if(c ==1)
      {
        f = lefttoside[i];
      }
    }
    if(c == 2)
    {
      sum[j] = abs(f - lefttoside[i])/2;
      j++;
   //   printf("%d\n", sum[j]);
      c = 0;
    }
 //   printf("%d\n", lefttoside[i]);
   }
// this loop redefines righttoside to "cancel" the elements that are not entrances
  for(i = 0; i <= col; i++)
  {
    if(lefttoside[i] == -2)
    {
      break;
    }
    if(lefttoside[i] != -3)
    {
      righttoside[0] = lefttoside[i];
      break;
    }
  }


  // this loop finds the entrances in the current r that leads to the previous r from the right side of the start.
  for( i = 0; i <= col; i++)
  {
    if(righttoside[i] == -2)
    {
      break;
    }
    if(m == 1)
    {
      r = righttoside[i] - col;
    }
    else
    {
    r = righttoside[i] + col;
    }
    if (maze[r] == 'b' ||  maze[r] == 'x')
    {
      righttoside[i] = -3;
    }
    else
    {
      c++;
      if(c ==1)
      {
        f = righttoside[i];
      }
    }
    if(c == 2)
    {
      sum[j] = abs(f - righttoside[i])/2;
  //    printf("%d\n", sum[j]);
      j++;
      c = 0;
    }
  //  printf("%d \n", righttoside[i]);
   }
   
   while(j < col)
   {
     sum[j] = -3;
 //    printf("%d\n", sum[j]);
     j++;
   }
  int *uni;
  uni = malloc(sizeof(int)*col);
  i = col;
  int u = 0;
 //These two loops assigns the right and left to side to a single array 
  while(i >= 0)
  {
    if (lefttoside[i] != -2)
    {
    
    if(lefttoside[i] != -3)
    {
    uni[u] = lefttoside[i];
   // printf("L%d \n", uni[u]);
    u++;
    }
    } 
    i--;
  }
  i = 1;
  while(i <= col)
  {
    if(righttoside[i] == -2)
    {
      break;
    }
    if(righttoside[i] != -3)
    {
    uni[u] = righttoside[i];
   // printf("r%d \n", uni[u]);
    u++;
    
    }
    i++;
  }
  // end of combination  here
  int b = 0; 
  for( i = 0; i < u; i++)
  {
    if(uni[i] != 0)
    {
      b = 1;
    }
  }
  //if (b != 1 && m == 0)
  {
    if(l != -2)
    {
      minindex = l - col;
    }
    else
    {
      minindex = r - col;
    }
      maze[minindex] = 's';
      
      fStart(maze, col, r, pMaze,d);
  }  
//
  // This part is for the recursive loop part
  int redo = d;
  
  int temp;
  if(startarray > 0)
  {
    helper(pMaze, maze, col, r, righttoside, lefttoside, startarray - col,startref, d, 1);
  }
  for( b = 0; b < col; b++)
  {
  for (i = 0; i <= u; i++)
  {
    if(uni[i] != 0)
    {
      
      if(m ==1)
      {
      minindex = uni[i] - col;
      }
      else
      {
        minindex = uni[i] + col;
      }
      maze[minindex] = 'x';
      pMaze[minindex] = abs(startref - minindex + startarray)+ 1 + d;
      
      d = pMaze[minindex];
 //     printf("u%d\n", d);
     
      play(pMaze, maze, col, r, d, startarray, minindex - startarray, m); // <- This line is what is causing a seg fault. Most important to fix.
     
      temp = minindex + sum[i] + col;
      
      if(sum[i] != -3 && sum[i] != 0);
      {
      for(j =  temp - startarray; j < col - 1; j++)
      {
        if(maze[temp] != 'b' && maze[temp] != '\n')
        {
          maze[temp] = ' ';
        }
        temp++;
      }
      }
      }
      d = redo;
  }
}
if(m == 1 && (startarray + col) > (r * col))
{ 
     helper(pMaze, maze, col, r, righttoside, lefttoside, startarray + col,startref, d,0 );
  }
    else
    {
      helper(pMaze, maze, col, r, righttoside, lefttoside, startarray - col,startref, d, m);
    }


  return;
}
    

  
  
void play(int * pMaze, char * maze, int col, int r, int d, int startarray, int startref, int m)
{
 //This function traverse from left to right by the starting point. 
  int * righttoside;
  int * lefttoside;
  lefttoside = malloc(sizeof(int)*col);
  righttoside = malloc(sizeof(int)*col);
  int r = 0;
  int l = 0;
  righttoside[r] = startref + startarray;
  lefttoside[l] = startref + startarray;
  r++;
  l++;
  int right = d;
  int left = d;
  int j = startarray + 1;
  
 for (int i = 0; i < col; i++)
   {
     while (maze[j] != '\n')
     {
       if(maze[j+1] == 'x' && maze[j] != 'b' && maze[j] != 'x')
       {
         maze[j] =  'x';
         pMaze[j] = ++left;
         lefttoside[l] = j ;
         l++;
       }
       if(maze[j-1] == 'x' && maze[j] != 'b' && maze[j] != 'x')
       {
         maze[j] = 'x';
         pMaze[j] = ++right;
         righttoside[r] = j;
         r++;
  //       printf("%d \n", righttoside[r]);
       }
       j++;
       
     }
     j = startarray + 1;
   }
   r = 0;
   l = 0;
   while(r < col)
   {
     if (righttoside[r] == 0)
     {
     righttoside[r] = -2;
     
     }
    // printf("%d \n", righttoside[r]);
     r++;
   }
   while(l < col)
   {
     if(lefttoside[l] == 0)
     {
     lefttoside[l] = -2;
     }
    // printf("left%d \n", lefttoside[l]);
     l++;
   }
   for( j = 0; j < col; j++)
   {
    if((startarray - col) < 0)
    {
      m = 0;
    }
 //   if ((startarray + col + col) >= ( r * col - 1))
   // {
  //    m = 1;
  //  }
    if (m == 1)
    {
     helper(pMaze, maze, col, r, righttoside, lefttoside, startarray - col,startref, d, m);
     }
     else
     {
       helper(pMaze, maze, col, r, righttoside, lefttoside, startarray + col,startref, d, m);
     }
     m = 1;
    } 
     
   return;
}
*/
void fStart(char * maze, int col, int r, int * pMaze, int d)
{
  int start;
  int endstart;
  int i;
  for(i = 0; i < (col * r);i++)
  {
   if (maze[i] == 's') 
   {
     maze[i] = 'x';
     pMaze[i] = d;
     start = i;
     while( maze[i] != '\n')
     {
      i++;
     }
     endstart = i;
     break;
   }
   
  }

 // int startarray = i - col;
  
 // play (pMaze, maze, col, r,d , startarray, start - startarray, 1);
}
     




int main ( int argc, char * * argv)
{
  FILE * fh;
  if ( argc < 2)
  {
    return EXIT_FAILURE;
  }
 
  fh = fopen( argv[1], "r");
  if ( fh == NULL)
  {
    return EXIT_FAILURE;
  }
  int len, col, r;
  col = 0;
  r = 0;
  int i = 0;
  char c;
  char *Imaze;
  int *pMaze;

  do {
    c = fgetc(fh);
    
    col++;
    if ( c == '\n')
    {
      len = col;
      col = 0;
      r++;
    }

    if ( feof(fh)){
      
      break;
    }
    }while(1);
    col = len;
    Imaze = malloc(sizeof(char)* col *r);
    rewind(fh);
    do {
    c = fgetc(fh);
    Imaze[i] = c;
    i++;
    
    if ( feof(fh)){
      
      break;
    }
    }while(1);


  pMaze = malloc(sizeof(int) *len * r); 
  fStart( Imaze, col, r, pMaze, 0);
  traverseArr(pMaze,Imaze, col, r);
  printMaze(pMaze, r, col);
 /* for(i = 0; i < (col*r); i++)
  {
    printf("%c", Imaze[i]);
  }
 */ 
 fclose(fh);
 return 0; 
}
