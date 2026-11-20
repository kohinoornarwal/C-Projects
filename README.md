<div align="center">

# 💻 C Programming Mini Projects

### Three console-based projects built in **C**

![C](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)
![GCC](https://img.shields.io/badge/Compiler-GCC-green?style=for-the-badge)
![Level](https://img.shields.io/badge/Level-First%20Year-blue?style=for-the-badge)

**Made by Kohinoor Narwal | GF202676017**

</div>

---

## 📖 About

This repository contains three console applications I wrote in C as a first-year student. Together they cover the core topics of the course: **switch case, functions, structures, file handling, strings, loops and random numbers**.

---

## 🗂️ Projects

| # | Project | File | Level | Key Concepts |
|---|---------|------|-------|--------------|
| 1 | 🧮 Simple Calculator | [`simple_calculator.c`](./simple_calculator.c) | Basic | Switch case, operators, functions |
| 2 | 🏦 Bank Management System | [`bank_management.c`](./bank_management.c) | Intermediate | Structures, functions, file handling |
| 3 | 🔑 Password Generator | [`password_generator.c`](./password_generator.c) | Practical | Strings, loops, random functions |

---

## ✨ Features

### 🧮 Simple Calculator
- Addition, subtraction, multiplication, division and modulus
- Menu-driven, repeats until you choose to exit
- Handles division by zero and modulus by zero

### 🏦 Bank Management System
- Create accounts with an account number, holder name and opening deposit
- Deposit and withdraw money, with checks for invalid amounts and insufficient balance
- Check the balance of any account and display all accounts in a table
- Records are stored in a binary file (`accounts.dat`), so data stays after the program closes

### 🔑 Password Generator
- Choose the password length (4 to 64 characters)
- Choose which character types to include: lowercase, uppercase, digits, symbols
- Generates a random password and lets you generate more without restarting

---

## 🚀 How to Compile and Run

Make sure you have **GCC** installed, then:

```bash
# Simple Calculator
gcc simple_calculator.c -o calculator
./calculator

# Bank Management System
gcc bank_management.c -o bank
./bank

# Password Generator
gcc password_generator.c -o password
./password
```

> 💡 On Windows, run the generated `.exe` files instead (for example `calculator.exe`).

---

## 📁 Folder Structure

```
c-projects/
├── simple_calculator.c
├── bank_management.c
├── password_generator.c
└── README.md
```

> The bank program creates `accounts.dat` automatically the first time you add an account.

---

## 🧠 Concepts Practiced

- Input and output with `printf` and `scanf`
- Decision making with `if-else` and `switch`
- Loops (`do-while`, `for`)
- User-defined functions
- Structures (`struct`)
- File handling (`fopen`, `fread`, `fwrite`, `fseek`)
- String functions (`strcat`, `strlen`)
- Random numbers with `rand()` and `srand()`

---

## 👨‍💻 Author

**Kohinoor Narwal**
Student ID: **GF202676017**

---

<div align="center">

⭐ If you found this helpful, consider giving the repository a star!

</div>
