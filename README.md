*This project has been created as part of the 42 curriculum by nbaz-sil, bpassos-*

# Description

Pushswap is a program that sorts integers on a stack, with a limited set of instructions.

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
### ---complex 

The complex algorithm O(n log n) sorts the values with radix sort adaptation 

example:

>```
>./push_swap --complex 67 69 420 911 42 123 321
>```

>[!NOTE]
>the flags above will force the program to use the chosen algorithms
>
>	If the number of values to sort is equal to 3 or 5, the program will automatically
		use a personalized sorting, regardless of the flags inputted.

### --adaptive

The adaptive strategy selects different internal methods depending on the measured disorder.

example:

>```
>./push_swap --adaptive 67 69 420 911 123 321 42
>```

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

# Algorithm 

each one of the difficulty selectors chooses a type of algorithm.

## Simple algorithm 0(n2)

For small inputs, the program uses a selection-based approach. It does so by repeatedly finding the minimum value, rotates the stack to bring it to the top, pushes it to the second stack, and then pushes everything back in order.

This is simple to implement and works well when the input is small, but it becomes expensive for larger stacks because it may require many rotations.

## Medium algorithm O(n√n)

The Medium algorithm uses a chunk-based sorting mechanism, where the stack is divided into chunks, and values are moved to the second stack chunk by chunk.

This reduces the number of operations compared to a pure selection approach, while staying simpler than a full radix-based solution.

## Complex algorithm O(n log n)

For larger and more disordered inputs, the program uses radix sort on normalized indices.

This strategy is a good choice for bigger datasets because it scales much better than quadratic approaches and keeps the number of operations more predictable.

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
