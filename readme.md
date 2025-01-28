# Problem Statement: Sort Linked List Based on Frequency and Value

## Description

You are given a singly linked list of integers. The task is to sort the linked list based on the following criteria:

1. **Frequency**: Elements with lower frequency should appear before elements with higher frequency.
2. **Value**: If two elements have the same frequency, they should be sorted in ascending order based on their value.

## Example

### Input:

```
4 2 2 8 4 6 4
```

### Output:

```
8 6 2 2 4 4 4
```

### Explanation:

- Frequency of elements:
  - `8`: 1 occurrence
  - `6`: 1 occurrence
  - `2`: 2 occurrences
  - `4`: 3 occurrences
- Sorted order:
  - First, by frequency: `8 (1), 6 (1), 2 (2), 4 (3)`
  - Then, by value (if frequencies are equal): `6 -> 8`

## Constraints:

- The linked list may contain up to `10^4` nodes.
- Each value in the linked list is a positive integer.

## Complexity Analysis

### Time Complexity:

Using **bubble sort**, the time complexity can be broken down as follows:

1. **Frequency Calculation**: To calculate the frequency of elements, traverse the linked list once, resulting in `O(n)` time complexity.
2. **Bubble Sort**: Sorting the list based on frequency and value involves nested traversal:
   - Each pass takes `O(n)` time.
   - In the worst case, there are `O(n)` passes.
   - Therefore, sorting takes `O(n^2)` time.

Overall time complexity: **O(n^2)**.

### Space Complexity:

- No additional data structures are used for sorting when using bubble sort.
- Space required for frequency calculation (i.e a 2-D array): **O(n)**.

Overall space complexity: **O(n)**.
