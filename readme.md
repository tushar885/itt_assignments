# Problem Statement: Sort a Linked List Alternately in Ascending and Descending Order

## Description

You are given a singly linked list of integers. The task is to rearrange the linked list such that:

1. Nodes at **odd positions** (1st, 3rd, 5th, etc.) are sorted in **ascending order**.
2. Nodes at **even positions** (2nd, 4th, 6th, etc.) are sorted in **descending order**.

The final linked list should preserve the alternate arrangement of nodes.

## Example

### Input:

```
10 40 53 30 4 50 89
```

### Output:

```
4 50 10 40 53 30 89
```

### Explanation:

- Nodes at odd positions: `10, 53, 4, 89` → Sorted in ascending order: `4, 10, 53, 89`
- Nodes at even positions: `40, 30, 50` → Sorted in descending order: `50, 40, 30`
- Alternating merge: `4 -> 50 -> 10 -> 40 -> 53 -> 30 -> 89`

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
