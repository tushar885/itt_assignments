# Implement Stack Using Linked List

## Requirements:

- Implement a stack using a linked list.
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
| **size()**    | O(N)       |

- **Push, Pop, Peek, and isEmpty** run in **O(1)** time since they involve simple pointer operations.
- **Size()** runs in **O(N)** because it traverses the entire stack to count the elements.

---

## **Space Complexity Analysis**:

- **O(N)** where **N** is the number of elements in the stack.
- Unlike an array-based stack, this implementation does not waste memory on unused capacity.

---

### **Conclusion**:

- This approach is more memory-efficient than an array when the number of elements is unknown.
- No fixed-size constraints, making it more flexible.
- Slight overhead due to extra memory used for pointers.
