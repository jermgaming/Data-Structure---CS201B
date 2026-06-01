# Unit 1 – Introduction  
**Essential Programs & Lab Exercises**  

A collection of small C programs that demonstrate fundamental concepts in array handling, searching, sorting, sequence generation, and basic algorithm design. Each source file is a self‑contained example that can be compiled and run independently.

---  

## Project Structure  

```
Unit 1 - Introduction
│
├─ 1.2 Lesson 2 - Array
│   ├─ 1.2.1 Introduction to Arrays.c
│   ├─ 1.2.2 Understanding one dimensional arrays.c
│   └─ 1.2.3 Understanding Multi-dimensional arrays.c
│
├─ 1.4 Lesson 4 - Searching
│   ├─ 1.4.1 Understanding Binary search.c
│   ├─ 1.4.2 Write a Program to Search an element using Binary Search and Recursion.c
│   └─ 1.4.3 Understanding Linear search.c
│
├─ 1.6 Lab Programs
│   ├─ 1.6.3 Submatrix Sum Calculation.c
│   └─ 1.6.7 Search Insert Position.c   *(code not included in the repository)*
│
└─ 1.7 Essential Programs
    ├─ 1.7.1 Sequence Generation.c
    ├─ 1.7.2 Pairs with Given Sum.c
    ├─ 1.7.3 Sort the Array using Selection Sort.c
    ├─ 1.7.4 Sort the products depending upon quantity by using divide and conquer techniques.c
    ├─ 1.7.5 Sort the scores of athletes in descending order.c
    ├─ 1.7.6 Sort the books based on popularity.c
    ├─ 1.7.7 Sort the books according to their price.c
    ├─ 1.7.8 Sort the products depending upon quantity.c
    └─ 1.7.9 Sort the products according to their price by divide and conquer techniques.c
```

---  

## File‑by‑File Overview  

| File | Purpose | Core Algorithm / Data Structure | Key Functions / Concepts |
|------|---------|--------------------------------|---------------------------|
| **1.2.1 Introduction to Arrays.c** | Demonstrates static array initialization and element access. | Fixed‑size integer array (`int arr[10]`). | Direct indexing, `printf`. |
| **1.2.2 Understanding one dimensional arrays.c** | Reads *n* integers into a 1‑D array and prints them. | Dynamic input size, simple loop. | `scanf`, `for` loops, array indexing. |
| **1.2.3 Understanding Multi-dimensional arrays.c** | Reads a matrix (rows × cols) and displays it. | 2‑D array (`int a[rows][cols]`). | Nested loops, multi‑dimensional indexing. |
| **1.4.1 Understanding Binary search.c** | Sorts the array with bubble sort, then performs a binary search for a key. | Bubble sort (O(n²)), binary search (O(log n)). | Missing `/*TODO*/` sections illustrate where code must be added. |
| **1.4.2 Write a Program to Search an element using Binary Search and Recursion.c** | Implements a recursive binary search on a sorted array. | Recursive function `binarySearch`. | Function recursion, base case, divide‑and‑conquer. |
| **1.4.3 Understanding Linear search.c** | Performs a linear search for a key in an unsorted array. | Linear scan (O(n)). | Simple `if` condition, flag variable, early `break`. |
| **1.6.3 Submatrix Sum Calculation.c** | Computes the sum of elements in a rectangular sub‑matrix defined by coordinates. | Direct summation of sub‑matrix entries. | Nested loops over the sub‑matrix bounds. |
| **1.6.7 Search Insert Position.c** | *(code not supplied)* – typical problem: find the index at which a target should be inserted to keep a sorted array ordered. Expected algorithm: binary search or linear scan. |
| **1.7.1 Sequence Generation.c** | Generates a new array where each element (except the last) is the sum of itself and the next element of the original array. | Simple arithmetic transformation of array elements. | Reverse traversal, array indexing. |
| **1.7.2 Pairs with Given Sum.c** | Finds all pairs of array elements whose sum equals a given value `s`. | Double‑nested loops (O(n²)). | Pair detection, counting, printing each pair. |
| **1.7.3 Sort the Array using Selection Sort.c** | Sorts an integer array in ascending order using selection sort. | Selection sort (O(n²)). | Two‑level nested loops, in‑place swapping. |
| **1.7.4 Sort the products depending upon quantity by using divide and conquer techniques.c** | Intended to illustrate a divide‑and‑conquer sort; currently implements a modified bubble sort. | (Incomplete) – algorithm placeholder. | Function stub, incomplete logic. |
| **1.7.5 Sort the scores of athletes in descending order.c** | Sorts an array of scores in descending order using bubble sort. | Bubble sort (O(n²)), dynamic memory allocation. | `malloc`, `free` (not used), reverse ordering comparison. |
| **1.7.6 Sort the books based on popularity.c** | Same as 1.7.5 – reads popularity scores, sorts descending, prints before/after. | Bubble sort (O(n²)), dynamic allocation. | Similar to 1.7.5. |
| **1.7.7 Sort the books according to their price.c** | Reads book prices (floats), sorts ascending using bubble sort, prints with two‑decimal formatting. | Bubble sort (O(n²)), floating‑point array. | `float` array, formatted `printf`. |
| **1.7.8 Sort the products depending upon quantity.c** | Reads product quantities, sorts ascending using bubble sort, prints before/after. | Bubble sort (O(n²)), dynamic allocation. | Integer array, simple printing. |
| **1.7.9 Sort the products according to their price by divide and conquer techniques.c** | Implements a bubble sort for float prices (float array). | Bubble sort (O(n²)). | Float array, formatted output (`%0.2f`). |

