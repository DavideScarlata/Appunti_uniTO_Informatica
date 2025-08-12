#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) 
{
    bool AlmenoUnaRiga=false;
    bool TutteRighe=true;
    bool condizione=false ;
    int max=0;
    for (size_t i = 0; i < rows; i++) {
        //considera solo le righe che hanno lunghezza non zero.
        if(rags[i]>0){
            
            int somma=0;
           //somma i numeri nella riga
            for(size_t j=0 ; j<rags[i] ; j++){
                
                somma+=mat[i][j];
            }
            //somma degli elementi della riga è multiplo di k 
            if(somma % k == 0){
                
               AlmenoUnaRiga=true; 
            }
            else{
                TutteRighe=false;
            }
            if(somma>max){
               max=somma;
            }
        }
    }
     // Aggiorna il massimo solo se almeno una riga soddisfa la condizione
   if (TutteRighe && AlmenoUnaRiga) {
        *pMaxSum = max;
        condizione=true;
    }

    return condizione;
}
