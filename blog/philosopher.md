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

### About concurrent Programming
My experience in [CS 6.824, Distributed System From MIT](https://pdos.csail.mit.edu/6.824/index.html), and [15-445, Database Systems From CMU](https://15445.courses.cs.cmu.edu/spring2025/) has helped me a lot in building a fundamental understanding of concurrent programming.  

Here is also an article I wrote to briefly introduce concurrent programming.

### Challenge

#### The Data Race  
- **Forks** – Since each fork is a shared resource, and the subject explicitly requires using a mutex for each fork, it ensures safety but also introduces the risk of **deadlock** when we have many mutexes.  
- **Round Counter** – This tracks how many rounds a philosopher has eaten. The value is written by a philosopher thread and read by the main/other thread, creating a potential data race.  
- **End Flag** – This indicates the end of the game. Because we cannot print anything after a philosopher dies, there is another possible data race.  
- **Print Operations** – To avoid output overlap, we must also prevent data races between philosopher threads when printing logs.  

#### The Cost of System Calls  
- **Thread Management** – The subject requires one thread per philosopher. Thread creation and initialization are time-consuming. The subject allows up to **200 philosophers**, which means we need to manage up to **200 threads**. We need to handle this properly to avoid failures caused by performance issues.  
- **Write System Calls** – It is frequently used in this project and can introduce unnecessary delays.  

