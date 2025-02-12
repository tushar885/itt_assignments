# Implement Stack Using Two Queues

## Requirements:

- Implement a stack using two queues.
- Include the following operations:
  - `push`: Add an element to the stack.
  - `pop`: Remove the top element from the stack.
  - `peek`: Retrieve the top element without removing it.
  - `isEmpty`: Check if the stack is empty.
  - `size`: Return the number of elements in the stack.

## Approach:

- Use two queues (`q1` and `q2`) to simulate stack behavior.
- **Push**: Enqueue the element into `q1`.
- **Pop**: Transfer all elements except the last from `q1` to `q2`, dequeue the last element, then swap `q1` and `q2`.
- **Peek**: Similar to `pop`, but reinserts the last element back into `q2` before swapping.
- **isEmpty**: Checks if `q1` is empty.
- **size**: Returns the size of `q1`.

## Time Complexity:

- **Push**: \(O(1)\) (Direct enqueue)
- **Pop**: \(O(n)\) (Moving elements between queues)
- **Peek**: \(O(n)\) (Moving elements to find the top)
- **isEmpty**: \(O(1)\) (Checking queue state)
- **Size**: \(O(1)\) (Returning stored size)

## Space Complexity:

- **Overall**: \(O(n)\) (Using two queues to store \(n\) elements)
