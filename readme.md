# Assignment: Implement a Hash Map in C Using Linked Lists

## Problem Statement

You are required to implement a Hash Map (Dictionary) in C using **separate chaining with linked lists** to handle collisions. Your implementation should support the following operations:

1. **Insert (Put)** – Add a key-value pair to the hash map. If the key already exists, update the value.
2. **Search (Get)** – Retrieve the value associated with a given key.
3. **Delete (Remove)** – Remove a key-value pair from the hash map.
4. **Display** – Print all key-value pairs stored in the hash map.
5. **Exit** – Terminate the program.

## Constraints

- The **keys** will be non-negative integers entered by the user.
- The **values** will also be non-negative integers entered by the user.
- The **hash function** should be modulus-based, i.e.,  
  `hash(key) = key % table_size`.
- The **hash table size** should be fixed (choose a reasonable value, e.g., **10**).
- **Collisions** should be handled using **separate chaining with linked lists**.
- The program should provide a **simple menu-driven interface** for user interaction.
