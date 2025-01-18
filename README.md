# 42_push_swap_project
Push Swap is a C program designed to sort a set of integers using two stacks (a and b) and a set of predefined operations. 
The goal is to output the smallest sequence of operations required to sort the integers in ascending order.

## Objectives
Develop a sorting algorithm to efficiently sort numbers.
Understand algorithm complexity and its impact on performance.
Gain proficiency in writing rigorous, optimized C code.
Sorting algorithms are foundational in computer science and are often discussed in job interviews. This project serves as an introduction to these critical concepts.

## Rules
Initial Setup:

Stack a contains a random set of unique integers (both positive and negative).
Stack b starts empty.

## Goal:
Sort all integers in ascending order in stack a using the available operations.

Allowed Operations:

sa: Swap the top two elements of stack a.
sb: Swap the top two elements of stack b.
ss: Perform sa and sb simultaneously.
pa: Push the top element of stack b onto stack a.
pb: Push the top element of stack a onto stack b.
ra: Rotate stack a (shift all elements up by one, first element becomes last).
rb: Rotate stack b (shift all elements up by one, first element becomes last).
rr: Perform ra and rb simultaneously.
rra: Reverse rotate stack a (shift all elements down by one, last element becomes first).
rrb: Reverse rotate stack b (shift all elements down by one, last element becomes first).
rrr: Perform rra and rrb simultaneously.

## Benchmark
To validate the project, the sorting algorithm must perform within specific operation limits:

Minimal Validation (Grade ≥ 80):
Sort 100 random numbers in fewer than 700 operations.

Maximal Validation (Grade = 100):

Sort 100 random numbers in fewer than 700 operations.
Sort 500 random numbers in fewer than 5500 operations.

## How to Use

### Clone the repository:
git clone
cd push_swap

### Compile the program:
make

### Run the program:
Provide a list of integers as arguments:

./push_swap 4 2 3 1
The program outputs the sequence of operations required to sort the integers.

## Implementation
This project uses a brute force algorithm to find the optimal solution. The algorithm evaluates all possible sequences of operations to determine the minimal one (Maximal Validation for Grade = 100).

## Learning Objectives
Understand sorting algorithms and their complexities.
Practice rigorous programming in C.
Explore the challenges of algorithmic optimization.

## Resources
Ecole 42: This project is part of the Ecole 42 curriculum.
Algorithm Analysis: Study sorting algorithms like bubble sort, quicksort, and merge sort to enhance understanding.
