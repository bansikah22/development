### Arrays
An Array has a :
- Fixed size
- Fast for data retrival
- Compact memory usage if size is known
- Delete operation very hard
- 2D Arrays 
- Arrays comes from java.util package

### Use cases
- Storing and manipulating data
- Implementing data structures like stacks, queues, and linked lists
- Implementing algorithms like sorting, searching, and graph traversal
- Managing data in web applications, such as storing user information, shopping cart items, and comments

**2D Arrays**
- A 2D array is an array of arrays
- A 2D array is a matrix of rows and columns
- A 2D array is declared as `int[][] arr = new int[3][3];`
- A 2D array is accessed as `arr[0][0] = 1;`
- A 2D array is traversed as 
```java
for (int i = 0; i < arr.length; i++) {
    for (int j = 0; j < arr[i].length; j++) {
        System.out.print(arr[i][j] + " ");
    }
    System.out.println();
}
```
### Use cases
- Storing and manipulating data
- Implementing data structures like stacks, queues, and linked lists
- Implementing algorithms like sorting, searching, and graph traversal
