#include <stdio.h>
#include <stdbool.h>

int prod_riga_array(const size_t aLen, const int a[aLen],
					const size_t bLen, const int b[aLen])
{
	size_t minLen = (aLen < bLen) ? aLen : bLen;
	int sum_prod = 0;
	for (size_t i=0; i<minLen; i++)
		sum_prod += a[i] * b[i];
	return sum_prod;
}

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
	bool esiste = false;
	*pSum = 0;
	for (size_t r=0; r<rows; r++) {
		int sum_prod = prod_riga_array(aLen, a, rags[r], mat[r]);
		if (sum_prod>0 && sum_prod % 5 == 0) {
			esiste = true;
			*pSum += sum_prod;
		}
	}
	return esiste;
}