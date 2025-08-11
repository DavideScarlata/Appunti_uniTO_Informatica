/**  Un tipo di dato per i contatti telefonici e cyberspaziali
*/
#include <stdio.h>
#include <string.h>
#include <strings.h> 
#include <ctype.h>
/**  @brief Controlla se due contatti hanno lo stesso nome e cognome
      @param c1 il primo  contatto 
      @param c2 il secondo contatto
      @return 1 se i due contatti sono uguali, 0 altrimenti
*/
_Bool contactEq(Contact c1, Contact c2)
{
    if(strcasecmp(c1.name, c2.name) == 0 && strcasecmp(c1.surname, c2.surname) == 0){
        return 1;
    }
    else{
        return 0;
    }
}

/**  @brief Controlla se due contatti hanno lo stesso nome e cognome∗ 
      @param pc1 il puntatore al primo  contatto (non può essere NULL)
      @param pc2 il puntatore al secondo  contatto (non può essere NULL)
      @return 1 se i due contatti sono uguali, 0 altrimenti
*/
_Bool contactEqEff(const Contact *pc1, const Contact *pc2)
{
    if(strcasecmp(pc1->name, pc2->name) == 0 && strcasecmp(pc1->surname, pc2->surname) == 0){
        return 1;
    }
    else{
        return 0;
    }
}


/**  @brief Confronta due contatti per cognome rispetto all'ordine lessicografico e, se il cognome e' lo stesso, per nome
      @param c1 il primo  contatto 
      @param c2 il secondo contatto
      @return -1 se c1 minore di c2, 0 se c1 uguale a c2, 1 se c1 maggiore di c2
*/
int contactCmp(Contact c1, Contact c2)
{
    int surnameCmp = strcasecmp(c1.surname, c2.surname);
    if(surnameCmp < 0){
        return -1;
    }
    else if(surnameCmp > 0){
        return 1;
    }
    else {
        int nameCmp = strcasecmp(c1.name, c2.name);
        if(nameCmp < 0){
            return -1;
        }
        else if(nameCmp > 0){
            return 1;
        }
        else{
            return 0;
        }
    }
}


/**  @brief Confronta due contatti per cognome rispetto all'ordine lessicografico e, se il cognome e' lo stesso, per nome
      @param pc1 il puntatore al primo  contatto (non può essere NULL)
      @param pc2 il puntatore al secondo  contatto (non può essere NULL)
      @return -1 se *pc1 minore di *pc2, 0 se *pc1 uguale a *pc2, 1 se *pc1 maggiore di *pc2
*/
int contactCmpEff(const Contact *pc1, const Contact *pc2)
{
    int surnameCmp = strcasecmp(pc1->surname, pc2->surname);
    if(surnameCmp < 0){
        return -1;
    }
    else if(surnameCmp > 0){
        return 1;
    }
    else {
        int nameCmp = strcasecmp(pc1->name, pc2->name);
        if(nameCmp < 0){
            return -1;
        }
        else if(nameCmp > 0){
            return 1;
        }
        else{
            return 0;
        }
    }
}
