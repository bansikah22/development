## HashMaps
- HashMaps are used to store key-value pairs.
- The key is used to retrieve the value.
- The value can be any object.
- The key is unique.
- The HashMap class is part of the Java Collections Framework.
- The HashMap class provides methods to:
  - Add key-value pairs.
  - Remove key-value pairs.
  - Retrieve values by key.
  - Check if a key or value exists.
  - Iterate over key-value pairs.
  - Get the size of the map.
  - Check if the map is empty.
  - Clear the map.
  - Perform bulk operations like putAll and removeAll.
  - Get the hash code of the map.
- The HashMap class does not provide any ordering guarantees.

### HashMap Implementations
- The `HashMap` class provides a hash table implementation of the Map interface.
- The `LinkedHashMap` class provides a hash table and linked list implementation of the Map interface.
- The `IdentityHashMap` class provides a hash table implementation with reference-equality in place of object-equality.
- The `WeakHashMap` class provides a hash table implementation with weak keys.
- The `EnumMap` class provides a specialized Map implementation for enum types.
- The `ConcurrentHashMap` class provides a thread-safe implementation of the Map interface.

### HashMap Methods
- `put(K key, V value)`: Associates the specified value with the specified key in the map.
- `get(Object key)`: Returns the value to which the specified key is mapped, or null if the map contains no mapping for the key.
- `remove(Object key)`: Removes the mapping for the specified key from the map if present.
- `containsKey(Object key)`: Returns true if the map contains a mapping for the specified key.

### Use cases
- Storing and retrieving key-value pairs.
- Implementing data structures like dictionaries, hash tables, and associative arrays.
- Implementing algorithms like memoization, caching, and counting frequencies.
- Managing configuration settings in applications.