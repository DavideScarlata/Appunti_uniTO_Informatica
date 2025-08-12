#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    int *pMinSumProd) 
{
    // COMPLETARE
    int ContaRighe=0;
    bool funzione=false;
    int MinTemp=INT_MAX; //MASSIMO VALORE POSSIVILE 
    for(size_t i=0; i<rows  ; i++){
        
        int sum_prod=0;
        
        bool MultiploDiTre = false;
        
        for(size_t j=0; j<rags[i]  ; j++){
            if(mat[i][j]%3==0){//esiste almeno una colonna j<rags[i] per la quale l'elemento i,j è multiplo di 3;
                MultiploDiTre= true;
                int prod_j = 1;
                for(size_t k=0 ; k<rows ; k++){
                    if(j<rags[k]){
                       prod_j=prod_j*mat[k][j];   
                    }
                }
                sum_prod+=prod_j;
            }
		}
            if(MultiploDiTre && sum_prod%10==0){ //il valore sum_prod è divisibile per 10
               ContaRighe++;
				if (sum_prod < MinTemp) {
                    MinTemp = sum_prod;
                }
            }
	}
    if(ContaRighe>=2){
		*pMinSumProd=MinTemp;
        funzione=true;
    }
return funzione;
}
