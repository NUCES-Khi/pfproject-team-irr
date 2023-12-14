#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void headMessage(const char* title) {
    system("cls");
    printf("\t\t\t###########################################################");
    printf("\n\t\t\t#                                                         #");
    printf("\n\t\t\t#             WELCOME TO THE MATRIX CALCULATOR            #");
    printf("\n\t\t\t#                                                         #");
    printf("\n\t\t\t###########################################################");
    printf("\n\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t%s", title);
    printf("\n\t\t\t-----------------------------------------------------------");
}

void start() {
    headMessage("PF PROJECT");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  *******************************************************\n");
    printf("\n\t\t\t        =============================================");
    printf("\n\t\t\t        =                 LET'S START!               =");
    printf("\n\t\t\t        =============================================");
    printf("\n\n\t\t\t  *******************************************************\n");
    printf("\n\n\n\t\t\t Press Enter to begin...");
    getch();
}

int main() {
    start();
    return 0;
}
