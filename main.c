#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    char name[50];
    int rooms;
    int seed;
    enum ClassChar {W = 1, M, R, C};
    enum RoomType {COMBAT, TREASURE, SHOP, PUZZLE, BOSS};
    enum Element {FIRE, ICE, LIGHTNING, NONE};
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

        while (getchar() != '\n');

        if (class < 1 || class > 4) {
            printf("Invalid input. Try Again\n");
            continue;
            // No need to flush buffer here
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

    int numVowels = 0;
    for (size_t i = 0; i < strlen(name); ++i) {
        char ch = (char)tolower((unsigned char)name[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++numVowels;
        }
    }

    char tag[10];
    (numVowels >= 3) ? strcpy(tag,"ARCANE") : strcpy(tag,"GRIT");

    printf("=== CHARACTER SUMMARY ===\n");
    printf("Name: %s\n", name);
    printf("Class: ");
    switch (classChar) {
        case W:
            printf("Warrior\n");
            break;
        case M:
            printf("Mage\n");
            break;
        case R:
            printf("Rogue\n");
            break;
        case C:
            printf("Cleric\n");
            break;
        default:
            printf("Error. Could not select class.\n");
    }
    printf("Tag: %s\n", tag);
    printf("Seed: %d\n", seed);

    return 0;
}
