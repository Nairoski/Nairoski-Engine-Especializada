<h1># 🛠️ Nairoski Engine</h1>

Uma **engine 2D em C++**, desenvolvida do zero com **Allegro 5**, focada em aprendizado profundo de programação, arquitetura de jogos e sistemas no estilo *Factorio / sandbox*.

---

## 🚀 Visão Geral

A **Nairoski Engine** foi criada com o objetivo de entender *como as coisas realmente funcionam* em uma engine:

* Gerenciamento de entidades
* Sistema de grid
* Renderização manual
* Interação entre objetos (miners, esteiras, minérios)
* Atualização baseada em tempo (ticks)

Tudo escrito **sem frameworks prontos**, apenas C++ + Allegro.

---

## 🎮 Funcionalidades Atuais

* 🧍 Player com movimentação livre
* ⛏️ **Miners** que detectam minério natural
* 🟫 **Minérios** naturais e gerados
* 🔁 **Esteiras** com rotação e sentido
* 🧱 Sistema de **grid** para posicionamento
* 👻 Preview fantasma antes de colocar estruturas
* 🖱️ Colocação de estruturas com o mouse
* 🔄 Rotação de estruturas com tecla (`R`)

---

## 🧠 Sistemas em Desenvolvimento

* Transporte de minérios pelas esteiras
* Interação miner → esteira
* Sistema de chunks
* Organização por camadas (draw order)
* Otimizações de performance

---

## 🧩 Estrutura do Projeto

```txt
Nairoski Engine/
├── src/            # Código fonte (.cpp)
├── include/        # Headers (.h)
├── assets/         # Sprites e imagens
├── build/          # Arquivos gerados
├── .gitignore
└── README.md
```

---

## 🛠️ Tecnologias Utilizadas

* **C++**
* **Allegro 5** (gráficos, input, eventos)
* Git & GitHub

---

## ▶️ Como Compilar

### Requisitos

* Allegro 5 instalado
* Compilador C++ (g++, MinGW ou MSVC)

### Exemplo (MinGW):

```bash
g++ src/*.cpp -o NairoskiEngine \
-lallegro -lallegro_image -lallegro_primitives -lallegro_dialog
```

> Ajuste os caminhos conforme seu sistema.

---

## 🎯 Objetivo do Projeto

Este projeto tem foco **educacional e experimental**, com os seguintes objetivos:

* Aprender C++ de forma sólida
* Entender engines de jogos na prática
* Criar sistemas reutilizáveis
* Evoluir para projetos maiores no futuro

---

## 📌 Status

🚧 **Em desenvolvimento ativo**

Mudanças frequentes, refactors e novas ideias surgem constantemente.

---

## 👤 Autor

**Pedro Nairoski**
Estudante e desenvolvedor em formação

---

## 📜 Licença

Este projeto é open-source para fins de estudo.

Sinta-se livre para explorar, modificar e aprender com o código.

---

🔥 *Construindo do zero para entender tudo.*
