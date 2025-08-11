# 📚 Appunti di Davide Scarlata 2024/2025

**👨‍🏫 Prof:** Claudio Schifanella  
**✉️ Mail:** [claudio.schifanella@unito.it](mailto:claudio.schifanella@unito.it)  
**📌 Corso:** C  
**🔗 [Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3106)**  
**🗓 Data:** 21/02/2025

---

## 🗂️ Memoria RAM e Allocazione

Quando un programma viene eseguito, vengono usate tre aree principali:

- **Codice:** Contiene le istruzioni del programma.
- **Stack:** Memoria per chiamate di funzione e variabili locali.
- **Heap:** Area per l'allocazione dinamica della memoria.

---

# 🔄 Ciclo di Esecuzione (Fetch-Decode-Execute)

La CPU esegue ogni istruzione del livello 1 (ISA) per mezzo di una serie di passi elementari:

1. Prendi l'istruzione seguente dalla memoria e mettila nel registro delle istruzioni.
2. Cambia il program counter per indicare l'istruzione seguente.
3. Determina il tipo dell'istruzione appena letta.
4. Se l'istruzione usa una parola in memoria (word), determina dove si trova.
5. Metti la parola, se necessario, in un registro della CPU.
6. Esegui l'istruzione.
7. Torna al punto 1 e inizia a eseguire l'istruzione successiva.

---

# 📊 Misurazione delle Prestazioni

Le prestazioni di una CPU si misurano con:

- **Tempo di esecuzione/risposta:** Intervallo tra inizio e fine di un programma.
- **Throughput/larghezza di banda:** Numero di operazioni eseguite in un dato tempo.

### ⏳ Tempo della CPU

- **Tempo di CPU utente:** tempo effettivamente speso dalla CPU nella computazione richiesta da un programma
- **Tempo di CPU di sistema:** tempo speso dalla CPU per eseguire le funzioni del sistema operativo richieste per l’esecuzione di un programma

### ⏱️ Periodo/Frequenza di Clock della CPU

- **Clock:** Segnale a frequenza costante.
- **Ciclo di clock:** Unità di tempo per sincronizzare le operazioni.
- **Frequenza di clock:** (es. 4 GHz → 4 miliardi di cicli al secondo).

### ⚙️ Velocità del Processore

Dipende da:

- **CPI (Clock per Istruzione).**
- **Numero di Core.**
- **Frequenza di Clock.**

#### ✅ Formule Utili

- **Tempo di cpu relativo ad un programma:**  

$$
    \text{Cicli di clock impiegati} \times \text{Durata di un ciclo di clock}
$$

- **Tempo di cpu relativo ad un programma (alternativa):**  
$$
\frac{\text{Cicli di clock impiegati}}{\text{Frequenza di clock}}
$$
- **tempo di CPU:**  
$$
    \frac{\text{Numero di istruzioni} \times \text{CPI}}{\text{Frequenza di clock}}
$$
- **Istruzioni al secondo:**  
$$
    \frac{\text{Frequenza di clock (Hz)}}{\text{CPI}}
$$


💡 **Nota:** Alcune istruzioni richiedono più cicli di clock per essere eseguite (es. load).

---

# 🏡 Architetture CPU: RISC vs CISC

## 🏃️ RISC (Reduced Instruction Set Computer)

✅ **Istruzioni semplici e veloci.**  
✅ **Miglior efficienza energetica.**  
✅ **Uso ottimizzato dei registri.**  
❌ **Maggior numero di istruzioni necessarie per operazioni complesse.**

## 🚚 CISC (Complex Instruction Set Computer) – Es. Intel

✅ **Istruzioni più complesse che fanno più operazioni.**  
✅ **Meno istruzioni per task complessi.**  
❌ **Consuma più energia e richiede più cicli di clock.**