<h1># 🛠️ Nairoski Engine</h1>

A **2D engine written in C++**, built from scratch using **Allegro 5**, focused on deep learning of programming fundamentals, game engine architecture, and systems inspired by *Factorio / sandbox-style* games.

> This project is not just a game — it is a laboratory for ideas, systems, and experimentation.

---

## 🚀 Overview

**Nairoski Engine** was created with the goal of understanding *how things actually work* inside a game engine:

* Entity management
* Grid-based systems
* Manual rendering
* Object interaction (miners, conveyors, ores)
* Time-based updates (ticks)

Everything is written **without ready-made engines**, using only C++ + Allegro.

---

## 🎮 Current Features

* 🧍 Player with free movement
* ⛏️ **Miners** that detect natural ore
* 🟫 **Ores** (natural and generated)
* 🔁 **Conveyors (Esteiras)** with rotation and direction
* 🧱 **Grid system** for placement
* 👻 Ghost preview before placing structures
* 🖱️ Mouse-based structure placement
* 🔄 Structure rotation using keyboard (`R`)

---

## 🧠 Systems in Development

* Ore transportation through conveyors
* Miner → conveyor interaction
* Procedural map generation
* Chunk-based world system
* Layered rendering (draw order)
* Performance optimizations

---

## 🧩 Project Structure

```txt
Nairoski Engine/
├── src/            # Source files (.cpp)
├── include/        # Header files (.h)
├── assets/         # Sprites and images
├── build/          # Generated files
├── .gitignore
└── README.md
```

---

## 🛠️ Technologies Used

* **C++**
* **Allegro 5** (graphics, input, events)
* Git & GitHub

---

## ▶️ How to Build

### Requirements

* Allegro 5 installed
* C++ compiler (g++, MinGW, or MSVC)

### Example (MinGW):

```bash
g++ src/*.cpp -o NairoskiEngine \
-lallegro -lallegro_image -lallegro_primitives -lallegro_dialog
```

> Adjust library paths according to your system.

---

## 🎯 Project Goals

This project has an **educational and experimental focus**, aiming to:

* Build strong C++ fundamentals
* Understand game engines at a low level
* Create reusable systems
* Evolve into larger and more complex projects

---

## 📌 Project Status

🚧 **Actively in development**

Frequent changes, refactors, and new ideas are expected.

---

## 👤 Author

**Pedro Nairoski**
Student and aspiring software developer

---

## 📜 License

This project is open-source and intended for learning purposes.

Feel free to explore, modify, and learn from the code.

---

🔥 *Built from scratch to understand everything.*
