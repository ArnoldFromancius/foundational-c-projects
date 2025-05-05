Data Structures in C

This folder contains C implementations of fundamental data structures. These projects are designed to help you understand how core data structures work under the hood, how memory is managed manually in C, and how these structures can be used in real programs.
📦 Contents

Each directory within this folder represents an individual data structure or related project. Current contents include:

    ✅ Linked List – Singly and/or doubly linked list implementations

    ✅ Stack – Stack implementation using arrays or linked lists

    ✅ Queue – FIFO queue built with arrays or linked lists

    ⚠️ More to come: Trees, Graphs, Hash Tables

    Each subproject includes source files, and some may include test cases or basic usage examples.

🧠 Learning Objectives

    Understand how data structures work at a low level

    Learn to manage dynamic memory using malloc/free

    Practice creating reusable, modular code in C

    Build intuition for runtime complexity and performance

🚀 How to Run

For any data structure implementation:

    Navigate into the specific project folder:

cd linked-list  # or stack, queue, etc.

Compile the code:

gcc -o main *.c
./main

Or, if a Makefile is present:

    make
    ./main

📁 Folder Structure

Example:

data-structures/
├── linked-list/
│   ├── linked_list.c
│   ├── linked_list.h
│   └── main.c
├── stack/
│   ├── stack.c
│   └── main.c
└── queue/
    ├── queue.c
    └── main.c

📌 Notes

    All implementations are written in standard C (C89 or C99 for compatibility).

    Emphasis is placed on readability, simplicity, and educational clarity.

📜 License

This folder is part of the main repository and is licensed under the [MIT License](LICENSE).
