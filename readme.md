### Problem Statement:

You are tasked with helping a library organize its book inventory. The library stores book records in a singly linked list, where each node represents a book, and the `data` field of the node stores the unique ID of the book (an integer). The library manager wants the books to be arranged in ascending order of their IDs to make searching for books more efficient.

Due to memory constraints, you cannot use any additional data structures like arrays or vectors to sort the IDs. Design an efficient sorting algorithm to rearrange the linked list so that it satisfies the manager's requirement.

### Input Format:

- A singly linked list of `n` integers, where each integer represents the unique ID of a book.

### Output Format:

- A singly linked list sorted in ascending order of the book IDs.

### Example:

#### Input:

```
5 3 8 6 2 7 4 1
```

#### Output:

```
1 2 3 4 5 6 7 8
```

### Time Complexity:

- **Average and Best Case**: `O(n log n)`
- **Worst Case**: `O(n^2)` (for linked list with unbalanced partitions)

### Space Complexity:

- `O(log n)` (for recursion stack in the Quick Sort algorithm)

### Constraints:

1. The linked list can contain up to `10,000` nodes.
2. Do not use any additional data structures like arrays or vectors.
3. The sorting should be done in-place.
