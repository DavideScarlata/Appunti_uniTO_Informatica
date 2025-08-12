#include <stdio.h>
#include <stdbool.h>

int e2R(size_t aLen, const int a[], size_t bLen, const int b[], size_t i) {
    // Caso base: quando entrambi gli array sono terminati
    if (i >= aLen && i >= bLen) {
        return 0;
    }

    int somma = 0;
    int prodotto = 0;
    int quadrato_a = 0;
    int quadrato_b = 0;

    // Caso in cui entrambe le posizioni hanno elementi
    if (i < aLen && i < bLen) {
        prodotto = a[i] * b[i];
    }
    // Caso in cui solo l'elemento di a è disponibile
    else if (i < aLen) {
        quadrato_a = a[i] * a[i];
    }
    // Caso in cui solo l'elemento di b è disponibile
    else if (i < bLen) {
        quadrato_b = b[i] * b[i];
    }

    // Calcola la somma per la posizione corrente
    somma = prodotto + quadrato_a + quadrato_b;

    // Chiamata ricorsiva per la posizione successiva
    return somma + e2R(aLen, a, bLen, b, i + 1);
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    
    return e2R(aLen, a, bLen, b, 0);
}
