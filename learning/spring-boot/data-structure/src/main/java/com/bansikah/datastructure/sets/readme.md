## A Set
- A collection that contains no duplicate elements.
- The Set interface contains only methods inherited from Collection and adds the restriction that duplicate elements are prohibited.
- Two Set objects are equal if they contain the same elements.
- A Set is a useful data structure for storing unique elements and performing set operations like union, intersection, and difference.
- More formally, sets contain no pair of elements e1 and e2 such that e1.equals(e2), and at most one null element.
- As implied by its name, this interface models the mathematical set abstraction.

### Use cases
- Removing duplicates from a collection.
- Checking if a collection contains a specific element.
- Performing set operations like union, intersection, and difference.
- Implementing data structures like sets, multisets, and bags.
- Implementing algorithms like finding unique elements, finding common elements, and finding uncommon elements.

### Set Implementations
- The `HashSet` class provides a hash table implementation of the Set interface.
- The `LinkedHashSet` class provides a hash table and linked list implementation of the Set interface.
- The `TreeSet` class provides a red-black tree implementation of the Set interface.
- The `EnumSet` class provides a specialized Set implementation for enum types.
- The `CopyOnWriteArraySet` class provides a thread-safe implementation of the Set interface.
- The `ConcurrentSkipListSet` class provides a thread-safe implementation of the NavigableSet interface.

### Set Operations
- `Union`: Combines two sets to create a new set containing all unique elements from both sets.
- `Intersection`: Finds common elements between two sets and creates a new set containing those elements.
- `Difference`: Finds uncommon elements between two sets and creates a new set containing those elements.
- `Subset`: Checks if one set is a subset of another set.
- `Superset`: Checks if one set is a superset of another set.
- `Equality`: Checks if two sets are equal.
- `Add`: Adds an element to the set.
- `Remove`: Removes an element from the set.

### Set Methods
- `add(E e)`: Adds the specified element to the set if it is not already present.
- `addAll(Collection<? extends E> c)`: Adds all the elements in the specified collection to the set if they are not already present.
- `clear()`: Removes all elements from the set.