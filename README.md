# Compiler Design Lab (CSE 420) - BRAC University

This repository contains the laboratory assignments for the **Compiler Design** course. The project involves building a compiler for a subset of the **C programming language**.

## Compiler Phases

The development is divided into four sequential phases:
* 
**Lab 1: Lexical & Syntax Analysis** – Tokenizing source code using **Flex** and verifying grammar with **Bison/Yacc**.
* 
**Lab 2: Symbol Table Generation** – Implementing a scoped hash table to store identifiers, functions, and their attributes.
* 
**Lab 3: Semantic Analysis** – Performing type checking, uniqueness checking, and function parameter validation.
* 
**Lab 4: Intermediate Code Generation** – Constructing an **Abstract Syntax Tree (AST)** and generating **Three-Address Code (TAC)**.

## Tools Used
* 
**Lex/Flex** (Lexical Analyzer) 
* 
**Yacc/Bison** (Syntax Analyzer) 
* 
**C++** (AST and Symbol Table Logic)

## ⚙️ How to Run

To compile and run the analyzer for any phase:
1. Ensure Flex and Bison are installed.
2. Provide execution permission to the script: `chmod +x script.sh`
3. Run the script: `./script.sh input.c`
