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

### Sorting Algorithm: A Graph Traversal Approach

To sort 500 numbers within 5500 operations, we face several constraints:
- Traditional sorting algorithms like merge sort or quick sort cannot be used because we lack random access to stack elements.
- **Reading stack elements is free**, but **moving elements incurs a cost**.

Instead of treating this as a traditional sorting problem, I approached it as a [graph traversal problem](https://www.w3schools.com/dsa/dsa_algo_graphs_traversal.php). Here's how:

- Numbers in `stack a` represent **nodes** in an [undirected graph](https://www.geeksforgeeks.org/what-is-unidrected-graph-undirected-graph-meaning/).
- The **cost to move a number** corresponds to the **weight of an edge** between nodes.

#### The Approach

Initially, I planned to use an [A*](https://www.geeksforgeeks.org/a-search-algorithm/)-like heuristic algorithm, combining:
- The **cost of moving a number**.
- An **estimated remaining cost** (similar to shortest-path calculations in graph theory).

However, during implementation, I realized that a simpler **greedy approach**—focusing only on the local optimal move—was sufficient to meet the project's requirements. For this reason, I named my function `astar_sort` as a nod to the original inspiration.

#### Algorithm Overview

The sorting process has two main steps:

1. **Step 1: Move numbers from `stack a` to `stack b`**
   - For each move, pick the number in `stack a` that can be moved to `stack b` with the lowest cost by [BFS](https://www.geeksforgeeks.org/a-search-algorithm/).
   - Maintain `stack b` in sorted order during this process.

2. **Step 2: Move numbers back from `stack b` to `stack a`**
   - Since `stack b` is already sorted, simply move the numbers back in order. This step has a constant cost per operation.

**Actually, there are something missed in "subject.pdf", but apeared in eval table. We have to optimize our algorithm for the 3 and 5 elements sorting. Therefore, the best solution is that: we pushed the numbers from stack a to stack b one by one, until there are only 3 elements in stack_a, and then we push them back by the algorithm below.**


#### A Note on `stack b`'s Order

When we say `stack b` is sorted, we mean that it is **sorted within the context of a circular linked list**:
- The smallest number may not necessarily be at the top of `stack b`.
- Traversing `stack b` in its circular structure will reveal an ordered sequence.

This ordering ensures that Step 2 (moving numbers back to `stack a`) is efficient, as the relative order of the numbers remains intact.

#### Why It Works

- **Avoiding Deep Nodes in `stack a`**: By using a BFS approach to find the optimal node to move, the algorithm avoids accessing deep nodes in `stack a`. In fact, in my implementation, a pruning mechanism ensures that nodes deeper than 30 are never considered, significantly reducing unnecessary operations.

- **Efficient Use of Double Stack Operations**: During the process of moving nodes from `stack a` to `stack b`, maintaining the order of `stack b` allows for effective utilization of double-stack operations like `rr` and `rrr`. These operations simultaneously rotate both stacks, significantly reducing the total number of operations required.

This greedy algorithm efficiently meets the requirements without the need for complex heuristic calculations.
