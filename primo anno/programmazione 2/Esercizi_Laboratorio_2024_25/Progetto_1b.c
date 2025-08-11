/**
 * @brief Converte una stringa in intero (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa in argomento nella base
 * (la base deve essere un numero intero nel range 2..36) in argomento:
 * − saltando gli eventuali spazi bianchi iniziali,
 * − riconoscendo l'eventuale (singolo) carattere del segno,
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data (le cifre per la base 36 sono: 0,..,9,A,..,Z).
 *
 * @param s: Una stringa da convertire.
 * @param b: La base.
 * @param r: L'indirizzo dell'intero dove memorizzare il risultato.
 * @return   Restituisce 0 se 'b' non è nell’intervallo ammesso, oppure se non trova nessuna cifra valida
 *           (e in tal caso il valore all'indirizzo r non è significativo).
 *           Altrimenti restituisce 1, e scrive all'indirizzo r il numero intero rappresentato nella stringa nella base data.
 *           Non si accorge dell'eventuale overflow (restituendo in questo caso un risultato scorretto).
 */
int stoub(char *s, unsigned short b, int*r) {
    
    if(b < 2 || b > 36 || !s || !r) {
        
        return 0; //base non valida o puntatori nulli
        
    }
     // Salta spazi bianchi iniziali
    while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f' || *s == '\v') {
        s++;
    }
    //gestione del segno
    int segno = 1;
    if(*s == '-' || *s == '+'){
        if(*s == '-' ){
            segno = -1;
        }
        s++;
    }
    int risultato = 0;
    int trova_carattere = 0;
    int carattere_valido = 1;
    
    while (*s && carattere_valido) {
        char c = *s;
        int carattere = -1;
        
        if (c >= '0' && c <= '9') {
            carattere = c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            carattere = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'z') {
            carattere = c - 'a' + 10;
        }
        
        if (carattere < 0 || carattere >= b) {
            carattere_valido = 0; // Segnala la fine della lettura valida
        } else {
            risultato = risultato * b + carattere;
            trova_carattere = 1;
            s++;
        }
    }
    
    if (!trova_carattere) {
        return 0; // Nessuna cifra valida trovata
    }
    
    *r = risultato * segno;
    return 1;
}
