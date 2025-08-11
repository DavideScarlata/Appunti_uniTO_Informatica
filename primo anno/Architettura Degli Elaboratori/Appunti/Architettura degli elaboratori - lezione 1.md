# 📚 Appunti di Davide Scarlata 2024/2025

- **👨‍🏫 Professore:** Claudio Schifanella
- **✉️ Email:** [claudio.schifanella@unito.it](mailto:claudio.schifanella@unito.it)
- **📌 Corso:**  C
- **🔗 Moodle:** [Moodle Unito](https://informatica.i-learn.unito.it/course/view.php?id=3106)
- **📅 Data:** 18/02/2025
- **🎖️ Riconoscimenti:** Davide Vella

---

# 🖥️ Linguaggio Macchina e Assembly

## 🔹 Linguaggio Macchina 💾

- Il linguaggio più **basso** e direttamente comprensibile dalla CPU.
- Scritto in **binario** (difficile da leggere per gli umani).

## 🔹 Linguaggio Assembly 🛠️

- Un linguaggio a basso livello più leggibile rispetto al linguaggio macchina.
- Tradotto in linguaggio macchina tramite un **Assembler**.

---

# 🔄 Strati di Astrazione 🏗️

| **Livello** | **Descrizione**                   | **Conversione al livello inferiore tramite**         |
| ----------- | --------------------------------- | ---------------------------------------------------- |
| **4**       | Linguaggi ad alto livello         | 🖥️ Compilatore                                      |
| **3**       | Assembly                          | 🔄 Assemblatore                                      |
| **2**       | Sistema Operativo (OS)            | ⚙️ Interpretazione parziale                          |
| **1**       | Instruction Set Architecture(isa) | 📜 Definisce le istruzioni eseguibili dal processore |
| **0**       | Logica Digitale                   | 🔌 Composta da porte logiche e circuiti elettronici  |

---

# 🔄 Conversione dei Linguaggi 🔀

|**Da → A**|**Strumento utilizzato**|
|---|---|
|**📜 Linguaggio Alto Livello → 🛠️ Assembly**|🔹 **Compilatore**|
|**🛠️ Assembly → 💾 Linguaggio Macchina**|🔹 **Assemblatore**|

---

# 🏛️ Architettura di Von Neumann

![[Pasted image 20250308174420.png]]

## 🔹 Definizione

Questa architettura, sviluppata durante la Seconda Guerra Mondiale, ha permesso di **caricare programmi in memoria**, a differenza delle architetture precedenti.

## ⚙️ Struttura della CPU

### **🧠 CPU - Componenti principali**

#### **Unità di Controllo (Control Unit) 🎛️**

- Decodifica le istruzioni e coordina le altre componenti della CPU per eseguirle.

> 💡 Alcune istruzioni vengono eseguite direttamente dalla Control Unit.

#### **Unità Aritmetico-Logica (ALU) ➕➖**

- Esegue operazioni aritmetiche (somma, sottrazione) e logiche (AND, OR, NOT).

#### **Registri 📋**

- Memoria ultra-veloce usata per l'elaborazione immediata dei dati (memoria temporanea ).

##### **📌 Registri fondamentali**

- **📍 PC (Program Counter):** Indirizzo della prossima istruzione.
- **📍 IR (Instruction Register):** Istruzione attualmente in esecuzione.
### altri registri:
status register(sr) 

## **📂 Memoria Principale (RAM) 💾**

- Memoria **volatile** che contiene **codice macchina** e **dati**.
- Più lenta rispetto ai registri.

### **🛜 Bus 🚍**

Sistema di comunicazione tra le componenti hardware. (fili)

**Tipologie di bus:**

#### - **🖥️ Bus di sistema:** Collega la CPU ai chipset:
- tra questi abbiamo:
- bus di controllo: indica se l'operazione in memoria sarà una lettura o una scrittura 
- bus degli indirizzi: punta una certa zona di memoria per prelevare il dato 
- bus dei dati: bidirezionale verso la memoria per scrivere dalla memoria per leggere  
##### **📡 Bus I/O:** Gestisce la comunicazione con le periferiche.
#####  - **🎮 Bus locale:** Include bus specifici come **PCIe o AGP** per connettere componenti interni come scheda video e audio.

### **📊 Data Path**

organizzazione interna di una CPU (registri, ALU, bus interno)
Ciclo del data path:  è un  processo per far  passare due operandi attraverso l'ALU e memorizzarne il risultato
#### **Esempio in RISC-V:**

- I dati in ingresso vengono caricati nei **registri**.
- Dopo l'elaborazione, i dati in uscita vengono **salvati nei registri**.