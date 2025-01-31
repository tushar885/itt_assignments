# Queue Implementation Using Linked List

## Description

This program demonstrates the implementation of a **Queue** using a **linked list** in C. It includes basic queue operations such as **enqueue**, **dequeue**, **front**, **isEmpty**, and **freeQueue**. A queue follows the **First In First Out (FIFO)** principle.

## Operations:

The following operations are implemented in the queue:

1. **enqueue**: Adds an element to the rear of the queue.

   - **Time Complexity**: O(1)
   - **Space Complexity**: O(1)

2. **dequeue**: Removes the front element from the queue.

   - **Time Complexity**: O(1)
   - **Space Complexity**: O(1)

3. **front**: Retrieves the front element without removing it.

   - **Time Complexity**: O(1)
   - **Space Complexity**: O(1)

4. **isEmpty**: Checks if the queue is empty.

   - **Time Complexity**: O(1)
   - **Space Complexity**: O(1)

5. **freeQueue**: Frees all the memory allocated for the queue.
   - **Time Complexity**: O(n)
   - **Space Complexity**: O(1)

## Example Usage:

1. **enqueue**: Add an element to the queue.
2. **dequeue**: Remove an element from the front of the queue.
3. **front**: Check the front element without removing it.
4. **isEmpty**: Check if the queue is empty.
5. **freeQueue**: Free the memory occupied by the queue.

This queue implementation uses a **linked list** with `front` and `rear` pointers to manage the operations efficiently.

## Structure Definitions:

- **Node**: Represents an individual element in the queue.
  - Contains an integer data and a pointer to the next node.
- **Queue**: Contains two pointers, `front` and `rear`, to keep track of the front and rear of the queue.

## Memory Management:

- The queue is dynamically allocated, and memory for nodes is freed after use via the `freeQueue` function.
