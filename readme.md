# Problem Statement: Reorder Delivery Packages

You are tasked with reorganizing a list of delivery packages for a courier service. Each package is represented as a node in a singly linked list, where every node contains the **package weight** in kilograms (an integer).

Due to a processing error, the list of packages is in random order. Your goal is to rearrange the list so that the packages are sorted by their weight in **non-decreasing order**. You should use an efficient sorting algorithm to accomplish this.

---

## Input Format

- A singly linked list where each node contains:
  - `weight` (integer): The weight of the package in kilograms.
  - `next`: A pointer to the next node in the list.

The input is the `head` of the linked list.

---

## Output Format

- Return the `head` of the sorted linked list, where the nodes are ordered by their `weight` in ascending order.

---

## Examples

**Input:**

```
7 3 9 1 14
```

**Output:**

```
1 3 7 9 14
```

---

## Time Complexity

1. **Splitting the List:**  
   Each split operation divides the list into two halves. Since the list is divided repeatedly until we reach individual nodes, this takes \( O(\log n) \) operations.

2. **Merging the Lists:**  
   Merging two sorted linked lists takes \( O(n) \), where \( n \) is the total number of nodes in the list.

3. **Overall Time Complexity:**  
   Since merging is performed at every level of recursion, the total complexity is:
   O(n log n)

---

## Space Complexity

1. **Auxiliary Space:**  
   The recursion stack used during the splitting process requires \( O(\log n) \) space.

2. **In-Place Merging:**  
   The merge operation does not require any extra space as it is performed in place.

3. **Overall Space Complexity:**  
   O(log n)
