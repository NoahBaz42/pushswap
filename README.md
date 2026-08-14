*This project has been created as part of the 42 curriculum by nbaz-sil, bpassos-*

# Description

Pushswap is a program that sorts integers on a stack, with a limited set of instructions. The program uses the maximum os 2 stacks and an already defined set of operations that can be done to execute the sorting.

Using the lowest possible number of actions, push_swap manipulates various types of algorithms and chooses the most appropriate solution (out of many) for
optimized data sorting.

# Instructions

### Compiling the program:


```
make
```


### after that, you can run the program with your desired integers:

```
./push_swap 42 67 69 420 911 123 321
```

>## Operations

### Swap elements

- **sa** (swap a): Swaps the first 2 elements at the top of stack a.
				Do nothing if there is only one or no elements in stack a.
- **sb** (swap b): Swaps the first 2 elements at the top of stack b.
				Do nothing if there is only one or no elements in stack b.
- **ss**: Executes **sa** and **sb** at the same time.

### Push elements

- **pa** (push a): Takes the fist element of stack b and inserts it at the top of stack a.
				Do nothing if there are no elements in stack b.
- **pb** (push b): Takes the fist element of stack b and inserts it at the top of stack a.
				Do nothing if there are no elements in stack b.

### Rotate elements

- **ra** (rotate a): Shifts all elements of stack a up by one.
				The first element becomes the last one.

- **rb** (rotate b): Shifts all elements of stack b up by one.
				The first element becomes the last one.
- **rr**: Executes **ra** and **rb** at the same time.

### reverse rotate elements

- **rra** (rotate a): Shifts all elements of stack a down by one.
				The last element becomes the first one.

- **rrb** (rotate b): Shifts all elements of stack b down by one.
				The last element becomes the first one.

- **rrr**: Executes **rra** and **rrb** at the same time.

>## Flags

### --simple

The simple algorithm O(n2) sorts the 
numbers with min extraction.

example:
> ```
> ./push_swap --simple 67 69 42 420 911 123 321
> ```
### --medium 

The medium algorithm O(n√n) sorts the integers with chunk-based sorting (dividing into √n chunks) 

example:

>```
>./push_swap --medium 67 69 420 911 123 321
>```
### --complex 

The complex algorithm O(n log n) sorts the values with radix sort adaptation 

example:

>```
>./push_swap --complex 67 69 420 911 42 123 321
>```

>	[!NOTE]	the flags above will force the program to use the chosen algorithms
>
>		If the number of values to sort is equal to 3 or 5, the program will automatically use a personalized sorting, regardless of the flags inputted.

### --adaptive

The adaptive strategy selects different internal methods depending on the measured disorder.

**Low disorder**: if disorder is < 0.2, adaptive will chose 0(n2) complexity algorithm.

**medium disorder**: if 0.2 <= disorder > 0.5, adaptive will chose O(n√n) complexity algorithm.

**High disorder**: if disorder is >= 0.5, adaptive will chose O(n log n) complexity algorithm.

>**Note**: If the input size is 3 or 5 elements another algorithm will be used for the sorting instead. This is done to save operations count under low inputs.

example:

>```
>./push_swap --adaptive 67 69 420 911 123 321 42
>```
output:
it should print just the operations.
```
pb
rra
pb
pb
ra
ra
pb
pb
pb
pb
pa
pa
pa
pa
pa
rb
pa
pa
```
### --bench

The benchmark mode will display:
* The computed disorder;
* The strategy used and its complexity level;
* The total number of operations; 
* The count for each of the operations;

example:

>```
>./push_swap --bench --adaptive 67 42 69 420 911 123 321
>```

>```
>[bench] disorder: 23.38%
>[bench] strategy: Adaptive / O(n√n)
>[bench] total_ops: 17
>[bench] sa: 0 sb: 0 ss: 0 pa: 7 pb: 7
>[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
>```
# Algorithm 


## Simple algorithm 0(n2)

For small inputs (n = 3 or n = 5), the program uses a `selection-based` approach. It does so by repeatedly finding the minimum value, rotates the stack to bring it to the top, pushes it to the second stack, and then pushes everything back in order.

This is simple to implement and works well when the input is small, but it becomes expensive for larger stacks because it may require many rotations.

## Medium algorithm O(n√n)

The Medium algorithm uses a `chunk-based sorting` mechanism, where the stack is divided into chunks, and elements are moved to the second stack chunk by chunk. Each size of the chunk is dependent of the number of elements that were selected, in which, size = √n (where n equals to the number of elements selected). Additionally, the program will assign a moving cost value (How costly in terms of number of operations it is to move an element to stack b) to each element of the current chunk. Then it finds and moves the lowest value of chunk to stack b. 

After executing the operations required to move the cheapest value, it will recalculate the cost value for the rest of the remaing elements of the chunk. Once there are no longer elements left in the chunk the algoritm will move to the next lowest index chunk.

After executing all operations to move all chunks to stack a, the algorithm will then sort by finding the maximum value in stack b and executing the optimal rotations needed to push it back to stack a.

This reduces the number of operations compared to a pure selection approach, while staying simpler than a full radix-based solution.

## Complex algorithm O(n log n)

For larger and more disordered inputs, the program uses `radix sort` on normalized indices.

This strategy is a good choice for bigger datasets because it scales much better than quadratic approaches and keeps the number of operations more predictable.

# Disorder: Measuring with O(n²)

The disorder score measures how "out of order" the input stack is, on a scale from 0 (already sorted) to 1 (fully reverse-sorted). It's the value used by `--adaptive` to decide which algorithm to run, and the value printed by `--bench`.

### How it's calculated

For every pair of numbers in the stack, we check whether the first one is bigger than the next . We do this for every number against every number that comes after it.

- **Inverted pair**: any two numbers `a` and `b`, where `a` comes before `b` in the stack, and `a > b`.
- **Total pairs**: every possible pair of numbers in the stack, i.e. `n * (n - 1) / 2` for `n` numbers.

A fully sorted stack has 0 inverted pairs, so `disorder = 0`. A fully reverse-sorted stack has every pair inverted, so `disorder = 1`. Everything else falls somewhere in between depending on how scrambled the input is.


example:
 ```
 ./push_swap --bench --adaptive 67 42 69 420 911 123 321
 ```
> This will print the computed disorder value alongside the algorithm it selected.

# Resources

* [push_swap subject](https://cdn.intra.42.fr/pdf/pdf/207061/en.subject.pdf)

* [w3wchools](https://www.w3schools.com/c/index.php)

* [geeksforgeeks](https://www.geeksforgeeks.org/c/c-programming-language/)

* 42 peers

* AI was used to debug the makefile 

## Contributions

| Login | Contributions |
|-------|--------------|
| nbaz-sil | Parsing, flags |
| bpassos- | Operations, Algorithms|
