#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
    // COMPLETARE
    bool funzione = false ;
    int somma = 0;
    for(size_t i = 0 ; i < rows ; i++){
        int prodotto=0;
        size_t minLen;
		 // Determina la lunghezza minima tra la riga e l'array a
          if (rags[i] < aLen) {
            minLen = rags[i];
        } else {
            minLen = aLen;
        }
		// Calcola il prodotto riga-array
        for(size_t k = 0 ; k < minLen ; k++){
                
            prodotto += mat[i][k]*a[k];
        }
        if(prodotto > 0 && prodotto % 5 == 0){
            funzione = true;
            somma+=prodotto;
        }
    }
 
    *pSum = somma;
    return funzione ;
}