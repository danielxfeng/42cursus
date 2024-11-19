## Thoughts on `push_swap`

### Analysis:

In this project, the goal is to implement an integer sorting algorithm using two stacks. The supported operations for the stacks include:

- **Swap** the top elements of a stack (`s` operation),
- **Double-way rotation** (`r` or `rr` operation),
- **Double-rotation** (`rrr` operation),
- **Move** the top element from one stack to the other (`p` operation).

I divided the project into two main parts:
1. **Stack Implementation**: This part involves implementing the stack data structure and exposing the `s`, `r`, `rr`, and `p` operations.
2. **Sorting Algorithm**: The second part focuses on implementing the sorting algorithm.

### Project Structure:

- **Entry Function**: Serves as the entry point of the program, handling input validation, stack initialization, and calling the sorting function to perform the sorting operation.
- **Stack**: Implements the data structure and exposes the necessary stack operations (`s`, `r`, `rr`, `p`).
- **Sorting Function**: Implements the sorting algorithm.
![diagram](./imgs/push_swap_1.png)

### Data Structure:
Initially, I attempted to implement the data structure using a **circular array**. However, I realized that after performing a rotation operation, pushing elements required significant copying, making the circular array unsuitable for this purpose.

As a result, I switched to a **circular doubly linked list**. In my implementation, I decided not to use sentinel nodes, as the common practice of setting the sentinel node’s value to `INT_MAX` or `INT_MIN` was inadequate for white-box testing during evaluation.

Without a sentinel node, **the most important consideration was to avoid infinite loops**. To prevent this, I set the start and end points of the loop/recursion to `root->next` and `root`, respectively.

### Dependency Injection:
In this project, I applied the concept of **dependency injection**. This approach was chosen because it helps achieve better **decoupling** between components and makes **unit testing** more convenient.

    ```c
    int push_swap(int argc, char **argv, void (*apply_sort_func)(t_stacks *))
    {
        t_stacks *stacks;

        ...
        apply_sort_func(stacks);
        free_helper(&stacks);
        return (0);
    }
    ```
This approach allows flexibility in selecting the sorting function and facilitates easier testing by isolating dependencies.

### Object-Oriented Design:
Although C is a procedural language, I adopted an **object-oriented approach** when implementing the stack data structure to improve code organization, reusability, and maintainability.  
The stack's construction and destruction are encapsulated within factory functions, making the code more modular and reusable in different contexts.

    ```c
    typedef struct s_stack
    {
        t_node *root;
        size_t len;
        char label;
    } t_stack;

    t_stacks *new_stacks();
    t_stacks *free_helper(t_stacks **stacks);
    // ... other APIs
    ```
### Sorting Algorithm Discussion

Common optimized sorting algorithms like **merge sort** and **quick sort** have a time complexity of O(n log n) and space complexity of O(1). However, due to the constraints of stack operations, these algorithms cannot be directly applied in this project. Additionally, these algorithms require random access to the data within the stack, which is not possible in this case.

The biggest challenge in the algorithm part of this project is that **common sorting algorithms cannot be directly used** because of the limitations.

Upon observation, we note that, unlike traditional sorting, **reading data is completely free** in this project. The only operation with a cost is writing data.

In my opinion, the only feasible method to implement sorting in this scenario is by swapping elements at the top of the stack (by `p` operation). However, because random access is not allowed, moving each element to the top of the stack (by `r` operation) has a worst-case complexity of O(n), making the overall worst-case writing cost for this double-stack sorting approach **O(n²)**.

#### Let's do some math:

For example, with 500 elements, the project suggests that we aim for **5,500 operations**.  
In theory, **O(n²)** would give us **250,000 operations**.  
However, in practice, as the stack shortens with each operation, the worst-case scenario becomes **125,000 operations**.  
At the same time, with the ability to use `r` and `rr`, the total number of operations reduces to **62,500**.  
On average, we expect around **31,250 operations**.

#### Optimization by `rrr`

We must not forget about the **`rrr` operation**. This operation enables us to move both stacks simultaneously, significantly optimizing the sorting process.

...to be continued