> **Note:** Several “divide‑and‑conquer” files (1.7.4, 1.7.9) currently use bubble sort; they serve as placeholders where a more advanced algorithm (e.g., quicksort, mergesort) could be added.

---  

## How to Compile & Run  

All programs use the standard C library only. Compile with `gcc` (or any C99‑compatible compiler):

```bash
gcc -Wall -Wextra -std=c99 -o <output_name> <source_file>.c
```

**Example**

```bash
gcc -Wall -Wextra -std=c99 -o pairs pairs_with_given_sum.c
./pairs
```

**Typical usage**

1. Run the executable.  
2. Provide the required input (e.g., array size, elements, target sum, key, etc.) as prompted.  
3. The program prints the result(s) to `stdout`.

---  

## Algorithms & Data Structures Demonstrated  

| Concept | Files Demonstrating It |
|---------|------------------------|
| **Static & Dynamic Arrays** | 1.2.1, 1.2.2, 1.2.3, 1.7.* (all) |
| **Linear Search** | 1.4.3 |
| **Binary Search (Iterative & Recursive)** | 1.4.1, 1.4.2 |
| **Bubble Sort (Ascending / Descending)** | 1.7.5, 1.7.6, 1.7.8, 1.7.7, 1.7.9, 1.4.1 |
| **Selection Sort** | 1.7.3 |
| **Divide‑and‑Conquer (conceptual placeholder)** | 1.7.4, 1.7.9 |
| **Sequence Generation / Array Transformation** | 1.7.1 |
| **Pair Finding (Two‑Sum)** | 1.7.2 |
| **Submatrix Summation** | 1.6.3 |
| **Search Insert Position (conceptual)** | 1.6.7 (algorithm to be implemented) |
| **Pointers & Dynamic Memory** | 1.7.5, 1.7.6, 1.7.8 (use `malloc`) |
| **Nested Loops & Complexity Analysis** | All sorting/searching programs (O(n²) or O(n) / O(log n)) |

---  

## Key Concepts Demonstrated  

* **Array indexing** (single‑dimensional, multi‑dimensional)  
* **Input handling** (`scanf`) and output formatting (`printf`)  
* **Loop constructs** (`for`, `while`) and nested loops  
* **In‑place sorting** (selection, bubble) – swapping without extra storage  
* **Dynamic memory allocation** (`malloc`) for variable‑size arrays  
* **Algorithmic thinking** – from O(n²) brute‑force methods to O(log n) binary search  
* **Recursion** – base case and self‑call in binary search  
* **Problem‑specific logic** – pair detection, submatrix summation, sequence generation, insertion position calculation  

---  

## License  

The source files are provided for educational purposes under the **MIT License** (or another appropriate open‑source license – specify if needed).  

---  

*End of README.*