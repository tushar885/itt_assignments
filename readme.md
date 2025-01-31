# Implement Stack Using One Queue

## Requirements:

- Implement a stack using one queue.
- Include the following operations:
  - `push`: Add an element to the stack.
  - `pop`: Remove the top element from the stack.
  - `peek`: Retrieve the top element without removing it.
  - `isEmpty`: Check if the stack is empty.
  - `size`: Return the number of elements in the stack.

## Approach:

- A single queue is used to implement the stack.
- When pushing an element, it is enqueued normally.
- After enqueuing, all previous elements in the queue are dequeued and enqueued again to maintain the last-in, first-out (LIFO) order.
- `pop` simply dequeues from the front.
- `peek` retrieves the front element without removing it.
- `isEmpty` checks if the queue is empty.
- `size` returns the queue's size.

## Time Complexity:

- **Push**: \(O(n)\) (Reordering elements after each push)
- **Pop**: \(O(1)\) (Direct dequeue)
- **Peek**: \(O(1)\) (Accessing front)
- **isEmpty**: \(O(1)\) (Checking queue state)
- **Size**: \(O(1)\) (Returning stored size)

## Space Complexity:

- **Overall**: \(O(n)\) (Using a queue to store \(n\) elements)
