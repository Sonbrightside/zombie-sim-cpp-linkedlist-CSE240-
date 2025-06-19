
# 🧟 Zombie Conga Party Simulation

**C++ | Data Structures | OOP | Linked List | Randomization | Simulation Design**

This project simulates a dynamic "Conga Line" of zombies using a templated linked list in C++.  
Each zombie is randomly assigned a type (`R`, `Y`, `G`, `B`, `C`, `M`), and a variety of randomized "party actions" manipulate the structure of the list in real time.

---

## 🔧 Key Features

### 🧱 Zombie Class
- Random zombie type generation via `rand()`
- Overloaded comparison operators: `==`, `!=`
- Stream output overloading: `<<` for console printing

### 🔗 Linked List Operations
- Insertions:
  - Add to **front**, **end**, or **any index**
- Deletions:
  - Remove **first occurrence** or **all occurrences** of a zombie type
- Utility:
  - Traverse and print the entire zombie conga line

### 🕹️ Party Actions
Implemented commands that modify the zombie line:
- `engine` – insert at front  
- `caboose` – insert at end  
- `jump in` – insert at random position  
- `you out` – remove first matching zombie  
- `everyone out` – remove all matching zombies  
- `brains` – insert at front, end, and middle  
- `rainbow` – insert zombies of every type  
- `friends` – insert near same type if exists, else add to end

### 🎲 Randomized Simulation Loop
- Game runs for N rounds based on user input
- Behavior influenced by random seed (`-s [seed]`)
- Option for user to continue the party after each round

---

## 🧠 Concepts Demonstrated

- Templated data structures: `LinkedList<Zombie>`
- Object-Oriented Programming:
  - Class encapsulation
  - Separation of logic and behavior
- Operator overloading (`==`, `!=`, `<<`)
- Randomized simulation using `rand()`
- Interactive CLI experience with terminal I/O

---

## 🖥️ Example Output
```
Round: 0
New Zombie: [R] -- Action: Engine!
Size: 1 :: [R]
**************************************************
Round: 1
New Zombie: [G] -- Action: Friends!
Size: 2 :: [G][R]
...
```

---

## 🏗️ How to Compile & Run
```bash
g++ hw5_son_hongju.cpp -o conga
./conga -s 1234
```

> If no seed is given, the simulation uses the current system time.

---

## 📁 File Structure
```
├── hw5_son_hongju.cpp       # Main game logic
├── zombie_son.cpp/h         # Zombie class and operator overloads
├── linkedlist_son.hpp       # Templated LinkedList implementation
├── Makefile (optional)
```

---

## 👨‍💻 Author
**Hongju Son**  
[LinkedIn](https://www.linkedin.com/in/hongju-son-86163625a/) | hson17@asu.edu  
Arizona State University | CSE240 Project
