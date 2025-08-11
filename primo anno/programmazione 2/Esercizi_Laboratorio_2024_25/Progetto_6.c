#include "ram.h"
#include <stdlib.h>
#include <string.h>
/*
      se voglio allocare un quantitativo K di ram divido la ram totale 
      in due e poi ancora in 2 fino ad arrivare che divdendo la ram ancora avrei suddivisioni più piccole di K
      se si supera tutti i test -1 va bene
*/


/**
* @brief Crea una struttura RAM con una certa quantità di memoria  
* @param M la quantità di memoria voluta, espressa in KB (deve essere una potenza di 2, maggiore o uguale a 1)
* @return Il puntatore alla struttura creata, oppure NULL in caso di errore
*/
RAM initram(int M) {
      if(M<1 || (M & (M-1))!=0)return NULL;
      RAM r = malloc(sizeof(struct nodo));
      r->KB = M;
      r->s=LIBERO;
      r->parent=NULL;
      r->rbuddy=NULL;
      r->lbuddy=NULL;
      return r;
}


/**
* @brief Tenta di allocare una data quantità di memoria entro una RAM
* @param K la quantità di memoria richiesta, in KB
* @param ram la RAM entro cui cercare la memoria richiesta
* @return Il puntatore al nodo che può ospitare la quantità richiesta, oppure NULL se non trovato
*/
RAM allocram(int K, RAM ram) {
      if(!ram || K > ram->KB || K<1 || ram->s==OCCUPATO) return NULL;
      
      if(K > ram->KB/2 && K <= ram->KB && ram->s == LIBERO) {
            ram->s = OCCUPATO;
            return ram;
      }
      if(ram->s == LIBERO) {
            RAM lb = initram(ram->KB/2);
            if(!lb) return NULL;
            lb->parent = ram;
            ram->lbuddy = lb;
            ram->s = INTERNO;
            
            RAM rb = initram(ram->KB/2);
            if(!rb)return NULL;
            rb->parent = ram;
            ram->rbuddy = rb;
            ram->s = INTERNO;
      }
      RAM r = allocram(K, ram->lbuddy);
      if(r)
      {
          return r;
      }
      r=allocram(K,ram->rbuddy);
      if(r)
      {
         return r;
      }else{
          return NULL;
      }
      return NULL;
}


/**
* @brief Libera un nodo RAM precedentemente ottenuto con allocram    
* @param ram il nodo RAM da liberare
* @return Il successo della operazione
*/
Risultato deallocram(RAM ram) {
    // Caso non valido: nodo nullo o non occupato
    if (!ram || ram->s != OCCUPATO) {
        return NOK;
    }

    // Libera il nodo
    ram->s = LIBERO;

    // Tentativo di merge con il buddy
    while (ram->parent != NULL) {
        RAM parent = ram->parent;
        RAM buddy = (parent->lbuddy == ram) ? parent->rbuddy : parent->lbuddy;

        // Se il buddy non esiste o non è libero, non si può unire
        if (!buddy || buddy->s != LIBERO) {
            break;
        }

        // Entrambi i buddy sono liberi: fusione
        free(parent->lbuddy);
        free(parent->rbuddy);

        parent->lbuddy = NULL;
        parent->rbuddy = NULL;
        parent->s = LIBERO;

        // Continua la fusione verso l'alto
        ram = parent;
    }

    return OK;
}



/**
* @brief calcola il numero di KB di memoria ancora liberi all'interno di una struttura RAM    
* @param ram la struttura RAM 
* @return La quantità di memoria libera, oppure -1 in caso di errore
*/
int numfree(RAM ram) {
    if (!ram) return -1;

    if (ram->s == LIBERO) {
        // Se il nodo è libero, tutta la sua memoria è disponibile
        return ram->KB;
    }

    if (ram->s == OCCUPATO) {
        // Nodo occupato, nessuna memoria libera qui
        return 0;
    }

    // Nodo interno: somma la memoria libera nei figli ricorsivamente
    int left_free = numfree(ram->lbuddy);
    int right_free = numfree(ram->rbuddy);

    if (left_free == -1 || right_free == -1) {
        return -1; // errore nella ricorsione
    }

    return left_free + right_free;
}


