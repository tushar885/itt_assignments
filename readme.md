# Problem Statement: Sort a Linked List Alternately in Ascending and Descending Order

## Description

You are given a singly linked list of integers. The task is to rearrange the linked list such that:

1. Nodes at **odd positions** (1st, 3rd, 5th, etc.) are sorted in **ascending order**.
2. Nodes at **even positions** (2nd, 4th, 6th, etc.) are sorted in **descending order**.

The final linked list should preserve the alternate arrangement of nodes.

## Example

### Input:

```
10 40 53 30 67 12 89
```

### Output:

```
10 89 30 67 40 53 12
```

### Explanation:

- Nodes at odd positions: `10, 53, 67, 89` → Sorted in ascending order: `10, 30, 40, 67`
- Nodes at even positions: `40, 30, 12` → Sorted in descending order: `89, 67, 53, 40, 12`
- Alternating merge: `10 -> 89 -> 30 -> 67 -> 40 -> 53 -> 12`

## Constraints:

- The linked list may contain up to `10^4` nodes.
- Each value in the linked list is a positive integer.

## Complexity Analysis:

### Time Complexity:

Using **selection sort**, the time complexity can be broken down as follows:

1. **Splitting the List**: Traversing the linked list once to separate nodes into two sublists takes `O(n)`.
2. **Sorting Each Sublist**:
   - Selection sort on the odd-position sublist takes `O(k^2)`, where `k` is the size of the odd sublist.
   - Selection sort on the even-position sublist takes `O(m^2)`, where `m` is the size of the even sublist.
3. **Merging**: Combining the sorted sublists alternately takes `O(n)`.

Overall time complexity: **O(n^2)** (due to selection sort).

### Space Complexity:

- Space for storing the two sublists: **O(n)**.
- Selection sort is an in-place algorithm, so no additional space is required for sorting.

Overall space complexity: **O(n)**.
