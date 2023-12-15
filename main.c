#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void headMessage(const char* title) {
    system("cls");  
    printf("\n\t\t\t#############################################");
    printf("\n\t\t\t#                                           #");
    printf("\n\t\t\t#     WELCOME TO THE MATRIX CALCULATOR      #");
    printf("\n\t\t\t#                                           #");
    printf("\n\t\t\t#############################################");
    printf("\n\t\t\t---------------------------------------------");
    printf("\n\t\t\t\t\t%s", title);
    printf("\n\t\t\t---------------------------------------------");
}

void start()
{
    headMessage("PF PROJECT");
    printf("\n");
    printf("\n\t\t\t*********************************************\n");
    printf("\n\t\t\t    ====================================");
    printf("\n\t\t\t    *           LET'S START!           *");
    printf("\n\t\t\t    ====================================");
    printf("\n\n\t\t\t*********************************************\n");
    printf("\n\n\t\t\t\t   Press Enter to begin...");
    getch();
}

void menu()
{
    printf("\n\n\t\t\t---------------------------------------------");
    printf("\n\t\t\t|           PROGRAM FUNCTIONALITIES         |");
    printf("\n\t\t\t---------------------------------------------");
    printf("\n\t\t\t|   |1| Addition between TWO Matrices       |");
    printf("\n\t\t\t|   |2| Subtraction between TWO Matrices    |");
    printf("\n\t\t\t|   |3| Multiplication between TWO Matrices |");
    printf("\n\t\t\t|   |4| Determinant of a Matrix             |");
    printf("\n\t\t\t|   |5| Transpose of a Matrix               |");
    printf("\n\t\t\t---------------------------------------------");

}

int main() {
    start();
    menu(); 
    return 0;
}

