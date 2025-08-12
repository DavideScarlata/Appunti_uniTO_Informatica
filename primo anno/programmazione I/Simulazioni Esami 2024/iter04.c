#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
    // COMPLETARE
    //e1 modifica in-place la matrice irregolare;
    //per ciascuna riga i, la funzione e1 scorre gli elementi inizializzati e, 
    //per ogni colonna j il cui elemento inizializzato è maggiore di 0 e multiplo di 3,
    //aggiunge in fondo alla riga i l'elemento stesso diviso 3.
    //L'aggiunta degli elementi si interrompe se la riga raggiunge la capacità massima cols.
    //e1 ritorna true se tutte le righe sono state modificate con almeno un'aggiunta di un elemento.
    //Ritorna false altrimenti
    int funzione= true;
    for(size_t i=0 ; i<rows ; i++){
        bool tutte_modificate=false;
        for(size_t j=0 ; j<rags[i] ; j++){
            
            if(mat[i][j]>0 && mat[i][j]%3==0){//per ogni colonna j il cui elemento inizializzato è maggiore di 0 e multiplo di 3,
            
                if(rags[i]<cols){//L'aggiunta degli elementi si interrompe se la riga raggiunge la capacità massima cols.
                
                    mat[i][rags[i]] = mat[i][j]/3;//aggiunge in fondo alla riga i l'elemento stesso diviso 3.
                    rags[i]++;
                    tutte_modificate=true;//e1 ritorna true se tutte le righe sono state modificate con almeno un'aggiunta di un elemento.
                }   
            }
            }
            if(tutte_modificate==false){
                funzione= false;
            }
    }
    return funzione;
}