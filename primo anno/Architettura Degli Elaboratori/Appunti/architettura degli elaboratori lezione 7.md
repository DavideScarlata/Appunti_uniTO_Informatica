# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🏫 Prof:** Claudio Schifanella  
✉️ **Mail:** [claudio.schifanella@unito.it](mailto:claudio.schifanella@unito.it)  
📌 **Corso:** C  
🔗 **[Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3106)**  
📅 **Data:** 18/03/2025
## convenzioni di chiamata
![[Pasted image 20250430120148.png]]
![[Pasted image 20250430120326.png]]![[Pasted image 20250430120410.png]]![[Pasted image 20250430143955.png]]![[Pasted image 20250430144010.png]]
![[Pasted image 20250318141704.png]]
### Le fasi di una invocazione di procedura schematicamente

![[Pasted image 20250318144235.png]]
### Le fasi di una invocazione di procedura foglia
• Se una procedura è foglia, nel codice della procedura : 
• non è necessario salvare e ripristinare il registro ra 
• non è necessario salvare sullo stack i registri a0-a7 e t0-t6 (non c’è nessuna invocazione di procedura nella procedura chiamata)

```assembly
sommaArray: 
			li t0, 0 # t0 = somma
			li t1, 0 # t1 = contatore indice i 
loop: 
			bge t1, a1, fine     # i >= lunghezza, esci dal loop 
			slli t2, t1, 2       # offset
			add t3, a0, t2       # indirizzo elemento i
			lw t4, 0(t3)         # Carica v[i] 
			add t0, t0, t4       # Aggiorna la somma 
			addi t1, t1, 1       # i++ 
			j loop               # Ripeti il ciclo 
fine: 
			mv a0, t0            # Restituisci il risultato in a0 
			jr ra                # Ritorna

# funzione main
start:
			la a0,array          # a0 = indirizzo dell'array
			la a1,length         # a1 = lunghezza dell'array
			lw a1,0(a1)
			jal ra, sommaArray
			
			li a7, 93            # syscall exit
			ecall                # termina il programma
```
