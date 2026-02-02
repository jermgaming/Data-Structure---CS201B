<div align="center">

# 📚 Data Structures - CS201B

<img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c&logoColor=white" alt="C Language"/>
<img src="https://img.shields.io/badge/Course-CS201B-green?style=for-the-badge" alt="Course"/>
<img src="https://img.shields.io/badge/Status-Active-success?style=for-the-badge" alt="Status"/>
<img src="https://img.shields.io/github/last-commit/jermgaming/Data-Structure---CS201B?style=for-the-badge" alt="Last Commit"/>

<br/>

> 🎓 A comprehensive collection of **Data Structure** implementations and programs in **C** for the CS201B course

[📖 Getting Started](#-getting-started) • 
[📁 Course Structure](#-course-structure) • 
[🎯 Learning Path](#-learning-path) • 
[🤝 Contributing](#-contributing)

</div>

---

## 🌟 Overview

Welcome to the **Data Structures - CS201B** repository! This repository contains well-documented implementations of fundamental data structures and algorithms in C programming language. Each topic includes detailed explanations, code implementations, and practical examples.

```
┌─────────────────────────────────────────────────────────────────┐
│                    DATA STRUCTURES ROADMAP                      │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│   📚 Arrays ──▶ 🔗 Linked Lists ──▶ 📦 Stacks ──▶ 🚶 Queues   │
│                                                                 │
│   Linear Data Structures → Foundation for Complex Algorithms    │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

---

## 📁 Course Structure

<details>
<summary><b>📘 Unit 1 - Introduction</b> (Click to expand)</summary>

### 🔢 Arrays & Searching Algorithms

| Lesson | Topic | Description |
|--------|-------|-------------|
| 1.2 | **Arrays** | Introduction to arrays, memory representation |
| 1.3 | **Array Operations** | Min, Max, Average calculations |
| 1.4 | **Searching** | Binary Search & Linear Search |

#### Key Concepts:
- 📊 Array Declaration & Initialization
- 🔍 Binary Search (Iterative & Recursive)
- 🔎 Linear Search Algorithm
- ⏱️ Time Complexity Analysis

```c
// Binary Search Example
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

</details>

<details>
<summary><b>🔗 Unit 2 - Linked Lists</b> (Click to expand)</summary>

### 🔗 Types of Linked Lists

```
┌──────────────────────────────────────────────────────────────────┐
│                      LINKED LIST TYPES                           │
├──────────────────────────────────────────────────────────────────┤
│                                                                  │
│  Singly Linked List:    [A]──▶[B]──▶[C]──▶[D]──▶ NULL          │
│                                                                  │
│  Doubly Linked List:    NULL ◀──[A]⟷[B]⟷[C]⟷[D]──▶ NULL       │
│                                                                  │
│  Circular Linked List:  [A]──▶[B]──▶[C]──▶[D]──┐                │
│                          └────────────────────────┘              │
│                                                                  │
└──────────────────────────────────────────────────────────────────┘
```

| Lesson | Topic | Key Operations |
|--------|-------|----------------|
| 2.1 | **Singly Linked List** | Insert, Delete, Traverse, Concatenate |
| 2.2 | **Doubly Linked List** | Bidirectional traversal |
| 2.3 | **Circular Linked List** | Circular operations |
| 2.5 | **Lab Programs** | Reverse, Sort, Search |
| 2.6 | **Essential Programs** | Merging, Frequency, Addition |

#### Node Structure:
```c
struct node {
    int data;
    struct node* next;
};
```

</details>

<details>
<summary><b>📦 Unit 3 - Stack</b> (Click to expand)</summary>

### 📦 Stack - LIFO Data Structure

```
┌─────────────────────────────────────────────────────┐
│                    STACK OPERATIONS                  │
├────────────────────────────────────────��────────────┤
│                                                     │
│        ┌───┐                                        │
│        │ 5 │  ← TOP (Last In, First Out)           │
│        ├───┤                                        │
│        │ 4 │                                        │
│        ├───┤                                        │
│        │ 3 │     PUSH ↓    POP ↑                   │
│        ├───┤                                        │
│        │ 2 │                                        │
│        ├───┤                                        │
│        │ 1 │                                        │
│        └───┘                                        │
│                                                     │
│   Operations: push(), pop(), peek(), isEmpty()     │
│                                                     │
└─────────────────────────────────────────────────────┘
```

| Lesson | Topic | Description |
|--------|-------|-------------|
| 3.1 | **Introduction** | Stack fundamentals |
| 3.2 | **Stack Operations** | Array & Linked List implementation |
| 3.3 | **Applications** | Reversing, Recursion, Expression evaluation |
| 3.5 | **Essential Programs** | Next Greater Element, Expression conversion |

#### Applications Covered:
- 🔄 Reversing arrays and strings
- 📝 Expression evaluation
- 🔁 Understanding Tail Recursion
- 🔢 Next Greater Element

```c
// Stack using Array
void push(int element) {
    if(top == size - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    arr[++top] = element;
}
```

</details>

<details>
<summary><b>🚶 Unit 4 - Queue</b> (Click to expand)</summary>

### 🚶 Queue - FIFO Data Structure

```
┌────────────────────────────────────────────────────────────────┐
│                      QUEUE OPERATIONS                           │
├────────────────────────────────────────────────────────────────┤
│                                                                 │
│   FRONT                                              REAR       │
│     ↓                                                  ↓        │
│   ┌───┬───┬───┬───┬───┐                                        │
│   │ 1 │ 2 │ 3 │ 4 │ 5 │   ←── Enqueue (Add to rear)           │
│   └───┴───┴───┴───┴───┘                                        │
│     ↑                                                           │
│     └── Dequeue (Remove from front)                            │
│                                                                 │
│   First In, First Out (FIFO) Principle                         │
│                                                                 │
└────────────────────────────────────────────────────────────────┘
```

| Lesson | Topic | Description |
|--------|-------|-------------|
| 4.1 | **Queue Operations** | enqueue, dequeue, display, size, isEmpty |
| 4.2 | **Circular Queue** | Efficient memory utilization |
| 4.6 | **Essential Programs** | FIFO implementation |

#### Implementations:
- 📊 Queue using Arrays
- 🔗 Queue using Linked Lists
- 🔄 Circular Queue

```c
// Queue using Linked List
void enqueue(int ele) {
    struct queue* temp = malloc(sizeof(struct queue));
    temp->data = ele;
    temp->next = NULL;
    if(rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}
```

</details>

---

## 🎯 Learning Path

```
                           START HERE
                               ↓
           ┌───────────────────────────────────────┐
           │         📚 UNIT 1: INTRODUCTION       │
           │    Arrays • Searching Algorithms      │
           └───────────────────┬───────────────────┘
                               ↓
           ┌───────────────────────────────────────┐
           │        🔗 UNIT 2: LINKED LISTS        │
           │  Singly • Doubly • Circular Lists     │
           └───────────────────┬───────────────────┘
                               ↓
           ┌───────────────────────────────────────┐
           │           📦 UNIT 3: STACKS           │
           │  LIFO • Applications • Recursion      │
           └───────────────────┬───────────────────┘
                               ↓
           ┌───────────────────────────────────────┐
           │           🚶 UNIT 4: QUEUES           │
           │  FIFO • Circular Queue • Operations   │
           └───────────────────┬───────────────────┘
                               ↓
                          🎉 COMPLETE!
```

---

## 📖 Getting Started

### Prerequisites

- **GCC Compiler** - To compile C programs
- **Basic C Knowledge** - Understanding of C syntax

### ⚡ Quick Start

```bash
# Clone the repository
git clone https://github.com/jermgaming/Data-Structure---CS201B.git

# Navigate to the repository
cd Data-Structure---CS201B

# Compile a program (example)
gcc "Unit 1 - Introduction/1.4 Lesson 4 - Searching/1.4.1. Understanding Binary search.c" -o binary_search

# Run the program
./binary_search
```

---

## 📊 Complexity Reference

| Data Structure | Access | Search | Insertion | Deletion |
|----------------|--------|--------|-----------|----------|
| **Array** | O(1) | O(n) | O(n) | O(n) |
| **Linked List** | O(n) | O(n) | O(1) | O(1) |
| **Stack** | O(n) | O(n) | O(1) | O(1) |
| **Queue** | O(n) | O(n) | O(1) | O(1) |

---

## 📂 Repository Structure

```
📦 Data-Structure---CS201B
├── 📁 Unit 1 - Introduction
│   ├── 📁 1.2 Lesson 2 - Array
│   ├── 📁 1.3 Lesson 3 - Representation of Arrays
│   └── 📁 1.4 Lesson 4 - Searching
│
├── 📁 Unit 2 - Linked Lists
│   ├── 📁 2.1 Lesson 1 - Singly Linked List
│   ├── 📁 2.2 Lesson 2 - Doubly Linked List
│   ├── 📁 2.3 Lesson 3 - Circularly Linked List
│   ├── 📁 2.5 Lab Programs
│   └── 📁 2.6 Essential Programs
│
├── 📁 Unit 3 - Stack
│   ├── 📁 3.1 Lesson 1 - Introduction to Stack
│   ├── 📁 3.2 Lesson 2 - Stack Operations
│   ├── 📁 3.3 Lesson 3 - Applications of Stack
│   └── 📁 3.5 Essential Programs
│
├── 📁 Unit 4 - Queue
│   ├── 📁 4.1 Lesson 1 - Operations of Queue
│   └── 📁 4.6 Essential Programs
│
└── 📄 README.md
```

---

## ✨ Features of Each Program

Each program in this repository includes:

- 📋 **Overview** - Brief description of the program
- 🎯 **Purpose** - Why this program exists
- ✨ **Key Features** - Highlights of the implementation
- 🏗️ **Data Structures Used** - Explanation of structures
- 🔧 **Implementation Details** - Algorithm explanation & function documentation
- 💻 **Compilation & Usage** - How to compile and run
- 📥 **Input/Output** - Expected inputs and outputs
- 📊 **Complexity Analysis** - Time and space complexity
- 🧪 **Example Run** - Sample execution
- ⚠️ **Edge Cases** - Error handling

---

## 🤝 Contributing

Contributions are welcome! Feel free to:

1. 🍴 Fork the repository
2. 🌿 Create a new branch (`git checkout -b feature/improvement`)
3. 💾 Commit your changes (`git commit -m 'Add new feature'`)
4. 📤 Push to the branch (`git push origin feature/improvement`)
5. 🔃 Open a Pull Request

---

## 📜 License

This project is open source and available for educational purposes.

---

<!-- ## 👨‍💻 Author

<div align="center">

**jermgaming**

[![GitHub](https://img.shields.io/badge/GitHub-jermgaming-181717?style=for-the-badge&logo=github)](https://github.com/jermgaming)

</div>

--- -->

<div align="center">

### ⭐ Star this repository if you find it helpful!

<img src="https://img.shields.io/github/stars/jermgaming/Data-Structure---CS201B?style=social" alt="Stars"/>

**Happy Learning! 🚀**

</div>