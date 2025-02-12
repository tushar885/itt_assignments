# Implement Stack Using Array

## Requirements:

- Implement a stack using an array.
- Include the following operations:

### Operations:

1. **push**: Add an element to the stack.
2. **pop**: Remove the top element from the stack.
3. **peek**: Retrieve the top element without removing it.
4. **isEmpty**: Check if the stack is empty.
5. **size**: Return the number of elements in the stack.

---

## **Time Complexity Analysis**:

| Operation     | Complexity |
| ------------- | ---------- |
| **push()**    | O(1)       |
| **pop()**     | O(1)       |
| **peek()**    | O(1)       |
| **isEmpty()** | O(1)       |

- All operations run in constant time **O(1)** because they involve simple array index manipulation.

---

## **Space Complexity Analysis**:

- **O(N)** where **N** is the maximum size of the stack.
- Additional space used is constant **O(1)** (for storing `stackTop` variable).

---

### **Conclusion**:

- This implementation is efficient with all operations in **O(1)** time.
- Space complexity is **O(N)** due to the fixed-size array.
- A dynamic stack implementation (using linked lists) could improve flexibility by not restricting the size.
