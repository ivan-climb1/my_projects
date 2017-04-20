#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int n;
    do
    {
        printf("Height:");
        n = GetInt();
    }
    while((n >= 24) || (n < 0));
    
    
   for (int row = 0; row < n; row++)
   {
       for (int q = 1; q < (n - row); q++)
       {
          printf(" ");
       }
       for (int w = 0; w < row; w++)
       {
           printf("#");
       }
      printf("##\n");
   }
}