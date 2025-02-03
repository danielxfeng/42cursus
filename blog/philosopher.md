## Thoughts on `philosopher`

Philosopher is a very interesting project to learn **concurrent programming**. It presents a scenario where multiple philosophers sit around a round table, each with a single fork. However, to eat, a philosopher needs two forks—one from their left and one from their right.

### Game Rules

#### How it works  
Each philosopher follows a cycle of three main states:  

1. **Thinking** – Unless the philosophers are **Eating** or **Sleeping**, they are **Thinking**.  
2. **Eating** – When the philosophers get 2 forks, they start to eat.  
3. **Sleeping** – After eating, they have to sleep.  

#### End of the game    

1. **A philosopher starves** – If a philosopher cannot eat within a given time, they die, ending the game.  
2. **All philosophers eat a specified number of rounds** – The game also ends if all philosophers successfully eat a given number of times (optional rule).  

#### Inputs  
At the start of the game, the following parameters are provided:  

- The **number of philosophers**  
- The **time to eat**
- The **time to sleep**
- The **maximum number of eating rounds** (optional)

### About Concurrent Programming
My experience in [CS 6.824, Distributed Systems from MIT](https://pdos.csail.mit.edu/6.824/index.html) and [15-445, Database Systems from CMU](https://15445.courses.cs.cmu.edu/spring2025/) has helped me build a strong fundamental understanding of concurrent programming.  

- **Thread** – Similar to a lightweight **Process**, a **Thread** is another tool that helps execute tasks concurrently. The key differences include:  
    - **Threads** belong to a **Process**.  
    - Unlike a **Process**, **Threads** in the same **Process** share the same **Heap** space.  
    - Due to shared memory, we must prevent data race to ensure data consistency.  
  You may also find this article interesting: [Concurrency is not Parallelism](https://go.dev/blog/waza-talk).  

- **Data Race** – A **Data Race** happens while multiple **Threads** access the same variable at the same time, at least one of them is writing.
    - The most common scenario is multiple threads trying to modify a shared variable.  
    - Surprisingly, a data race can also occur between multiple readers and a single writer because:  
        - **Cache Coherence** – According to [the memory hierarchy system of our computers](https://www.geeksforgeeks.org/memory-hierarchy-design-and-its-characteristics/), each CPU core has its own cache system. This means a CPU core may read a variable from its local cache instead of reading the latest value written by another core.  
        - **Instruction Reordering** – The compiler/CPU may reorder instructions for optimization, leading to unexpected behaviors.  
        - **Non-Primitive Operations** – If an operation consists of multiple instructions(```++i```), a reader might read partially updated data.  

- **Solutions**  
    - **Mutex**  
        - A synchronization method that prevents data races by ensuring only one thread can access the protected variables.
        - The trade off is the performance because it's expensive.
    - **Atomic**  
        - A lock-free method that allows threads to perform atomic updates to shared variables by hardware supported instructions.
        - Difficult to apply in this project.  

### Challenge

#### The Data Race  
- **Forks** – Since each fork is a shared resource, and the subject explicitly requires using a mutex for each fork, it ensures safety but also introduces the risk of **deadlock** when we have many mutexes.  

- **Round Counter** – This tracks how many rounds a philosopher has eaten. The value is written by a philosopher thread and read by the main/other thread, creating a potential data race.  

- **End Flag** – This indicates the end of the game. Because we cannot print anything after a philosopher dies, there is another possible data race.  

- **Print Operations** – To avoid output overlap, we must also prevent data races between philosopher threads when printing logs.  

#### The Cost of System Calls  
- **Thread Management** – The problem requires one thread per philosopher. Thread creation and initialization can be expensive. Since the problem allows up to **200 philosophers**, we may need to manage up to **200 threads**. We need a proper way to handle it.
- **Write System Call** – `write` syscall is a frequent operation in this project, we need to pay attention to the expense of the cost of syscalls.

### Solution

#### **Overall Strategy**  
- A **Coordinator** is responsible for handling message printing, setting the **End Flag**, and checking the **Round Counter** if applicable.  

- Each philosopher operates as a **State Machine**, transitioning between different **Statuses** (Thinking, Eating, Sleeping).  

- A **Message Queue** is used to handle messages, following a **Multiple Producers, Single Consumer** pattern to centralize logging.  

#### **Message Queue**  
- Implemented using a **circular array buffer**, which consists of an array, two indexes (`read` and `write`), and is protected by a **mutex**.  

- To simplify the implementation, it is a **fixed-length queue**, meaning it must be initialized with a sufficiently large capacity.  

- This approach **reduces Write Syscalls**, centralizes the **printing feature** to ensure message order, and also helps handle game termination, preventing unnecessary logs after the game ends.

- But for this project, actually it can be replaced by just a simple **print when you hold a lock** strategy.

#### **Eating Strategy**  
- If the number of philosophers is **odd**, the odd-indexed philosophers eat first. Once they sleep, the even-indexed philosophers eat.  

- If the number of philosophers is **even**, they are split into three shifts. The **third shift** consists only of the first philosopher.  

#### **Data Race Prevention**  
- **Forks** – An array of **mutexes** represents the forks. When a philosopher locks a mutex, it means they have acquired the fork. To prevent **deadlock**, forks are always acquired in a consistent order (picking up the left fork first, then the right fork).  

- **End Flag** – Since for this project, we cannot print out anything after someone dies, which means the **End Flag** should be protected by a mutex.

- **Print Operations** – Solved by the **Message Queue**.

- **Round Counting** - Initially, I applied a **data race tolerant approach** as an optimization. However, during evaluation, I was told that **no data races are allowed in this project**, which I hadn't noticed before. I modified it to apply **mutex locks for both reads and writes**, ensuring full synchronization.  

#### **My Data Race Tolerant Approach**  

- **What's it?**  
  I hold the lock when writing, but I read without locking.  

- **Why does it work?**  
  When executing `lock` and `unlock`, the implementation of **Mutex** actually performs three tasks:  
  1. Executes these commands as an **atomic operation**.  
  2. Handles the **Memory Barrier**, ensuring **Cache Coherence**.  
  3. Prevents **Instruction Reordering** optimizations.  

  So, when I write with a lock, everything is fine.  

  When I read without a lock, since reading a **32-bit `int`** on an **x86** computer is also a **primitive operation**, the worst-case scenario is that I might read an **outdated** value, not a **corrupted** one. The 1-2 ms delay in ending the game is **totally tolerable**, so this approach works in practice.  

- **Why is it not suitable for this project?**  
  This approach works only under two specific conditions:  
  1. The read operation is a **primitive operation**.  
  2. Reading outdated data is **acceptable** in this context.  

  However, in the **general case**, this is still a **data race**, and due to the project rule **"no data races are allowed"**, all data races are flagged by **Valgrind**.  


#### **Efficiency Improvements**  
- **Thread Management** – When there are **200 philosophers**, CPU usage was nearly **100%** during thread creation, causing the program to fail. To handle this, the game only starts **after all threads are created and initialized**, preventing performance issues.  
- **Write System Calls** – The centralized **Message Queue** prevents excessive logging issues. Although I had a plan called the **batch writing approach**, which involves **printing without locking**, I didn’t implement it since the performance was good enough to pass the tests.  
