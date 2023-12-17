# Project Title: Matrices Calculation Programme

## Programmers:

|Name|ID|
|-|----------|
|Riya Bhart|(23k-0063)|
|Rija Ali|(23k-0057)|
|Ibrahim Johar Farooqi|(23k-0074)|

#### Instructor Name: Sir Farooq Zaidi

#### Course Title: Programming Fundamentals - Lab

#### Course Code: CS1002

# Proposal Idea
## Project Description: 
Our project aims to reinforce the core concepts and skills we have learned in the course by developing a Matrices Calculation Program. 

## Core Concepts:
1. Control Structures (If statements & If - Else Statements)
2. Switch Statements
3. Loops
4. Arrays (1D & 2D)
5. Pointers
6. Functions
7. Recursion
8. DMA
9. Filing 

## Project Scope: 
This program will be created in C, using the “Visual Studio Code” application. This will be used for our compiler for our program as well as the interface for the program. 
The program functionalities will consist of:
1. Determinant of Square Matrix
2. Addition between two Matrices. (mxn)
3. Subtraction between two Matrices. (mxn)
4. Multiplication of between two Matrices (mxn)
5. Transpose of a Matrix. 
6. Convolution of a Square Matrix

The program will offer the user the option to choose from the sub-programs mentioned above that pertain to the use of matrices. For tedious inputs, we will utilize the functionality of filing and dynamic memory allocation. 

## Purpose & Need for this Programme:
Matrices play a crucial role in various STEM fields, and a program's significance lies in its ability to compute determinants for square matrices. This functionality finds applications in quantum mechanics, geometry, linear transformations, and stress analysis in engineering. Additionally, the program offers the capability to determine the transpose of matrices, with real-world applications spanning cryptography, linear regression, statistics, machine learning, neural networks, matrix operations, and database query optimization. While the program currently addresses lower-level complexities of these applications, it holds the potential for further development to address higher-level complexities in real-world scenarios.

# Implementation of the project

## Major problems faced during the project & How did we resolve them?
### The major problems we faced:
1.	Implementing Filing with Matrices in our program.
2.	Use of Recursion in determining the Determinant of a Matrix.
3.	Understanding Convolution and implementing it efficiently.

### The issues were resolved by:
1.	Extensive research was done to grasp the concepts of filing and recursion.
2.	Extensive trial and error along with understanding the key mathematical concepts of convolution and determinants through articles on the web.
3.	Further guidance from the Lab Instructor also helped in resolving the issues.

## Major logic/Algorithm used. Complexity. (Any chance of improvement):
The major Algorithm implemented was Dynamic Memory Allocation(DMA) since DMA is often used in 2D arrays when the size of the array is not known at compile time or when you want to allocate memory based on runtime conditions.
There are several reasons why dynamic memory allocation for 2D arrays was used in our program including:
### Variable Size:
Dynamic memory allocation allows you to create 2D arrays with sizes that are determined at runtime. This is useful when the size of the array is not known until the program is running.
### Flexibility:
It provides flexibility to resize the array during program execution based on user input or other runtime conditions.
### Memory Efficiency:
Dynamic allocation allows you to allocate memory only when it is needed. This can be more memory-efficient than static allocation, especially if the size of the array is not constant throughout the program's execution.
### Avoiding Wastage:
With dynamic memory allocation, you can avoid wasting memory by allocating exactly the amount of space needed for the array.
### Ease of Use:
Dynamic memory allocation is often more convenient when dealing with functions that return 2D arrays of varying sizes or when passing 2D arrays as function parameters.
### Avoiding Stack Overflow:
Large arrays may exceed the stack size, leading to a stack overflow. Dynamic memory allocation, which typically uses the heap, helps in avoiding this issue.



### Group Contributions:
|Functionalities of the Program|Name|
|-|----------|
|Determinant & Interface for programme|Ibrahim Johar|
|Multiplication & Transpose|Rija Ali|
|Convolution & Addition/Subtraction|Riya Bhart|


[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/j0WbCUcA)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=13059286&assignment_repo_type=AssignmentRepo)
