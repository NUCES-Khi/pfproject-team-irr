#                                                      Programming Fundamentals Lab - Course Project Report

 # **Project Title:** Matrices Calculation Programme
**Instructor Name:** Sir Farooq Zaidi
**Course Title:** Programming Fundamentals - Lab
**Course Code:** CS1002

## Group Members: 
1.Syeda Rija Ali (23K-0057)
2.Riya Bhart (23K-0063)
3.Ibrahim Johar Farooqi (23K-0074)

 
**Proposal Idea**
Project Description: 
Our project aims to reinforce the core concepts and skills we have learned in the course by developing a Matrices Calculation Program. 

These core concepts include:
*Control Structures (If statements & If - Else Statements)
*Switch Statements
*Loops
*Arrays (1D & 2D)
*Functions
*DMA
*Filing 

Project Scope: 
This program will be created in C language, using the “Developer Command Prompt for VS 2022” as the compiler for our program as well as the interface for the program. The program will consist of:
Determinant of nxn Square Matrix
Addition & Subtraction between two Matrices. (mxn)
Multiplication of between two Matrices [(mxn)]
Transpose of a Matrix. 
Convolution of a square Matrix

The program will offer the user the option to choose from the above-mentioned sub-programs that pertain to the use of matrices. For tedious inputs, we will utilise the functionality of filing and dynamic memory allocation. 

**Purpose & Need for this Programme:**
Matrices play a crucial role in various STEM fields, and a program's significance lies in its ability 
to compute determinants for square matrices. This functionality finds applications in quantum mechanics, geometry, linear transformations, 
and stress analysis in engineering. Additionally, the program offers the capability to determine the transpose of matrices, with real-world applications spanning cryptography, linear regression, 
statistics, machine learning, neural networks, matrix operations, and database query optimization. 
While the program currently addresses lower-level complexities of these applications, it holds the potential for further development to address higher-level complexities in real-world scenarios.


**Major problems faced during the project and How did you resolve them?**
**The major problem faced:**
1.Implementing Filing with Matrices.
2.Use of Recursion in determining the Determinant of a Matrix.
3.Understanding Convolution.

**The issues were solved by:**
1.Extensive research was done to grasp the concepts of filing and recursion.
2.Further guidance from Lab Instructor also helped in resolving the issues.

**Major logic/Algorithm used. Complexity. (Any chance of improvement)**
The major Algorithm implemented was Dynamic Memory Allocation(DMA): 
since,
DMA is often used in 2D arrays when the size of the array is not known at compile time or when you want to allocate memory based on runtime conditions. There are several reasons why dynamic memory allocation for 2D arrays was used.
**Variable Size:**
Dynamic memory allocation allows you to create 2D arrays with sizes that are determined at runtime. This is useful when the size of the array is not known until the program is running.
**Flexibility:**
It provides flexibility to resize the array during program execution based on user input or other runtime conditions.
**Memory Efficiency:**
Dynamic allocation allows you to allocate memory only when it is needed. This can be more memory-efficient than static allocation, especially if the size of the array is not constant throughout the program's execution.
**Avoiding Wastage:**
With dynamic memory allocation, you can avoid wasting memory by allocating exactly the amount of space needed for the array.
**Ease of Use:**
Dynamic memory allocation is often more convenient when dealing with functions that return 2D arrays of varying sizes or when passing 2D arrays as function parameters.
**Avoiding Stack Overflow:**
Large arrays may exceed the stack size, leading to a stack overflow. Dynamic memory allocation, which typically uses the heap, helps in avoiding this issue.

