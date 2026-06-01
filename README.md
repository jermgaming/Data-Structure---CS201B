# Queue Implementations in C*Educational repository demonstrating various queue data structures and algorithms.*

---

## Table of Contents
1. [Project Overview](#project-overview)  
2. [File & Folder Structure](#file--folder-structure)  
3. [Implementation Details](#implementation-details)  
   - 3.1 [Array‑Based Queue](#array‑based-queue)  
   - 3.2 [Linked‑List Queue](#linked‑list-queue)  
   - 3.3 [Circular Queue](#circular-queue)  
   - 3.4 [Queue using Two Stacks](#queue-using-two-stacks)  
   - 3.5 [Double‑Ended Queue (Deque)](#double‑ended-queue-deque)  
   - 3.6 [Sliding Window Maximum](#sliding-window-maximum)  
   - 3.7 [Lab Programs](#lab-programs)  
4. [How to Compile & Run](#how-to-compile--run)  
5. [Data Structures & Algorithms Used](#data-structures--algorithms-used)  
6. [Key Concepts Demonstrated](#key-concepts-demonstrated)  

---

## Project Overview
This repository contains a series of C programs that implement **queues** in multiple ways:

* **Static arrays** – simple fixed‑size queues.  
* **Dynamic linked lists** – queues that grow/shrink at runtime.  
* **Circular arrays** – efficient use of space with wrap‑around indexing.  
* **Two‑stack queue** – queue built from two LIFO stacks.  
* **Double‑ended queue (deque)** – supports insertion/removal at both ends.  
* **Sliding window maximum** – applies queue concepts to solve a classic sliding‑window problem.

All programs focus on the core queue operations **enqueue**, **dequeue**, **display**, **size**, and **emptiness**, while also handling overflow/underflow conditions.

---

## File & Folder Structure
```
Unit 4 - Queue/
├─ 4.1 Lesson 1 - Operations of Queue/
│   ├─ 4.1.2  Implementation of Queue using Arrays - enqueue() and display().c
│   ├─ 4.1.3  Implementation of Queue using Arrays - dequeue(), size() and isEmpty().c
│   ├─ 4.1.4  Operations on Queue using Arrays.c
│   ├─ 4.1.5  Implementation of Queue using Linked List - enqueue() and display().c
│   ├─ 4.1.6  Implementation of Queue using Linked List - dequeue(), size() and isEmpty().c
│   ├─ 4.1.7  C program to implement different Operations on Queue using Linked Lists.c
│   └─ 4.1.8  Implementation of Queues using two stacks.c
├─ 4.2 Lesson 2 - Circular Queues/
│   └─ 4.2.2  Implementation of Circular Queue using Arrays - enqueue() and display().c
├─ 4.3 Lesson 3 - Double Ended Queue/
│   └─ 4.3.4  Implementation of double ended queue using linked list - inject, eject and display operations.c
├─ 4.5 Lab Programs/
│   ├─ 4.5.1  Stack Using Two Queues.c
│   ├─ 4.5.2  Queue Using Two Stacks.c
│   └─ 4.5.4  Sliding Window Maximum.c
└─ 4.6 Essential Programs/
    └─ 4.6.1  Write a program to insert an element in a Queue in FIFO order.c
```

*Each `.c` file is a self‑contained program that can be compiled and executed independently.*

---

## Implementation Details  

### 3.1 Array‑Based Queue
**Files:** `4.1.2`, `4.1.3`, `4.1.4`, `4.1.6`, `4.1.7`  

* **Data Structure:** Fixed‑size integer array (`queue[MAX]`).  
* **Key Functions:**  
  * `enqueue(int x)` – adds element to the rear; checks for overflow (`rear == MAX-1`).  
  * `dequeue()` – removes element from the front; checks for underflow (`front == -1` or `front > rear`).  
  * `display()` – prints elements from `front` to `rear`.  
  * `size()` – returns `rear - front + 1` when the queue is non‑empty.  
  * `isEmpty()` – checks if `front == -1`.  

* **Algorithm:** Simple linear traversal for display; constant‑time enqueue/dequeue.

### 3.2 Linked‑List Queue
**Files:** `4.1.5`, `4.1.6`, `4.1.7`  

* **Data Structure:** Nodes (`struct queue`) linked together; `front` points to the first node, `rear` to the last.  
* **Key Functions:**  
  * `enqueue(int element)` – allocates a node, links it at `rear`.  
  * `dequeue()` – removes the front node, frees its memory.  
  * `display()` – traverses the list printing each `data`.  
  * `size()` – counts nodes while traversing.  
  * `isEmpty()` – checks `front == NULL`.  

* **Algorithm:** Dynamic memory allocation; O(1) enqueue/dequeue; O(n) for size and display.

### 3.3 Circular Queue
**File:** `4.2.2`  

* **Data Structure:** Fixed‑size array (`queue[MAX]`) with two indices `front` and `rear`.  
* **Key Functions:**  
  * `enqueue(int x)` – inserts at `rear` (wrapping around) and checks overflow (`rear == MAX-1`).  
  * `display()` – prints elements from `front` to `rear` handling the circular nature.  

* **Algorithm:** Uses modular arithmetic (implicit via index checks) to achieve wrap‑around, achieving O(1) operations with better space utilization.

### 3.4 Queue using Two Stacks
**File:** `4.1.8`  

* **Data Structure:** Two stacks (`stack1`, `stack2`) implemented as linked lists. The queue is the logical FIFO order obtained by moving elements from `stack1` to `stack2`.  
* **Key Functions:**  
  * `push(stk* stack, int x)` – standard stack push (linked list).  
  * `pop(stk* stack)` – stack pop, returns the top element.  
  * `enqueue(int ele)` – pushes onto `stack1`.  
  * `dequeue()` – if `stack2` empty, pops all from `stack1` and pushes onto `stack2`; then pops from `stack2`.  
  * `display()` – prints contents of both stacks in order.  

* **Algorithm:** Amortized O(1) for enqueue and dequeue; demonstrates the classic “queue‑from‑two‑stacks” technique.

### 3.5 Double‑Ended Queue (Deque) – Linked List
**File:** `4.3.4`  

* **Data Structure:** Doubly linked list‑like nodes (`struct queue`) with a single `next` pointer; `front` and `rear` pointers manage both ends.  
* **Key Functions:**  
  * `inject(int ele)` – inserts at the **rear** (similar to normal enqueue).  
  * `eject()` – removes from the **rear**; handles underflow and the case of a single element.  
  * `display()` – traverses from `front` to `rear` printing elements.  

* **Algorithm:** Linear traversal for `eject` to locate the node before `rear`; O(n) for rear removal in this simple implementation.

### 3.6 Sliding Window Maximum
**File:** `4.5.4`  

* **Problem:** Given an array `arr[]` and window size `k`, output the maximum of each contiguous sub‑array of length `k`.  
* **Approach:** Simple O(n·k) nested loops (as shown) – suitable for educational purposes.  
* **Key Functions:** `max(int a, int b)` helper; main logic iterates over windows and finds the maximum.  

* **Algorithm:** Brute‑force; demonstrates sliding‑window concept and nested iteration.

### 3.7 Lab Programs
* **`4.5.1 Stack Using Two Queues`** – implements stack operations (`push`, `pop`, `peek`, `isEmpty`) using two FIFO queues.  
* **`4.5.2 Queue Using Two Stacks`** – similar to the two‑stack queue but written as a minimal demonstration (prints first and last elements).  
* **`4.5.4 Sliding Window Maximum`** – already described above.

---

## How to Compile & Run
All programs are standard C99 console applications.

```bash
# Example: compile the array‑based queue (4.1.2)
gcc -Wall -Wextra -std=c99 -o array_queue 4.1.2_Implementation_of_Queue_using_Arrays_-_enqueue%20and_display%28%29.c

# Run and provide input as prompted
./array_queue
```

*Replace the source file name with the appropriate one for each program.*  
Typical input format:

1. **Array‑based / Circular / Linked‑list queues** – first integer `n` (number of elements), followed by `n` integers to enqueue.  
2. **Deque** – may require specific commands (`inject`, `eject`).  
3. **Sliding Window Maximum** – first integer `n`, then `n` array values, then window size `k`.  

Output is printed to the terminal; errors such as overflow or underflow are shown with descriptive messages.

---

## Data Structures & Algorithms Used
| Structure | Implementation | Complexity (Key Ops) |
|-----------|----------------|----------------------|
| **Array** | Fixed‑size static array | Enqueue/Dequeue: O(1); Display: O(n) |
| **Linked List** | Dynamically allocated nodes | Enqueue/Dequeue: O(1); Size/Display: O(n) |
| **Circular Buffer** | Array with wrap‑around indices | Enqueue/Dequeue: O(1); Display: O(n) |
| **Two Stacks** | Two LIFO stacks (linked list) | Enqueue: O(1); Dequeue: Amortized O(1) |
| **Deque (Linked)** | Single‑linked list with front/rear pointers | Inject/Eject: O(n) (rear ejection) |
| **Sliding Window** | Nested loops (brute‑force) | O(n·k) time, O(1) extra space |

---

## Key Concepts Demonstrated
* **FIFO (First‑In‑First‑Out) semantics** – core queue behavior.  
* **Overflow & Underflow handling** – checking capacity before insertion and emptiness before deletion.  
* **Dynamic memory management** – `malloc`/`free` in linked‑list implementations.  
* **Pointer manipulation** – linking nodes, updating `front`/`rear` pointers.  
* **Algorithmic thinking** – using two stacks to simulate a queue, sliding‑window maximum pattern.  
* **Modular arithmetic** – circular queue index wrap‑around.  
* **Code hygiene** – consistent function signatures, clear error messages, and separation of concerns (e.g., `print` helper in the first program).  

---

*This repository is intended for learning and experimentation with fundamental queue implementations in C.*