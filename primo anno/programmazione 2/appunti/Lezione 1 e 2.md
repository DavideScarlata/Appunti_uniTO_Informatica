 
# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🏫 Prof:** michele garetto  
**✉️ Mail:** [michele.garetto@unito.it](michele.garetto@unito.it)
**📌 Corso:** C  
**🔗 [Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3066)**  
**🗓 Data:** 26/02/2025
## strutture dati

le strutture dati sono: collezione di dati correlati che possono essere **==disomogenei==**

es:[^1]

[^1]: titolo :  string
	numero pagine int
	autore:  sting
	prezzo float

```
struct libro { 
char titolo[MAXT]; 
int pagine;
char autore[MAXN]; 
float prezzo; 
};
```
libro sarà un'etichetta (tag) 
la struct è un prototipo di struttura quindi non ha allocata memoria
```
struct libro L; 
struct libro* Lptr = &L;
```
la seconda istruzione è il puntatore alla struttura 

per scrivere nella struct possiamo usare:
```
l'OPERATORE . 
L.pagine = 200; 
o l'OPERATORE -> 
ptrL->pagine = 200;
```

> [!Nota: ]
> Nota: L’operatore -> permette di accedere più semplicemente alla struct noto il suo puntatore, risparmiando la scrittura (equivalente): (*ptrL).pagine = 200

nelle funzioni le stuct di base vengono passate per valore per ciò:
la funzione chiamata non modifica la struct nel chiamante.
per far si che ciò accada bisogna passarla per riferimento (ovvero passare il puntatore &)
