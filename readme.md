# Implement Queue Using Two Stacks

## Requirements:

- Implement a queue using two stacks.
- Include the following operations:
  - `enqueue`: Add an element to the queue.
  - `dequeue`: Remove the front element from the queue.
  - `peek`: Retrieve the front element without removing it.
  - `isEmpty`: Check if the queue is empty.
  - `size`: Return the number of elements in the queue.

## Approach:

- Use two stacks (`stack1` and `stack2`) to simulate a queue.
- **Enqueue**:
  - Push the element onto `stack1`.
- **Dequeue**:
  - If `stack2` is empty, move all elements from `stack1` to `stack2`.
  - Pop the top element from `stack2`.
- **Peek**:
  - If `stack2` is empty, move all elements from `stack1` to `stack2`.
  - Return the top element of `stack2`.
- **isEmpty**:
  - Check if both `stack1` and `stack2` are empty.
- **size**:
  - Return the sum of elements in `stack1` and `stack2`.

## Time Complexity:

- **Enqueue**: \(O(1)\) (Push operation on `stack1`)
- **Dequeue**: \(O(n)\) (Moving elements from `stack1` to `stack2` in worst case)
- **Peek**: \(O(n)\) (Similar to `dequeue`, but retains elements)
- **isEmpty**: \(O(1)\) (Checking stack states)
- **Size**: \(O(1)\) (Returning stored sizes)

## Space Complexity:

- **Overall**: \(O(n)\) (Using two stacks to store \(n\) elements)
