# Coding Question: Advanced CRUD Operations on a Singly Linked List

## Problem Statement:

Implement a program in C that performs advanced CRUD (Create, Read, Update, Delete) operations on a singly linked list. The linked list will store integers, and your program should provide the following functionalities:

### 1. Create:

- Add a new element at the beginning of the list.
- Add a new element at the end of the list.
- Add a new element at a specific position in the list.

### 2. Read:

- Display all elements of the linked list.

### 3. Update:

- Update the value of the element at the beginning.
- Update the value of the element at the end.
- Update the value of the element at a specific position.

### 4. Delete:

- Delete the element at the beginning.
- Delete the element at the end.
- Delete the element at a specific position.

---

## Input Format:

- The first input is an integer `n`, representing the number of operations to perform.
- For each operation:
  - An integer representing the operation type followed by relevant parameters:
    - `1 x`: Add `x` to the end.
    - `2 x`: Add `x` at the beginning.
    - `3 pos x`: Add `x` at position `pos` (1-indexed).
    - `4`: Display all elements.
    - `5 pos x`: Update the element at position `pos` to `x`.
    - `6`: Delete the first element.
    - `7`: Delete the last element.
    - `8 pos`: Delete the element at position `pos` (1-indexed).

---

## Output Format:

- For each Read operation (`4`), display all elements of the linked list in a single line separated by spaces.
- For Update and Delete operations with invalid positions, output `"Invalid position"`.

---

## Constraints:

- The values of elements are integers within the range \([-10^3, 10^3]\).
- Positions for Add, Update, and Delete are **1-indexed**.
