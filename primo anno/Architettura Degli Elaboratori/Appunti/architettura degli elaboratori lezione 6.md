# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🏫 Prof:** Claudio Schifanella  
✉️ **Mail:** [claudio.schifanella@unito.it](mailto:claudio.schifanella@unito.it)  
📌 **Corso:** C  
🔗 **[Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3106)**  
📅 **Data:** 11/03/2025

---
## Ciclo `while`

```c
int v[10], k, i;
while (v[i] == k) {
    …
    i = i + 1;
}
```

```assembly
LOOP: 
	slli x10, x22, 2  # Calcola l'indirizzo della word v[i]
      add x10, x10, x25
      lw x9, 0(x10)       # Carica v[i] in x9
      bne x9, x24, ENDLOOP   # Se v[i] != k, esce dal ciclo
      …
      addi x22, x22, 1    # Incrementa i
      beq x0, x0, LOOP    # Torna alla valutazione della condizione
ENDLOOP:
```

---

## Salti condizionati e confronto

L'istruzione `slt` scrive 1 in `rd` se `rs1 < rs2`, altrimenti scrive 0.

```c
if (i < j) {
    k = 1;
} else {
    k = 0;
}
```

```assembly
slt x21, x19, x20  # x21 = (x19 < x20) ? 1 : 0
```

Possiamo combinare `slt` con `beq` per implementare il salto condizionato.

---

## Salti condizionati e linguaggio macchina

Le istruzioni di salto condizionato utilizzano il formato **SB**. Questo formato può rappresentare indirizzi di salto da -4096 a 4094 (multipli di 2).

![[Pasted image 20250311143804.png]]

---

## Pseudoistruzioni

Le pseudoistruzioni esistono solo in assembly e vengono tradotte in istruzioni reali dall'assemblatore.

![[Pasted image 20250311145509.png]]

### Istruzioni aritmetiche: moltiplicazione

![[Pasted image 20250311145646.png]]

### Istruzioni aritmetiche: divisione e resto

![[Pasted image 20250311145828.png]]

---

## Procedure

### Definizione

Le procedure sono blocchi di codice riutilizzabili che eseguono un compito specifico.

**Vantaggi:**

- Astrazione
- Riusabilità del codice
- Maggiore organizzazione
- Testing più agevole

### Chiamante e chiamata

```c
int somma(int x, int y) {
    int rst;
    rst = x + y + 2;
    return rst;
}
```

```assembly
jal IndirizzoProcedura   # Jump and Link
```

- Salta all'indirizzo della procedura
- Memorizza il valore dell'istruzione successiva in `x1`

![[Pasted image 20250311152653.png]]

### Ritorno al chiamante

```assembly
jalr rd, offset(rs1)  # Salto a un indirizzo qualsiasi
```

---

## Side Effects – Sovrascrittura dei registri

```c
int somma(int x, int y) {
    int rst = x + y + 2;
    return rst;
}
```

```assembly
SOMMA: add x5, x10, x11  
       addi x20, x5, 2   
       jalr x0, 0(x1)    # Ritorna al chiamante
```

Se un registro contiene un valore usato dalla procedura chiamante, occorre salvarlo in memoria prima di utilizzarlo.

![[Pasted image 20250311153606.png]]

---

## Lo Stack

- Lo stack segue la logica **LIFO (Last In First Out)**.
- Il **Stack Pointer (SP)** indica l'ultima cella occupata nello stack (registro `x2`).

**PUSH**

```assembly
addi sp, sp, -4  # Decrementa SP
sw x20, 0(sp)    # Salva in memoria
```

**POP**

```assembly
lw x20, 0(sp)   # Carica il valore
addi sp, sp, 4  # Incrementa SP
```

---
