**👨‍🏫 Prof:** Claudio Schifanella  
✉️ **Mail:** [claudio.schifanella@unito.it](mailto:claudio.schifanella@unito.it)  
📌 **Corso:** C  
🔗 **[Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3106)**  
📅 **Data:** 26/05/2025

ld x10,0(x11)

quanto varrà 

regwrite se il valore di controllo è uguale ad 1 si scrive il valore in write data 

memtoReg se devo leggere un dato dalla memoria  e varrà 1
memwrite indica se devo scrivere un dato nella memoria  varrà 0 perchè stiamo facendo una load
branch indica se devo fare un salto oppure no
alusrc varrà 1
regwrite varrà 1

istruzioni di tipo r (add, sub) hanno necessità di avere come input anche funz3 e funz7 per poter essere decodificate correttamente

memoria cache mappatura diretta
numero di richiesta indirizzo binario:
1. 11111
2. 11110
3. 11110
4. 10110
5. 11111
6. 11111
7. 01110
8. 01110
9. 10111

primi 2 bit= tag 
ultimi 3 = indirizzo del blocco nella cache

cos'è il tag?
Il tag è la parte dell'indirizzo che identifica un blocco specifico di dati nella cache. Nella mappatura diretta, il tag viene confrontato con il tag memorizzato nella cache per determinare se i dati richiesti sono presenti (cache hit) o meno (cache miss).

linea 000 tag: 
linea 001 tag:
linea 010 tag:
linea 011 tag:
linea 100 tag:
linea 101 tag:
linea 110 tag:
linea 111 tag:

isa vs assembly nell'isa non ci sono le pseudo istruzioni(es mul mv...)

cosa fa la jal (jump and link) invoca una procedura e salva l'indirizzo di ritorno in ra 

lhu(load half word unsigned) carica un half word dalla memoria e lo mette in un registro)



