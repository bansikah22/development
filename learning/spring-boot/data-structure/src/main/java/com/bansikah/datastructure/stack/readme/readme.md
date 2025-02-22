## A Stack
- The stack class represents a last-in-first-out (LIFO) stack of objects. 
- It extends class `Vector` with five operations that allow a vector to be treated as a stack. 
- The usual `push` and `pop` operations are provided, as well as a method to `peek` at the top item on the stack, a method to test for whether the stack is empty, and a method to search the stack for an item and discover how far it is from the top.
- When a stack is first created, it contains no items.
- A more complete and consistent set of LIFO stack operations is provided by the `Deque` interface and its implementations, which should be used in preference to this class. For example:
  - `Deque<Integer> stack = new ArrayDeque<Integer>();`
  - `stack.push(42);`
  - `int top = stack.pop();`
  - `assert top == 42;`
  - `assert stack.isEmpty();`
- Stack is a subclass of Vector that implements a standard last-in, first-out stack.
- When using a stack with multi threads it gets slowed down because of the synchronization overhead.

### use cases
- `Expression Evaluation`: Used in evaluating arithmetic expressions, including infix, prefix, and postfix notations.
- `Syntax Parsing`: Helps in parsing expressions, program code, and checking for balanced parentheses.
- `Backtracking Algorithms`: Utilized in algorithms like maze solving, finding paths in a graph, and solving puzzles.
- `Function Call Management`: Manages function calls and local variables in recursive programming.
- `Undo Mechanism`: Implements undo functionality in text editors and other applications.
- `Browser History`: Manages the history of visited web pages, allowing users to navigate back and forth.
- `Tree Traversal`: Used in depth-first search (DFS) algorithms for tree and graph traversal.
- `Memory Management`: Assists in memory allocation and deallocation in low-level programming.
- `String Reversal`: Helps in reversing strings and checking for palindromes.