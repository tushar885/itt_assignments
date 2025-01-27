## Problem Statement: Linear Search in a Linked List

### Task:

Implement a function to find the N-th occurrence of a target value in a linked list. If the target value occurs less than N times, return `-1`.

### Input:

- A singly linked list with integer values.
- An integer `target` representing the value to search for.
- An integer `N` representing the occurrence number to search for.

### Output:

- The position (1-based index) of the N-th occurrence of the target value in the linked list.
- If the N-th occurrence does not exist, return `-1`.

### Example:

#### Input:

```
1 3 5 3 8 3
3
2
```

#### Output:

```
4
```

#### Explanation:

The target value `3` occurs at positions 2, 4, and 6. The second occurrence is at position 4.

### Constraints:

- The linked list will contain at least one node.
- `1 <= N <= size of the linked list`.
- The values in the linked list can be any integer.

### Complexity Analysis:

- **Time Complexity:** O(n), where n is the number of nodes in the linked list, since we need to traverse the list once to find the N-th occurrence.
- **Space Complexity:** O(1), as we are only using a constant amount of extra space for counting occurrences.
