# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🎓 Prof:** _Michele Garetto_  
**✉️ Mail:** [📩 michele.garetto@unito.it](mailto:michele.garetto@unito.it)  
**📌 Corso:** 🎓 **C**  
**🔗 [Moodle corso C](https://informatica.i-learn.unito.it/course/view.php?id=3066)**  
**🔗 [Moodle Lab matricole dispari](https://esami.i-learn.unito.it/course/view.php?id=2062)**  
**🗓 Data:** _04/04/2025_

---

## 🌳 Cos'è un albero?

Un **albero** è una struttura dati **non lineare** composta da **nodi**, in cui:

- Ogni nodo può avere **zero o più figli**
- Un albero può essere:
  - **Vuoto**
  - Composto da un **nodo** (radice) e uno o più **sottoalberi**

![[Pasted image 20250511175613.png]]

---

## 🏷 Terminologia dell'albero

| Termine         | Definizione |
|-----------------|-------------|
| **Radice**       | Nodo di origine, **senza antenati** |
| **Foglie**       | Nodi **senza successori** |
| **Frontiera**    | Insieme di tutte le **foglie** |
| **Nodi interni** | Nodi con **almeno un successore** |
| **Discendenti**  | Nodi che **discendono** da un nodo dato |
| **Antenati**     | Tutti i **padri** di un nodo dato |
| **Arco**         | Collegamento **orientato** tra due nodi |

---

### 🔁 Percorsi e profondità

- **Percorso** = sequenza di nodi collegati da **archi**
  - 🔹 **Relativo**: tra un nodo e un suo successore  
  - 🔹 **Assoluto**: dalla **radice** a un nodo (univoco per ogni nodo)
- **Distanza** tra due nodi = numero di archi tra di essi
- **Profondità** = distanza della radice da un nodo
  - 🟤 Albero vuoto → `-1`
  - 🟢 Radice → `0`

---

### 🧮 Altre definizioni importanti

- **Grado di un nodo**: numero di **figli**  
- **Albero di grado N completo**:
  - Tutte le foglie sono alla **stessa profondità N**
  - Tutti i nodi interni hanno **esattamente N figli**
- **Albero degenere**:
  - Ogni nodo ha **al massimo un figlio** (≈ lista)
- **Albero ordinato**:
  - I nodi contengono valori **ordinabili**
  - La disposizione dei nodi **rispetta una relazione d’ordine**

![[Pasted image 20250511175512.png]]  
![[Pasted image 20250511175530.png]]

---

## 💻 Esempio: struttura di albero binario in C

```c
typedef struct nodo *tree;

struct nodo {
    int dato1;        // valore contenuto nel nodo
    // altri dati utili (es. etichette, info, ecc.)
    tree left;        // puntatore al sottoalbero sinistro
    tree right;       // puntatore al sottoalbero destro
};
```

### operazioni sugli alberi

```c
void init(tree *t){// inizializza l'albero
		*t = NULL;
}

tree crea_nodo (int el) {
		tree nuovo = (tree)malloc(sizeof(struct nodo);
		nuovo->dato1 = el;
		nuovo->left = NULL;
		nuovo->right = NULL;
		return nuovo;
		}
```

### come percorrere un albero (La visita)

- strategie:
- visita in profondità (depth-first visit/search): visita per primo uno dei nodi più distanti dalla radice; realizzata tramite ricorsione o stack di appoggio
- visita in ampiezza (breadth-first visit/search): esplora l’albero per livelli; realizzata tramite coda FIFO di appoggio

#### visita in profondità 
può essere fatta in maniera ricorsiva (con backtracking) 
o in maniera iterativa(senza backtracking))

### visita ricorsiva
visita in preorder: 
```c
visita nodo
visita figlio sinistro
visita figlio destro
```
stampa prima tutti i nodi  prima quelli a sinistra e poi quelli a destra
visita inorder:
```c
visita figlio sinistro
visita nodo
visita figlio destro
```
percorre l'albero a sinistra finchè ci sono figli sinistri stampa il nodo poi fa il richiamo ricorsivo a destra 

visita postorder:
```c
visita figlio sinistro
visita figlio destro
visita nodo
```
prima eseguimo il richiamo ricorsivo a sinistra e a destra e poi stampiamo il nodo

### implementazioni 
stampa in preorder
```c
void stampa_preorder(tree t){
     if(t){
     		 printf("%d ", t->dato);
					stampa_preorder(t->left);
					stampa_preorder(t->right);
	}
	else
		 printf("Albero vuoto");
}
```

stampa in inorder
```c
void stampa_inorder(tree t){
		 if(t){
		 		 stampa_inorder(t->left);
				 printf("%d ", t->dato);
				 stampa_inorder(t->right);
	}
	else
		 printf("Albero vuoto");
}
```
stampa in postorder
```c
void stampa_postorder(tree t){
		 if(t){
		 		 stampa_postorder(t->left);
				 stampa_postorder(t->right);
				 printf("%d ", t->dato);
	}
	else
		 printf("Albero vuoto");
}
```

### visita in profondità iterativa (con stack)
```c
void visita(tree t){
		stack s;
		push(&s,radice);
		while(!Empty(s)){
		     current = pop(s);
		     //se metto la print qua sarà visita in preorder
		     if(current->left){
			     push(s,current->left);
		     }
		     //visita inorder
		     if(current->right){
			     push(s,current->right);
		     }
		     //visita postorder
		}

}
```

## Visita in ampiezza

viene gestita in maniere iterativa attraverso una coda 

```c
allocazione della coda vuota
enqueue(coda,radice);
while(!empty(coda)){
	current = dequueu(coda)
	if(current->left){
		enqueue(coda,nodo sinistro);
	}
	if(current->right){
		enqueue(coda,nodo destro);
	}
}

```

