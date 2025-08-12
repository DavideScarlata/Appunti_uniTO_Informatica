#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols, 
       const int mat[rows][cols], const size_t rags[rows]) 
{
    int somma = 0;
    bool controllo = true;

    for (size_t i = 0; i < rows && controllo; i++) {
        // Controllo che la lunghezza della riga sia almeno `rows`
        if (rags[i] < rows) {
            controllo = false;
        }

        bool multiplo = false;  // Per verificare se esiste un multiplo di 7 nella riga

        for (size_t j = 0; j < rags[i]; j++) {
            if (mat[i][j] % 7 == 0) {
                if (multiplo==false) {
                    somma += mat[i][j];  // Aggiungi il primo multiplo di 7
                    multiplo = true;
                }
            }
        }

        // Se non è stato trovato nessun multiplo di 7 nella riga, invalida il controllo
        if (multiplo==false) {
            controllo = false;
        }
    }

    // Se il controllo fallisce, resetta la somma
    if (controllo==false) {
        somma = 0;
    }

    return somma;
}
