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
![diagram](./imgs/push_swap_2.png)

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
        t_node *max;
    } t_stack;

    t_stacks *new_stacks();
    t_stacks	*close_stacks(t_stacks **stacks);
    // ... other APIs
    ```
### Algorithm Section

#### Challenges

As per the project requirements, sorting **500 numbers** must be completed within **5500 operations**, implying an nearly **O(n log n)** time complexity. Additionally, with a dual-stack design, the space complexity is restricted to **O(n)**.

#### Analysis

Traditional sorting algorithms like **merge sort** and **quick sort** can theoretically meet the time complexity requirement (quick sort achieves an average of **O(n log n)** but can degrade to **O(n²)** in the worst case). However, there are two key differences in our project that make these algorithms unsuitable:

1. **Read operations** are free, but **write operations** consume the limited number of allowed moves.
2. The stack structure does not allow **random access** to data, making traditional sorting algorithms infeasible.

I came across some discussions about this project online and found several high-quality articles that helped me complete it. For example, [one article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) provided a detailed explanation of the project, and [TUK sorting](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) inspired my final solution. However, I also encountered many solutions that I found difficult to understand—some were complex, some relied on "magic numbers," and others had confusing algorithm descriptions. To be honest, I was also a bit lazy to dive into the longer ones.

My final idea was simple: our goal is to sort 500 numbers within 5500 operations, which also means the average cost per move should be less than 11 operations. So let's do it to optimize each moving, the project can be completed successfully.

This idea aligns with the approach of TUK’s algorithm but differs in implementation. I found the process of finding the optimal solution is heuristic in nature, as it involves a local BFS-based shortest path exploration. This makes it more closely aligned with graph theory principles. To enhance this, I introduced elements of the [A* search algorithm](https://www.geeksforgeeks.org/a-algorithm-and-its-heuristic-search-strategy-in-artificial-intelligence/) into my implementation, which allowed for a more efficient evaluation of potential moves and their costs.

Regrettably, after implementing the **lowest move cost calculation**, I had already achieved the project's goal of sorting 500 numbers in an average of 5500 operations. This outcome fulfilled the requirements and left me without the motivation to implement the **estimated remaining cost** (heuristic) aspect of the A* structure. 

As a result, the algorithm effectively regressed to a **Greedy Selection** approach. While it lacks the full power of A*, this simplified version proved sufficient for the average case. Nevertheless, this indicates that further optimization, such as incorporating heuristics, could still reduce operation counts, particularly in edge cases.

### A*-like Algorithm (Simplified to a Greedy-Based Approach)

#### Move Cost

- **Definition**: The cost of moving an element involves:
  1. Rotating the element to the top of stack A.
  2. Pushing it to stack B.
  3. Rotating stack B to maintain its descending order.

#### Approach

1. **Pruning**: Treat shallow nodes in stack A as **reachable nodes** to limit the depth of exploration and reduce computational complexity.  
2. **Local BFS**: Calculate the **move cost** for each reachable node by exploring all possible operations.  
3. **Greedy Selection**: Select the node with the **lowest move cost** for the next operation.  
4. **Iterative Exploration**: After moving a node to stack B, repeat the process for other reachable nodes until stack A is empty.  
5. **Final Step**: Reverse stack B to restore it to ascending order, completing the sorting process.

#### Optimization

- **Shallow Nodes**: By focusing only on shallow nodes, the algorithm avoids unnecessary deep rotations in stack A.
- **Dual-stack Operations**: Using dual-stack operations like **RR** and **RRR** minimizes the overall cost of rotations, further reducing the total move cost.

#### Implementation

![diagram](../pseudo_code/push_swap.png)

##### Key Points

1. **`plan` Structure**
- During the operation cost calculation, a **`plan` structure** is generated simultaneously.
- This approach decouples **cost calculation** and **execution**, allowing operations to be performed without recalculating costs.

2. **Calculating Rotations for Stack B**
- When determining the number of rotations needed for **stack B** during a push operation, I maintain a pointer `*max` in **stack B** that always points to its maximum element.
- This simplifies finding the correct insertion point, minimizing computational overhead.

3. **Special Scenarios: Maximum and Minimum Values**
- Extra care is required when inserting a value that is either:
  - **Larger than the maximum** in stack B.
  - **Smaller than the minimum** in stack B.
- These edge cases must be handled explicitly to ensure the rotations are calculated correctly.

4. **Maximum Exploration Depth (Pruning)**
- To maintain efficiency, I limit the exploration depth to prevent excessive costs from moving deeply buried elements.
- Ideally, this depth would be dynamically determined based on the number of elements in the stack.
- However, to avoid the complexity of dynamic allocation, I use a **fixed hyperparameter of `60`** as the maximum depth.
  - This is the only "magic number" in the project and was chosen to balance simplicity and performance.

This hybrid approach combines the simplicity of stack operations with the heuristic-driven prioritization of **A\***, ensuring that the sorting process is both efficient and meets the constraints of the project.
