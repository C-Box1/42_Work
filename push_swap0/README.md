*This project has been created as part of the 42 curriculum by anyousse & csahyoun.*

# Push Swap

## Description

The Push Swap is a sorting algorithm Project where the goal is to sort a stack of integers A using another stack B and a limited set of stack operations, with the minimum number of moves. The project challenges us to design and implement efficient algorithms under strict constraints, focusing on algorithmic optimization, code quality.

## Instructions

### Compilation

To compile, simply run:

```sh
make
```

### Execution

Run the program with a list of integers as arguments:

```sh
./push_swap 3 2 1 6 5 4
```

You can also use flags for different modes:

- `--simple` : Use the simple algorithm
- `--medium` : Use the medium (chunk-based) algorithm
- `--complex` : Use the complex (radix sort) algorithm
- `--adaptive` : Automatically select the best algorithm
- `--bench` : Print benchmarking statistics after sorting

Example:

```sh
./push_swap --bench 5 1 4 2 3
```

## Algorithms

### Simple Algorithm (Selection Sort)

For small or nearly sorted stacks, a simple sorting algorithm is used  **Selection Sort** (O(n^2)), which works by repeatedly finding the minimum element from the unsorted portion and moving it to the front until the entire stack is sorted.

### Medium Algorithm (Chunk-based)

For medium-sized disordered stacks, a chunk-based algorithm is used. The stack is divided into chunks, and elements are pushed to stack B in groups, then sorted and pushed back. This approach balances operation count and complexity.

### Complex Algorithm (Radix Sort)

For large or highly disordered stacks, a non-comparative radix sort (LSD) is used, which achieves O(n log n) complexity using only the allowed stack operations. This method sorts numbers by processing their binary representation bit by bit.

#### Algorithm Selection

The program can automatically select the best algorithm based on the initial disorder of the stack, or you can force a specific strategy with flags.

## Stack Operations

- **sa (swap a):** Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
- **sb (swap b):** Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
- **ss:** sa and sb at the same time.
- **pa (push a):** Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb (push b):** Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **ra (rotate a):** Shift up all elements of stack a by one. The first element becomes the last one.
- **rb (rotate b):** Shift up all elements of stack b by one. The first element becomes the last one.
- **rr:** ra and rb at the same time.
- **rra (reverse rotate a):** Shift down all elements of stack a by one. The last element becomes the first one.
- **rrb (reverse rotate b):** Shift down all elements of stack b by one. The last element becomes the first one.
- **rrr:** rra and rrb at the same time.

## Resources

- [Radix Sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Stack Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure/)


