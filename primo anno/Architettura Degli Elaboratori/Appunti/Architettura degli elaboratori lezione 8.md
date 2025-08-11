# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🏫 Prof:** Claudio Schifanella  
✉️ **Mail:** [claudio.schifanella@unito.it](mailto:claudio.schifanella@unito.it)  
📌 **Corso:** C  
🔗 **[Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3106)**  
📅 **Data:** 24/03/2025

---
#### esempio moltiplicazione per 10 senza mul

```assembly
moltiplica:
slli t0, a0, 3 # t0 = a0 * 8 
slli t1, a0, 1 # t1 = a0 * 2 
add a0, t0, t1
ret
```

è una funzione foglia in quanto non chiama altre funzioni , rispetta le convenzioni di chiamata 

---
• Scrivere una funzione moltiplicaVettore che 
• Dato un vettore di interi (word)
• Restituisce il vettore sostituendo ogni elemento con il suo prodotto per 10

![[Pasted image 20250324164614.png]]perchè  è sbagliato ? 
• P1 - La funzione non è foglia ma il registro ra non viene salvato e ripristinato 
• P2 - Convenzioni di chiamata non rispettate 
• Il registro t1 viene modificato dall’invocazione di moltiplica
• Il registro a1 potrebbe essere modificato da moltiplica

come risolviamo?
p1)

```assembly
moltiplicaVettore: 
addi sp,sp,-4            risolve p1
sw ra,0(sp)              risolve p1
beq a1, zero, fine
mv t1, a0 
ciclo:
lw t0, 0(t1) 
addi sp, sp, -8        risolve p2
sw t1, 0(sp)           risolve p2
sw a1, 4(sp)           risolve p2
mv a0, t0 
jal ra, moltiplica 
lw t1, 0(sp)          risolve p2
lw a1, 4(sp)          risolve p2
addi sp, sp, 8        risolve p2
sw a0, 0(t1)
addi t1, t1, 4
addi a1, a1, -1 
bnez a1, ciclo 
fine:
lw ra, 0(sp)        risolve p1
addi sp, sp, 4      risolve p1
ret

```
è corretto ma inefficiente perchè salva a1 e t1 che non vengono modificati da moltiplica
come risolvere?
```assembly
moltiplicaVettore: 
	addi sp, sp, -12 
	sw s2, 8(sp) 
	sw s1, 4(sp) 
	sw ra, 0(sp) 
	beq a1, zero, fine 
	mv s1, a0 
	mv s2, a1 
ciclo: 
	lw t0, 0(s1)
	mv a0, t0 
	jal ra, moltiplica 
	sw a0, 0(s1)
	addi s1, s1, 4 
	addi s2, s2, -1 
	bnez s2, ciclo 
fine: 
	lw ra, 0(sp)
	lw s1, 4(sp)
	lw s2, 8(sp) 
	addi sp, sp, 12 
ret
```
---
### Operandi immediati ampi
• Problema: è possibile caricare in un registro una costante a 32 bit? Supponiamo di voler caricare nel registro x5 il valore 0x12345678

• si introduce una nuova istruzione lui (load upper immediate, tipo U) che carica i 20 bit più significativi della costante nei bit da 12 a 31 di un registro 
• Con una operazione di or immediato si impostano i 12 bit meno significativi rimasti
![[Pasted image 20250324170646.png]]

---
#### Salti con offset più grandi
• Come per le costanti, anche i salti possono essere eseguiti anche ad istruzioni più lontane • RISC-V introduce la possibilità di salto in un intervallo pari a 2^32
![[Pasted image 20250324171359.png]]![[Pasted image 20250324171449.png]]
![[Pasted image 20250324171530.png]]

---
## Il livello del Linguaggio Assembly

![[Pasted image 20250324171652.png]]![[Pasted image 20250324172248.png]]

![[Pasted image 20250324174004.png]]
non riesco a leggere tutte le istruzioni mi serve un'altro passo
ASSEMBLATORE a due PASSI 
Problema delle forward reference ! 
1° Passo : 
▪ individuazione di tutti i nomi (le etichette) che compaiono come riferimento simbolico di dati o di istruzioni 
▪ creazione di una Symbol Table che contiene le etichette con la loro posizione relativa all’interno del programma 
2° Passo : 
▪ traduzione dei codici mnemonici delle istruzioni, degli operandi e delle etichette, mediante la consultazione della Symbol Table costruita nel 1° passo.