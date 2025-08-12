bool e1(const size_t rows, const size_t cols, 
        int mat[rows][cols], size_t rags[rows]) 
{
    bool funzione = false; // Variabile per indicare se almeno una riga è stata modificata.

    if (rows > 0) { // Controlla se ci sono righe nella matrice.
        for (size_t i = 1; i < rows; i++) { // Itera sulle righe dalla seconda (i = 1) in poi.

            size_t nuova_dim = 0; // Nuova dimensione della riga `i` dopo il filtraggio.

            for (size_t j = 0; j < rags[i]; j++) { // Itera sugli elementi della riga corrente `i`.

                bool trovato = false; // Indica se l'elemento corrente è presente nella riga precedente.

                for (size_t k = 0; k < rags[i - 1] && !trovato; k++) { 
                    // Confronta l'elemento mat[i][j] con tutti gli elementi della riga precedente `mat[i-1]`.
                    // Continua il ciclo solo finché `trovato` è false.
                    
                    if (mat[i][j] == mat[i - 1][k]) { // Se l'elemento è trovato...
                        trovato = true; // Imposta il flag a true.
                    }
                }

                if (!trovato) { 
                    // Se l'elemento `mat[i][j]` non è presente nella riga precedente:
                    mat[i][nuova_dim] = mat[i][j]; // Copia l'elemento nella nuova posizione.
                    nuova_dim++; // Incrementa la nuova dimensione della riga.
                } else {
                    // Se l'elemento è stato trovato nella riga precedente:
                    funzione = true; // Imposta `funzione` a true perché una riga è stata modificata.
                }
            }

            rags[i] = nuova_dim; // Aggiorna la dimensione effettiva della riga `i` dopo il filtraggio.
        }
    }
    return funzione; // Restituisce true se almeno una riga è stata modificata, false altrimenti.
}
