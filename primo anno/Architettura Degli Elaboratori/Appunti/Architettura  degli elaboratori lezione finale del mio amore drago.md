# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🏫 Prof:** Claudio Schifanella  
✉️ **Mail:** [claudio.schifanella@unito.it](mailto:claudio.schifanella@unito.it)  
📌 **Corso:** C  
🔗 **[Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3106)**  
📅 **Data:** 30/05/2025

velocità del nostro processore risc v = 900ps in media per ciclo (convenzione usata a lezione)
![[Pasted image 20250530115842.png]]

700 * 0.6 = 420ps
100 * 0.2 = 20ps
900 * 0.1 = 90ps
700 * 0.1 = 70ps
totale 600ps

la media è 900 
quindi 900 / 600 = 1.5

![[Pasted image 20250530121112.png]]

l'immediato è da 12bit 

sovrascriviamo un registro non lo leggiamo

hanno lo stesso cod op quindi no (a lezione drago lo ha fatto aggiungere quindi è un po' sus )

dobbiamo fare l'estensione del segno

![[Pasted image 20250530121616.png]]

in t1 ci sarà il numero 26 in binario 11010
in t5 ci sarà il numero 7 in binario 111

facciamo l'or 


![[Pasted image 20250530122237.png]]
la or è un'istruzione di tipo r

alusrc = 0 perché non stiamo usando l'immediato
regwrite = 1 perché dobbiamo scrivere il risultato nel registro di destinazione
memtoReg = 0 perché non stiamo leggendo dalla memoria
memwrite = 0 perché non stiamo scrivendo nella memoria
branch = 0 perché non stiamo facendo un salto
![[Pasted image 20250530122939.png]]
basta leggere gli indirizzi e cosa fa il codice easy game