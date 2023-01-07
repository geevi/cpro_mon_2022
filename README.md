# Computer Programming (in C) Monsoon 2022 


### Lec 20: Recursion I
Factorial | Fibonacci | n choose k   
Slides | [factorial.c](lecs/20/factorial.c) | [fib.c](lecs/20/fibonacci.c) | [choose.c](lecs/20/choose.c)  
Read:
- https://redirect.cs.umbc.edu/~chang/cs202.f98/readings/recursion.html
- Section 7.3 in https://hal.inria.fr/hal-02383654/file/ModernC.pdf
- https://web.mit.edu/6.005/www/fa15/classes/10-recursion/
  
Solve:
- Write a program which prints all permutations of numbers from $n$ to $n+k-1$. Input is $n,k$. (see slides last page).
- Write a program which takes input a number $n$, and an $n\times n$ matrix and outputs the determinant of that matrix. 

### Lec 21: Recursion II 
Euclids GCD | Fibonacci using Cache | Determinant | Typedef | Enumerating Permutations  
[slides](lecs/21/lec2.md) | [fib_cache.c](lecs/21/fib_cache.c) | [det.c](lecs/21/det.c) | [perm.c](lecs/21/perm.c)   
Read:
- https://en.wikipedia.org/wiki/Recursion_(computer_science)
  
Solve:
- Write a recursve program to find the shortest path from $(1,1)$ to $(n,n)$ in an $n\times n$ grid with obstacles. (see slides for some ideas).
- Write a program for enumerating all $k$ element subsets of an arbitrary $n$ sized set. Algorithm should work on $n = 20, k=10$ reasonably fast.  
      - Input: $k, n,$ and $S$ (an arbitary set of $n$ numbers)  
      - Output: Print every subset of $S$ of size $k$.  
      - Example: On input 2, 4 and 1 2 3 4, ouput 1 2,  2 3, 3 4, 1 3, 1 4, 2 4.
Explore:
- https://natureofcode.com/book/chapter-8-fractals/
- http://recursivedrawing.com/

### Lec 22: Recursion III
GDB | Recrusive Drawing  
[Recursive Drawing using Skia Fiddle (on web)](https://fiddle.skia.org/c/a9daaaae02da119da3c437a1e04b7037) | [Recursive Drawing using Allegro code](https://github.com/geevi/cpro_allegro)   
Read/Watch:
- GDB Commandline debugging: https://www.youtube.com/watch?v=svG6OPyKsrw
- VSCode debugging: https://www.youtube.com/watch?v=SkhHzpXw8F8
- Visualizing Algo: https://visualgo.net/en/recursion  
  
Solve:
- Draw a tree using recursive drawing 
  <img src="https://raw.githubusercontent.com/geevi/cpro_mon_2022/main/lec3/tree-normal.png" width="100" height="100"> Or even better (can be done in 10 lines of code): <img src="https://raw.githubusercontent.com/geevi/cpro_mon_2022/main/lec3/tree.jpg" width="100" height="100">

[Solution in Skia (web)](https://fiddle.skia.org/c/7b96d0cb407d99a0e81ed220ba47409c).
Skia Drawing Examples: 1 2 3

### Lec 23: Recursion IV - Mergesort
Mergesort | More GDB | Passing Pointers   
[slides](lecs/23/slides.md) | [sort.c](lecs/23/sort.c)  
Read:
- Call by Value/Reference: https://www.scaler.com/topics/c/call-by-value-and-call-by-reference-in-c/
- Passing Multidim array to func: https://solarianprogrammer.com/2019/03/27/c-programming-passing-multi-dimensional-array-to-function/  
  Note that we have been using the last method in the above writeup.
- MergeSort: https://www.ics.uci.edu/~goodrich/teach/cs260P/notes/MergeSort.pdf  
  
Solve:
- Write a recursing program which given an array and a number, returns the position of the number in the array. If the number is not present, returns -1.
- A 2D array M is said to be sorted, if every row and every column of M is sorted. Given an input 2D array, write an progam to sort it. 

### Lec 24:Abstract Data Type I
struct | struct from struct | array of struct | pointer to struct  
[slides](lecs/24/slides.md) | [point.c](lecs/24/point.c) | [draw circles with struct](https://fiddle.skia.org/c/c888ec30005d8af42b3925e4a919336e) | [draw tree with struct](https://fiddle.skia.org/c/71b68e1656277054222b26734ca18610)  
Read:
- https://codeforwin.org/2018/06/structures-in-c-programming-need-and-use.html
- https://beginnersbook.com/2014/01/c-structures-examples/
- Go through the examples: https://github.com/gowthamrajk/Structure-and-Pointers-in-C/tree/main/Structure%20in%20C
- https://www.tutorialspoint.com/cprogramming/c_structures.htm
  
Solve:
- See the comments in the file for the problem statement: [social_nets.c](lecs/24/social_nets.c) (3 problems are mentioned).

### Lec 25: Abstract Data Type II
Example application of using Structs to build a Reciept/Customer Management System  
[slides](lecs/24/slides.md) | [srms.c](lecs/24/srms.c)  
Read:
- Strings in C   
  https://www.programiz.com/c-programming/c-strings | https://www.programiz.com/c-programming/string-handling-functions
- Getting current date time in C  
  https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm

Solve:
- Modify srms.c to include an option 2 for listing all reciepts for a particular customer. On entering option 2, the program should ask for a phone number and then slow the list of reciepts sorted chronologically.
- Modify srms.c to include option 3 giving the total revenue on a particular day. On entering option 3, the program should ask for a day and print out all the reciepts issued on that day followed by the total revenue. 

### Doubt Clearing with Instructor Session I : Pointers and Recursion
[perm.c](revision/perm.c)

### Lec 26: Abstract Data Type III
Enums | Strings in C | Social Network application    
[slides](lecs/25/slides.md) | [enum.c](lecs/25/enum.c) | [str.c](lecs/25/str.c) | [social_net.c](lecs/25/social_nets.c)

Solve:  
- Find mutual friends in social_nets.c  
- Given 2 names, check if they connected through their friends.   
  - Input: 2 strings `name1`, `name2`
  - Output: check if there is a person `p` such that `p` is a friend of `name1` and `name2` is a friend of `p`.


### Lec 27: Abstract Data Type IV
Union | Bitfields |


### Doubt Clearing with Instructor Session II: Structs

### Lec 28: Abstract Data Type V
Problem Solving


### Quiz 2

### Lec 29: File Handling I

### Lec 30: File Handling II

### Lec 31: Multifile Programming
Header files | Make files


### Lec 32: Command Line Arguments | Profiler
### Lec 33: Macros/Preprocessor
### Lec 34: Function Pointer, Sorting for an array of struct
            Map | Filter 
### Lec 35:
### Lec 36: Summary/Conclusion

