#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char name[50];
    int rooms;
    int seed;
    enum ClassChar {W = 1, M, R, C};
    int class;

    printf("Enter Name:\n");
    scanf("%s", name);

    char tail;
    printf("Enter a five-digit number:\n");
    while (1) {
        int returnValOfInput = scanf("%d%c", &seed, &tail);
        if (returnValOfInput != 2) {
            printf("Invalid input. Try again.\n");
            printf("Enter a five-digit number:\n");
            while (getchar() != '\n');
            continue;
        }
        if (tail != '\n' && !isspace((unsigned char)tail)) {
            printf("Invalid input. Try again.\n");
            printf("Enter a five-digit number:\n");
            while (getchar() != '\n');
            continue;
        }
        if (seed < 10000 || seed > 99999) {
            printf("Number must be five digits. Try again.\n");
            printf("Enter a five-digit number:\n");
            continue;
        }
        break;
    }
    srand(seed);

    // FIXME: Apply same input handling to class selection below
    while (1) {
        printf("Choose your class:\n");
        printf("Enter '1' for Warrior:\n");
        printf("Enter '2' for Mage:\n");
        printf("Enter '3' for Rogue:\n");
        printf("Enter '4' for Cleric:\n");
        if (scanf("%d", &class) != 1) {
            printf("Invalid input. Try Again\n");
            while (getchar() != '\n');
            continue;
        }
        if (class < 1 || class > 4) {
            printf("Invalid input. Try Again\n");
            continue;
        }
        break;
    }

    enum ClassChar classChar = (enum ClassChar)class;
    switch (classChar) {
        case W:
            printf("You selected Warrior class.\n");
            break;
        case M:
            printf("You selected Mage class.\n");
            break;
        case R:
            printf("You selected Rogue class.\n");
            break;
        case C:
            printf("You selected Cleric class.\n");
            break;
        default:
            printf("Error. Could not select class");
    }







    return 0;
}
