# Push_swap

A sorting algorithm implemented in C that sorts a set of unique integers using two stacks and a restricted set of operations. The project focuses on algorithmic optimization, computational complexity, stack manipulation, and producing efficient sequences of operations under strict performance constraints.

## Authors

Push_swap is developed as an individual project at 42 École, showcasing practical understanding of algorithm design, computational complexity, data structures, rigorous C programming, and performance optimization.

## Key Features

### Stack-Based Sorting

- Two Stacks: Manage integers using stacks `a` and `b`
- Stack `a`: Contains the initial set of unique integers
- Stack `b`: Starts empty and is used as auxiliary storage
- Integer Support: Handle both positive and negative integers
- Ascending Order: Sort all integers in stack `a` from smallest to largest
- Unique Values: Validate that input values are not duplicated

### Allowed Operations

The program uses only the operations defined by the project:

- `sa`: Swap the top two elements of stack `a`
- `sb`: Swap the top two elements of stack `b`
- `ss`: Perform `sa` and `sb` simultaneously
- `pa`: Push the top element of stack `b` onto stack `a`
- `pb`: Push the top element of stack `a` onto stack `b`
- `ra`: Rotate stack `a`
- `rb`: Rotate stack `b`
- `rr`: Perform `ra` and `rb` simultaneously
- `rra`: Reverse rotate stack `a`
- `rrb`: Reverse rotate stack `b`
- `rrr`: Perform `rra` and `rrb` simultaneously

### Input Validation

- Integer Parsing: Parse command-line arguments as integers
- Signed Integers: Support positive and negative values
- Duplicate Detection: Reject duplicate values
- Invalid Input: Detect malformed or non-numeric arguments
- Integer Range: Validate values against the limits of an integer
- Error Handling: Return an error for invalid input

### Algorithmic Optimization

- Operation Minimization: Reduce the number of operations required to sort the input
- Complexity Analysis: Consider algorithmic complexity and scalability
- Stack Manipulation: Efficiently move and reorder elements between both stacks
- Small Input Optimization: Handle small sets of integers efficiently
- Large Input Optimization: Maintain efficient operation counts for larger datasets
- Performance Constraints: Optimize the algorithm according to the project's benchmark requirements

## Usage Examples

### Compilation

```bash
make
```

### Basic Usage

```bash
./push_swap 4 2 3 1
```

The program outputs the sequence of operations required to sort the integers.

The output can be piped directly into a checker to verify that the resulting stack is correctly sorted.

### Testing With Random Values

```bash
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG
```

The number of generated operations can be measured with:

```bash
./push_swap $ARG | wc -l
```

## Benchmark

The sorting algorithm is evaluated according to the number of operations required for different input sizes.

### Minimal Validation

- Sort 100 random numbers in fewer than 700 operations

### Maximal Validation

- Sort 100 random numbers in fewer than 700 operations
- Sort 500 random numbers in fewer than 5500 operations

These constraints require the implementation to balance algorithmic efficiency with the restricted set of available stack operations.

## Development & Debugging

The implementation was tested using different input sizes and configurations, including:

- Empty input
- Single integer
- Already sorted sequences
- Reverse-sorted sequences
- Small random sequences
- Large random sequences
- Positive integers
- Negative integers
- Mixed positive and negative integers
- Duplicate values
- Invalid input
- Integer boundary values

Testing focuses on:

- Correct stack manipulation
- Correct operation sequences
- Sorting accuracy
- Input validation
- Operation count
- Memory management
- Edge cases

## Security & Memory Considerations

- Input values are validated before processing
- Invalid arguments are rejected without performing undefined operations
- Dynamic memory is properly allocated and released
- Stack operations maintain valid data structures
- The implementation is designed to avoid memory leaks and invalid memory access

## Implementation Notes

This project focuses on algorithmic problem solving using a restricted set of stack operations. The implementation requires designing a sorting strategy capable of handling both small and large datasets while keeping the number of operations within strict limits.

The project provides practical experience with:

- Algorithm design
- Computational complexity
- Stack-based data structures
- Sorting strategies
- Operation optimization
- Input validation
- Memory management
- Rigorous C programming

Push_swap demonstrates how algorithm selection and implementation details directly affect performance, particularly when the solution is evaluated by the number of operations rather than execution time alone.
