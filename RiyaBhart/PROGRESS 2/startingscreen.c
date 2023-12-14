#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void headMessage(const char* title) {
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############            MATRIX CALCULATOR                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t%s", title);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}

void start() {
    headMessage("PF PROJECT");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  ********************************************************\n");
    printf("\n\t\t\t        =============================================");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 MATRIX                    =");
    printf("\n\t\t\t        =               CALCULATOR                  =");
    printf("\n\t\t\t        =============================================");
    printf("\n\n\t\t\t  ********************************************************\n");
    printf("\n\n\n\t\t\t Press Enter to continue.....");
    getch();
}

int main() {
    start();
    return 0;
}
