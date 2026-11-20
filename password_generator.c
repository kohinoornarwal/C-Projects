#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 64

int askYesNo(const char *msg) {
    char c;
    printf("%s (y/n): ", msg);
    scanf(" %c", &c);
    return c == 'y' || c == 'Y';
}

void generatePassword(int length, const char *pool, char *out) {
    int i;
    for (i = 0; i < length; i++)
        out[i] = pool[rand() % strlen(pool)];
    out[length] = '\0';
}

int main(void) {
    const char *lower  = "abcdefghijklmnopqrstuvwxyz";
    const char *upper  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *digits = "0123456789";
    const char *symbols = "!@#$%^&*()-_=+[]{};:,.<>?";

    char pool[128], password[MAX_LEN + 1];
    int length, again;

    srand((unsigned)time(NULL));

    printf("===== PASSWORD GENERATOR =====\n");
    do {
        pool[0] = '\0';
        printf("\nEnter password length (4-%d): ", MAX_LEN);
        scanf("%d", &length);
        if (length < 4 || length > MAX_LEN) {
            printf("Invalid length!\n");
            continue;
        }

        if (askYesNo("Include lowercase"))  strcat(pool, lower);
        if (askYesNo("Include uppercase"))  strcat(pool, upper);
        if (askYesNo("Include digits"))     strcat(pool, digits);
        if (askYesNo("Include symbols"))    strcat(pool, symbols);

        if (strlen(pool) == 0) {
            printf("Select at least one character type!\n");
            continue;
        }

        generatePassword(length, pool, password);
        printf("Generated password: %s\n", password);

        again = askYesNo("Generate another");
    } while (again);

    return 0;
}