/**
* @brief crea una rappresentazione dello stato interno della RAM sotto forma di una stringa (in un formato a piacere, 
* purchè completo di tutte le informazioni, ovvero tale che si possa ricreare dalla stringa esattamente lo stesso stato)
* @param ram la struttura RAM di cui creare la stringa
* @return la stringa creata, vuota in caso di RAM nulla o errore
*/
char* ram2str(RAM ram) {
    if (!ram) {
        char* empty = malloc(1);
        if (empty) empty[0] = '\0';
        return empty;
    }

    size_t cap = 256;
    size_t len = 0;
    char* buf = malloc(cap);
    if (!buf) return NULL;
    buf[0] = '\0';

    // Funzione ricorsiva interna
    int write_ram(RAM r) {
        if (!r) {
            const char* nullstr = "null";
            size_t n = strlen(nullstr);
            if (len + n + 1 > cap) {
                cap = (cap + n + 1) * 2;
                char* tmp = realloc(buf, cap);
                if (!tmp) return 0;
                buf = tmp;
            }
            strcpy(buf + len, nullstr);
            len += n;
            return 1;
        }

        char stato_char = (r->s == LIBERO) ? 'L' :
                          (r->s == OCCUPATO) ? 'O' : 'I';

        char temp[64];
        int n = snprintf(temp, sizeof(temp), "%d:%c(", r->KB, stato_char);
        if (len + n + 1 > cap) {
            cap = (cap + n + 1) * 2;
            char* tmp = realloc(buf, cap);
            if (!tmp) return 0;
            buf = tmp;
        }
        memcpy(buf + len, temp, n);
        len += n;
        buf[len] = '\0';

        if (!write_ram(r->lbuddy)) return 0;

        if (len + 2 > cap) {
            cap = (cap + 2) * 2;
            char* tmp = realloc(buf, cap);
            if (!tmp) return 0;
            buf = tmp;
        }
        buf[len] = ',';
        len++;
        buf[len] = '\0';

        if (!write_ram(r->rbuddy)) return 0;

        if (len + 2 > cap) {
            cap = (cap + 2) * 2;
            char* tmp = realloc(buf, cap);
            if (!tmp) return 0;
            buf = tmp;
        }
        buf[len] = ')';
        len++;
        buf[len] = '\0';

        return 1;
    }

    if (!write_ram(ram)) {
        free(buf);
        return NULL;
    }
    return buf;
}


/**
* @brief ricostruisce una struttura RAM a partire dalla sua rappresentazione sotto forma di stringa creata da ram2str 
* @param s  la stringa che contiene la rappresentazione della RAM, eventualmente vuota
* @return la RAM creata, oppure NULL in caso di errore o stringa vuota
*/
RAM str2ram(char *str) {
    static char *p;

    if (str != NULL) {
        // Se la chiamata è esterna, inizializzo il puntatore statico
        p = str;
    }
    if (!p || *p == '\0') return NULL;

    // Parsing KB
    int kb = 0;
    if (!(*p >= '0' && *p <= '9')) return NULL;
    while (*p >= '0' && *p <= '9') {
        kb = kb * 10 + (*p - '0');
        p++;
    }

    if (*p != ':') return NULL;
    p++; // salto ':'

    // Parsing stato
    if (*p != 'L' && *p != 'O' && *p != 'I') return NULL;
    char stato_char = *p;
    p++;

    if (*p != '(') return NULL;
    p++; // salto '('

    // Creo nodo RAM
    RAM node = malloc(sizeof(struct nodo));
    if (!node) return NULL;

    node->KB = kb;
    switch (stato_char) {
        case 'L': node->s = LIBERO; break;
        case 'O': node->s = OCCUPATO; break;
        case 'I': node->s = INTERNO; break;
        default:
            free(node);
            return NULL;
    }
    node->parent = NULL;
    node->lbuddy = NULL;
    node->rbuddy = NULL;

    // Parsing figlio sinistro
    if (p[0] == 'n' && p[1] == 'u' && p[2] == 'l' && p[3] == 'l') {
        p += 4;
        node->lbuddy = NULL;
    } else {
        RAM left_child = str2ram(NULL);
        if (!left_child) {
            free(node);
            return NULL;
        }
        node->lbuddy = left_child;
        left_child->parent = node;
    }

    if (*p != ',') {
        free(node);
        return NULL;
    }
    p++; // salto ','

    // Parsing figlio destro
    if (p[0] == 'n' && p[1] == 'u' && p[2] == 'l' && p[3] == 'l') {
        p += 4;
        node->rbuddy = NULL;
    } else {
        RAM right_child = str2ram(NULL);
        if (!right_child) {
            free(node);
            return NULL;
        }
        node->rbuddy = right_child;
        right_child->parent = node;
    }

    if (*p != ')') {
        free(node);
        return NULL;
    }
    p++; // salto ')'

    // Se questa è la chiamata "interna", restituisco il nodo
    // Se è la chiamata esterna (prima), controllo che non ci siano caratteri extra
    // Per questo controllo, se la chiamata è esterna, p è aggiornata su tutta la stringa

    return node;
}




/**
* @brief cancella dallo heap la struttura dati di un nodo RAM e di tutti i suoi figli  
* @param ram il nodo RAM da cancellare
* @return Restituisce OK se la funzione ha effettivamente liberato della memoria, NOK altrimenti
*/
Risultato freeram(RAM* ramptr) {
    if (!ramptr || !*ramptr) return NOK;

    RAM ram = *ramptr;

    // libera ricorsivamente i figli
    if (ram->lbuddy) freeram(&(ram->lbuddy));
    if (ram->rbuddy) freeram(&(ram->rbuddy));

    // libera il nodo stesso
    free(ram);
    *ramptr = NULL;

    return OK;
}
