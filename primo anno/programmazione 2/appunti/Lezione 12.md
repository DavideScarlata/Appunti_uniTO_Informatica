# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🎓 Prof:** _Michele Garetto_  
**✉️ Mail:** [📩 michele.garetto@unito.it](mailto:michele.garetto@unito.it)  
**📌 Corso:** 🎓 **C**  
**🔗 [Moodle corso C](https://informatica.i-learn.unito.it/course/view.php?id=3066)**  
**🔗 [Moodle Lab matricole dispari](https://esami.i-learn.unito.it/course/view.php?id=2062)**  
**🗓 Data:**  9/05/2025

---
## Union
```c
typedef union {
		tipox x;
		tipoy y;
} u;

```
## differenza tra union e struct
- union: occupa la dimensione in byte del tipo più grande
- struct: occupa la somma in byte delle dimensioni dei tipi
![[Pasted image 20250523112549.png]]
### A cosa servono le union?
In alcuni contesti applicativi è necessario gestire dati che hanno uno stessa valenza ma che possono essere formattati secondo standard diversi: le union sono uno strumento che permette di definire tipi/variabili che possono accogliere tutti i diversi formati, riducendo la quantità di memoria occupata rispetto alle struct
### Esempio di utilizzo delle union
```c
enum nazione { ITA, USA }; // etichette degli standard usati 
typedef struct TaggedUnion { 
	enum nazione paese; // identifica il caso 
	union { // tipi che dipendono dal caso 
	nomeITA NI; 
	nomeUSA NU; 
	} 
	n; 
}nome;
```
## variabili puntatore a funzione 
sintassi:
```c
tipo_restituito (*nome)(tipo1, tipo2, ...);

```
uso di variabili puntatore a funzione:
```c
int risultato;
risultato = (*nome)(arg1, arg2, ...);
```

### dichiarazione di una funzione che restituisce un puntatore a funzione
```c
typedef struct{
	void *dato;
	opcread creadato;
	opstampa stampa;
	opconfronta confronta;
	tree left,right;
} 
```
come si dichiarano queste variabili?
```c
typedef void *(*opcread)();
typedef void (*opstampa)(void *a);
typedef int (*opconfronta)(void *a, void *b);
```

```c
tree t=(tree)malloc(sizeof(struct nodo));
t->creadato = crea;
t->stampa = stampa;
t->confronta = confronta;
t->left = NULL;
t->right = NULL;
t->dato = t->creadato();
t->stampa(t->dato);
```

utilizzo di sprintf (stampa su stringa)
```c
char s1[n];
char s2[n];
scanf("%s",s1);
scanf("%s",s2);
risultato = (char *)malloc(sizeof(char)*(n1+n2+1));
sprintf(risultato,"%s%s",s1,s2);
```

