## A Queue
- The queue class represents a first-in-first-out (FIFO) queue of objects.
- It extends class `AbstractCollection` and implements the `Queue` interface.
- The usual `enqueue` and `dequeue` operations are provided, as well as methods to peek at the front item, test if the queue is empty, and to search for an item in the queue.
- When a queue is first created, it contains no items.
- A more complete and consistent set of LIFO stack operations is provided by the `Deque` interface and its implementations, which should be used in preference to this class. For example:
  - `Deque<Integer> queue = new ArrayDeque<Integer>();`
  - `queue.add(42);`
  - `int front = queue.remove();`
  - `assert front == 42;`
  - `assert queue.isEmpty();`
  - Queue is a subclass of `AbstractCollection` that implements a standard first-in, first-out queue.
  - When using a queue with multi threads it gets slowed down because of the synchronization overhead.
  - The `LinkedList` class provides a more efficient implementation of the `Queue` interface.

### Use cases
- `Breadth-First Search (BFS)`: Used in graph algorithms like BFS to explore nodes level by level.
- `Resource Sharing`: Manages shared resources among multiple consumers, ensuring fairness.
- `Task Scheduling`: Schedules tasks based on their priority or arrival time.
- `Print Queue`: Manages print jobs in a printer queue, ensuring the order of printing.