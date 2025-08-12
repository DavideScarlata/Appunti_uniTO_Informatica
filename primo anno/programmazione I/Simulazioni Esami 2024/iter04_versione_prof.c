#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
	bool tutte_righe = true;
	for (size_t r=0; r<rows; r++) {
		bool aggiunto_elem = false;

		for (size_t c=0; c<rags[r] && rags[r]<cols; c++) {
			if (mat[r][c] > 0 && 0==mat[r][c]%3) {
				mat[r][rags[r]] = mat[r][c]/3;
				rags[r]++;
				aggiunto_elem = true;
			}
		}
		tutte_righe = tutte_righe && aggiunto_elem;
	}
	return tutte_righe;
}