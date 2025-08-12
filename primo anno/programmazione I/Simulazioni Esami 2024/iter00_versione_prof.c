#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows]) 
{
	bool tutti = true;
	int somma = 0;
	for (size_t r=0; r<rows && tutti; r++) {
		tutti = (rags[r] >= rows);
		if (tutti) {
			bool esiste = false;
			for (size_t c=0; c<rags[r] && !esiste; c++) {
				if (mat[r][c] % 7 == 0) {
					esiste = true;
					somma += mat[r][c];
				}
			}
			if (!esiste)
				tutti = false;
		}
	}
	return (tutti ? somma : 0);
}