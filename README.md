# Computer Programming (in C) Monsoon 2022 


### Lec 20: Recursion I
Factorial | Fibonacci | n choose k   
Slides | [factorial.c](lec1/factorial.c) | [fib.c](lec1/fibonacci.c) | [choose.c](lec1/choose.c)  
Read:
- https://redirect.cs.umbc.edu/~chang/cs202.f98/readings/recursion.html
- Section 7.3 in https://hal.inria.fr/hal-02383654/file/ModernC.pdf
- https://web.mit.edu/6.005/www/fa15/classes/10-recursion/
  
Solve:
- Write a program which prints all permutations of numbers from n to n+k-1. Input is n,k. (see slides last page).
- Write a program which takes input a number n, and an nxn matrix and outputs the determinant of that matrix. 

### Lec 21: Recursion II 
Euclids GCD | Fibonacci using Cache | Determinant | Typedef | Enumerating Permutations  
[slides](lec2/lec2.md) | [fib_cache.c](lec2/fib_cache.c) | [det.c](lec2/det.c) | [perm.c](lec3/perm.c)   
Read:
- https://en.wikipedia.org/wiki/Recursion_(computer_science)
  
Solve:
- Write a recursve program to find the shortest path from (1,1) to (n,n) in an nxn grid with obstacles. (see slides for some ideas).
- Write a program for enumerating all k element subsets of an arbitrary n sized set. Algorithm should work on n = 20, k=10 reasonably fast.  
      - Input: k, n, and S (an arbitary set of n numbers)  
      - Output: Print every subset of S of size k.  
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
- Draw a tree using recursive drawing    Or even better (can be done in 10 lines of code).   
[Solution in Skia (web)](https://fiddle.skia.org/c/7b96d0cb407d99a0e81ed220ba47409c).
Skia Drawing Examples: 1 2 3

### Lec 23: Recursion IV - Mergesort
Mergesort | More GDB | Passing Pointers   
[slides](lec4/slides.md) | [sort.c](lec4/sort.c)  
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
[slides](lec5/slides.md) | [point.c](lec5/point.c) | [draw circles with struct](https://fiddle.skia.org/c/c888ec30005d8af42b3925e4a919336e) | [draw tree with struct](https://fiddle.skia.org/c/71b68e1656277054222b26734ca18610)  
Read:
- https://codeforwin.org/2018/06/structures-in-c-programming-need-and-use.html
- https://beginnersbook.com/2014/01/c-structures-examples/
- Go through the examples: https://github.com/gowthamrajk/Structure-and-Pointers-in-C/tree/main/Structure%20in%20C
- https://www.tutorialspoint.com/cprogramming/c_structures.htm
  
Solve:
- See the comments in the file for the problem statement: [social_nets.c](lec5/social_nets.c) (3 problems are mentioned).

### Lec 25: Abstract Data Type II
Example application of using Structs to build a Reciept/Customer Management System  
[slides](lec6/slides.md) | [srms.c](lec6/srms.c)  
Read:
- Strings in C   
  https://www.programiz.com/c-programming/c-strings | https://www.programiz.com/c-programming/string-handling-functions
- Getting current date time in C  
  https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm

Solve:
- Modify srms.c to include an option 2 for listing all reciepts for a particular customer. On entering option 2, the program should ask for a phone number and then slow the list of reciepts sorted chronologically.
- Modify srms.c to include option 3 giving the total revenue on a particular day. On entering option 3, the program should ask for a day and print out all the reciepts issued on that day followed by the total revenue. 

### Lec 26: Abstract Data Type III
Enums | Social Network application

### Lec 27: Abstract Data Type IV
Memory layout of structs |  string in C

### Lec 28: Multifile Programming
Header files | Make files

### Lec 29: File Handling 
### Lec 30: Command Line Arguments | Macros/Preprocessor
### Lec 31: Func Prog I
Function Pointer, Sorting for an array of struct
Map | Filter 
### Lec 32: Func Prog II | Variadic Function
### Lec 33-36: Project | Revision | C++