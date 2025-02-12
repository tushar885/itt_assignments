# Problem: Maximum Candies Distribution Using Linked List

## Problem Statement

You are given a **singly linked list** of integers where each node represents a pile of candies (size of the pile = node's value). You can divide any pile into any number of smaller piles, but you **cannot merge two piles together**.

You are also given an integer \(k\), representing the number of children. You need to distribute the piles of candies to the children such that:

1. Each child gets the **same number of candies**.
2. Each child can take **at most one pile of candies**, and some piles of candies may go unused.

Return the **maximum number of candies** each child can get.

---

## Input

1. A singly linked list where each node is an integer.
2. An integer k.

---

## Output

- An integer representing the maximum number of candies each child can get.

---

## Examples

### Example 1:

**Input:**

```
5 8 6
3
```

**Output:**

```
5
```

**Explanation:**

- You can split the piles as follows:
  - Pile `5`: Used entirely by one child.
  - Pile `8`: Split into `5` (used by one child) and `3` (unused).
  - Pile `6`: Split into `5` (used by one child) and `1` (unused).
- Each child gets `5` candies.

---

### Example 2:

**Input:**

```
10 20 30
4
```

**Output:**

```
10
```

**Explanation:**

- Each child can take `10` candies. Remaining candies are unused.

---

## Constraints

1. Length of Linked List is between 1 and 10^5
2. Each node's value is between 1 and 10^9
3. k is between 1 and 10^5

---

## Complexity Analysis

### Time Complexity:

1. **Finding Maximum Value**: \(O(n)\), where \(n\) is the number of nodes in the linked list.
2. **Binary Search**: Takes O(log(maxPile)) iterations.
3. **Feasibility Check**: For each binary search iteration, traversing the linked list takes \(O(n)\).

**Total Time Complexity**: O(n · log(maxPile))

---

### Space Complexity:

- O(1): Uses only a few variables for binary search and iteration.
