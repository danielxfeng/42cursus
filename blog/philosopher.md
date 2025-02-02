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
- **Thread Management** – The subject requires one thread per philosopher. Thread creation and initialization are time-consuming. The subject allows up to **200 philosophers**, which means we need to manage up to **200 threads**. We need to handle this properly to avoid failures caused by performance issues.  
- **Write System Calls** – It is frequently used in this project and can introduce unnecessary delays.

### Solution

#### Overall strategy
- A **Coordinator** to handle the message printing, set the **End flag**, and check the **Round Conter** if appliable.
- A state machine for each to perfrom the actions by the different **state** of a Philosopher.
- 

