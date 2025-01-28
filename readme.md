# Problem Statement: Sort Linked List by Parity and Value Using Insertion Sort

## Description

You are given a singly linked list of integers. The task is to rearrange the linked list such that:

1. **All even numbers** appear before **all odd numbers**.
2. Within the group of even numbers, the elements are sorted in **ascending order**.
3. Within the group of odd numbers, the elements are also sorted in **ascending order**.

The sorting should be performed using **insertion sort**.

## Example

### Input:

```
4 3 1 2 7 8 5
```

### Output:

```
2 4 8 1 3 5 7
```

### Explanation:

- Even numbers: `4, 2, 8` → Sorted in ascending order: `2 -> 4 -> 8`
- Odd numbers: `3, 1, 7, 5` → Sorted in ascending order: `1 -> 3 -> 5 -> 7`
- Rearranged list: All even numbers come first, followed by all odd numbers.

## Constraints:

- The linked list may contain up to `10^4` nodes.
- Each value in the linked list is a positive integer.

## Complexity Analysis

### Time Complexity:

Using **insertion sort**, the time complexity can be broken down as follows:

1. **Splitting into Parity Groups**: Traversing the linked list once to separate even and odd numbers takes `O(n)`.
2. **Sorting Each Group**:
   - Sorting the even-number sublist using insertion sort takes `O(k^2)`, where `k` is the size of the even sublist.
   - Sorting the odd-number sublist using insertion sort takes `O(m^2)`, where `m` is the size of the odd sublist.
3. **Merging the Groups**: Combining the sorted even and odd sublists takes `O(1)` (appending the odd list after the even list).

Overall time complexity: **O(n^2)** (due to insertion sort).

### Space Complexity:

- Splitting the list into even and odd sublists does not require additional storage (just rearranging pointers).
- Insertion sort is performed in-place.

Overall space complexity: **O(1)**.
