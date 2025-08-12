#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
     const int mat[rows][cols], const size_t rags[rows],
     const int k, int *pMaxSum) 
{
 bool tutti = true;
 bool esiste_riga = false;
 *pMaxSum = INT_MIN;
 for (size_t r=0; r<rows && tutti; r++) {
  if (rags[r] > 0) {
   int sum = 0;
   for (size_t c=0; c<rags[r]; c++) {
    sum += mat[r][c];
   }
   //printf("%d %d\n", sum, (sum % k)==0);
   tutti = (sum % k)==0;
   if (tutti)
       esiste_riga = true;
   if (*pMaxSum < sum)
    *pMaxSum = sum;
  }
 }
 return tutti && esiste_riga;
}