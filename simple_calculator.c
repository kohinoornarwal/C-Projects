#include <stdio.h>

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }

int main(void) {
    int choice;
    double a, b;
    int x, y;

    do {
        printf("\n===== SIMPLE CALCULATOR =====\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
        printf("4. Division\n5. Modulus\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); continue; }

        if (choice == 0) break;
        if (choice < 1 || choice > 5) { printf("Invalid choice!\n"); continue; }

        if (choice == 5) {
            printf("Enter two integers: ");
            scanf("%d %d", &x, &y);
        } else {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
        }

        switch (choice) {
            case 1: printf("Result = %.2f\n", add(a, b)); break;
            case 2: printf("Result = %.2f\n", sub(a, b)); break;
            case 3: printf("Result = %.2f\n", mul(a, b)); break;
            case 4:
                if (b == 0) printf("Error: division by zero!\n");
                else printf("Result = %.2f\n", divide(a, b));
                break;
            case 5:
                if (y == 0) printf("Error: modulus by zero!\n");
                else printf("Result = %d\n", x % y);
                break;
        }
    } while (1);

    printf("Goodbye!\n");
    return 0;
}
