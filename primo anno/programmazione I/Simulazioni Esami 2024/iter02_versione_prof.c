#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool selezionata(const size_t rows, const size_t cols, 
	   			 const int mat[rows][cols], const size_t rags[rows],
	   			 const size_t r, int *sum)
{
	bool esiste = false;
	*sum = 0;
	for (size_t c=0; c<rags[r]; c++) {
		if (mat[r][c] % 3==0) {
			int prod = 1;
			for (size_t r2=0; r2<rows; r2++) {
				if (c < rags[r2])
					prod *= mat[r2][c];
			}
			esiste = true;
			*sum += prod;
		}
	}
	return esiste && (*sum%10)==0;
}

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    int *pMinSumProd) 
{
	int count_sel = 0, v;
	*pMinSumProd = INT_MAX;
	for (size_t r=0; r<rows; r++) {
		if (selezionata(rows, cols, mat, rags, r, &v)) {
		  //  printf("%zu sel, v=%d\n", r, v);
			count_sel++;
			if (v < *pMinSumProd)
				*pMinSumProd = v;
		}
	}
	return count_sel >= 2;
}