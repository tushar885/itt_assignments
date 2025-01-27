# Problem: Detect Cycle in a Singly Linked List

## Problem Statement

Given the head of a singly linked list, determine if the list has a cycle. A cycle exists if any node in the list points back to a previous node, creating a loop. If a cycle exists, return `true`; otherwise, return `false`.

### Input Format:

- The input consists of the following:
  - A linked list where each node contains an integer value `val` and a pointer `next` to the next node.
  - An integer `pos` representing the position of the node where the cycle begins. If there is no cycle, `pos` is `-1`. If `pos` is a valid index, it indicates the node where the last node’s `next` points to.

### Output Format:

- Return `true` if a cycle is detected in the list, otherwise return `false`.

### Example:

#### Example 1:

Input:

```
3 2 0 4
1
```

Explanation:
The list contains a cycle where the last node points back to the second node.
So, the output should be `true`.

Explanation:
The list has no cycle.
So, the output should be `false`.

### Constraints:

- The number of nodes in the list is in the range `[0, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- `pos` is `-1` or a valid index in the list (0-based).

### Approach:

You can detect a cycle in a singly linked list using the **Floyd’s Tortoise and Hare Algorithm** (also known as the fast and slow pointer technique). The key steps are:

1. **Initialize two pointers**:

   - `slow` pointer moves one step at a time.
   - `fast` pointer moves two steps at a time.

2. **Traverse the list**:

   - If there’s no cycle, the `fast` pointer will eventually reach the end of the list (`null`).
   - If there is a cycle, the `fast` pointer will eventually meet the `slow` pointer.

3. **Return the result**:
   - If `fast` pointer meets `slow` pointer, return `true` (cycle detected).
   - If `fast` pointer reaches the end of the list (`null`), return `false` (no cycle).

### Time and Space Complexity:

- **Time Complexity**: `O(n)` where `n` is the number of nodes in the linked list. Both pointers traverse the list at most once.
- **Space Complexity**: `O(1)` as we are using only two pointers and no extra space is used for the cycle detection process.
