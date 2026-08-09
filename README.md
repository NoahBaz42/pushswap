*This project has been created as part of the 42 curriculum by nbaz-sil, bpassos-*

# Description

Pushswap is a program that sorts integers on a stack, with a limited set of instructions.

Using the lowest possible number of actions, pushswap manipulates various types of algorithms and chooses the most appropriate solution (out of many) for
optimized data sorting.

# Instructions

### Compiling the program:


```
make
```


### after that, you can run the program with your desired integers:

```
./pushswap 42 67 69 420 911 123 321
```

>## Flags

### --simple

The simple algorithm O(n2) is set as default to sort the 
numbers with min/max extraction.

example:
> ```
> ./pushswap --simple 67 69 42 420 911 123 321
> ```
### --medium 

The medium algorithm O(n√n) is set as default to sort the integers with chunk-based sorting (dividing into √n chunks) 

example:

>```
>./pushswap --medium 67 69 420 911 123 321
>```
### ---complex 

The complex algorithm O(n log n) is set as default to sort the values with radix sort adaptation 

example:

>```
>./pushswap --complex 67 69 420 911 42 123 321
>```

### the flags above will force the program to use the chosen algorithms
	
	If the number of values to sort is equal to 3 or 5, the program will automaticaly use a personalized sorting, regardless of the flags inputted.

### --adaptive

The adaptive strategy selects different internal methods depending on the measured disorder.

"You must document in your repository (e.g., README.md) the rationale for your
thresholds, the internal techniques used in each regime, and a brief complexity
argument (upper bounds) for time and space within the Push_swap model."

example:

>```
>./pushswap --adaptive 67 69 420 911 123 321 42
>```





### --bench

The benchmark mode will display:
* The computed disorder;
* The strategy used and its complexity level;
* The total number of operations; 
* The count for each of the operations;



example:

>```
>./pushswap --bench --adaptive 67 42 69 420 911 123 321
>```
