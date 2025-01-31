# Implement Queue Using One Stack

## Requirements:

- Implement a queue using one stack.
- Include the following operations:
  - `enqueue`: Add an element to the queue.
  - `dequeue`: Remove the front element from the queue.
  - `peek`: Retrieve the front element without removing it.
  - `isEmpty`: Check if the queue is empty.
  - `size`: Return the number of elements in the queue.

## Approach:

- Since a stack follows Last-In-First-Out (LIFO) and a queue follows First-In-First-Out (FIFO), we simulate queue operations using recursion.
- **Enqueue**: Push the element onto the stack.
- **Dequeue**:
  1. If the stack has only one element, pop and return it.
  2. Recursively pop all elements, store the last popped element, and push the rest back.
- **Peek**: Similar to `dequeue`, but reinsert all elements after retrieving the front.
- **isEmpty**: Check if the stack is empty.
- **Size**: Return the size of the stack.

## Time Complexity:

- **Enqueue**: \(O(1)\) (Direct push)
- **Dequeue**: \(O(n)\) (Recursive popping and reinsertion)
- **Peek**: \(O(n)\) (Recursive access to front)
- **isEmpty**: \(O(1)\) (Stack check)
- **Size**: \(O(1)\) (Returning stored size)

## Space Complexity:

- **Overall**: \(O(n)\) (Recursive call stack for dequeue and peek)
