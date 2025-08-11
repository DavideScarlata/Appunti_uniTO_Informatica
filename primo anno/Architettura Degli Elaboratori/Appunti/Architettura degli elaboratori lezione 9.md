# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🏫 Prof:** Claudio Schifanella  
✉️ **Mail:** [claudio.schifanella@unito.it](mailto:claudio.schifanella@unito.it)  
📌 **Corso:** C  
🔗 **[Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3106)**  
📅 **Data:** 24/03/2025

![[Pasted image 20250325141623.png]]
## Linker
è un programma che esegue la funzione di collegamento dei moduli oggetto in nodo da formare un unico modulo eseguibile
#### Compiti del Linker:
Il linker fonde gli spazi di indirizzamento dei moduli oggetto in uno spazio lineare unico nel modo seguente: 
-  Costruisce una tabella di tutti i moduli oggetto e le loro lunghezze 
- Assegna un indirizzo di inizio ad ogni modulo oggetto 
- Trova tutte le istruzioni che accedono alla memoria e aggiunge a ciascun indirizzo una relocation constant corrispondente all’indirizzo di partenza del suo modulo 
- *Trova* tutte le istruzioni che fanno riferimento ad altri moduli e le aggiorna con l’indirizzo corretto
![[Pasted image 20250325142400.png]]

## Loader

-  Una volta creato l’eseguibile (ad opera del linker) esso viene memorizzato su un supporto di memoria secondaria 
-  Al momento dell’esecuzione il sistema operativo lo carica in memoria centrale e ne avvia l’esecuzione 
- Il loader (che è un programma del sistema operativo) si occupa di: 
1. Leggere l’intestazione per determinare la dimensione del programma e dei dati 
2. Riservare uno spazio in memoria sufficiente per contenerli
3. Copiare programma e dati nello spazio riservato
4. Copiare nello stack i parametri (se presenti) passati al main 
5. Inizializzare tutti i registri e lo stack pointer (ma anche gli altri del modello di memoria) 
6. Saltare ad una procedura che copia i parametri dallo stack ai registri e che poi invoca il main

#### Binding e rilocazione dinamica
Collegamento statico: 
- Le funzioni di libreria diventano parte del codice eseguibile 
- Se viene rilasciata una nuova versione, un programma che carica staticamente le librerie continua a utilizzare la vecchia versione 
- La libreria può essere molto più grande del programma; i file binari diventano eccessivamente grossi
Collegamento dinamico: 
- DLL, Dynamically Linked Libraries 
- Le funzioni di libreria non vengono collegate e caricate finché non si inizia l’esecuzione del programma 
- DLL con collegamento lazy: ogni procedura viene caricata solo dopo la sua prima chiamata
![[Pasted image 20250325145445.png]]
![[Pasted image 20250325145528.png]]
### Circuiti digitali
![[Pasted image 20250325151438.png]]
#### Circuiti combinatori
![[Pasted image 20250325151556.png]]
#### il decoder
- Decoder: prende un numero di n bit come ingresso e lo usa per selezionare (mettere a 1, asserire) una delle 2 alla n linee di uscita
-  Può essere utilizzato per attivare una certa componente (vedi ALU più avanti), oppure un banco di memoria, ecc. 
- Interpretiamo gli ingressi A B C (o I2 I1 I0) come le cifre di un numero in base 2 con A (I2) quella più significativa
![[Pasted image 20250325151815.png]]

### multiplexer
Multiplexer (o selettore): 2 ingressi, 1 uscita e 1 ingresso di controllo 
- La linea di controllo determina quale dei 2 ingressi deve essere selezionato per essere inviato all’uscita 
- Esempio con 2 ingressi (A e B), un uscita (C) ed un ingresso di controllo (S)
![[Pasted image 20250325152751.png]]
![[Pasted image 20250325153846.png]]

### addizionatori
- riceve in ingresso due bit (cifre in base 2) da sommare, a e b nello schema 
- riceve in ingresso un bit (cifra in base 2) di riporto, CarryIn nello schema 
- restituisce un bit (cifra in base 2) in uscita che rappresenta il risultato, Sum nello schema
- restituisce un bit (cifra in base 2) in uscita che rappresenta il riporto, CarryOut nello schema
![[Pasted image 20250325154025.png]]![[Pasted image 20250325154054.png]]

![[Pasted image 20250325154908.png]]