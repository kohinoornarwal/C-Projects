#include <stdio.h>
#include <string.h>

#define FILE_NAME "accounts.dat"

struct Account {
    int accNo;
    char name[50];
    double balance;
};

void createAccount(void);
void deposit(void);
void withdraw(void);
void checkBalance(void);
void displayAll(void);
int findAccount(int accNo, struct Account *out, long *pos);

int main(void) {
    int choice;
    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n2. Deposit\n3. Withdraw\n");
        printf("4. Check Balance\n5. Display All Accounts\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); continue; }
        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: displayAll(); break;
            case 0: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}

/* Returns 1 if found; fills *out and *pos (file offset of the record) */
int findAccount(int accNo, struct Account *out, long *pos) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;
    struct Account a;
    while (1) {
        long p = ftell(fp);
        if (fread(&a, sizeof(a), 1, fp) != 1) break;
        if (a.accNo == accNo) {
            if (out) *out = a;
            if (pos) *pos = p;
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void createAccount(void) {
    struct Account a;
    printf("Enter account number: ");
    scanf("%d", &a.accNo);
    if (findAccount(a.accNo, NULL, NULL)) {
        printf("Account already exists!\n");
        return;
    }
    printf("Enter holder name: ");
    scanf(" %49[^\n]", a.name);
    printf("Enter initial deposit: ");
    scanf("%lf", &a.balance);
    if (a.balance < 0) { printf("Invalid amount!\n"); return; }

    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) { printf("File error!\n"); return; }
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    printf("Account created successfully.\n");
}

static void updateBalance(int isDeposit) {
    int accNo;
    double amt;
    struct Account a;
    long pos;

    printf("Enter account number: ");
    scanf("%d", &accNo);
    if (!findAccount(accNo, &a, &pos)) { printf("Account not found!\n"); return; }

    printf("Enter amount: ");
    scanf("%lf", &amt);
    if (amt <= 0) { printf("Invalid amount!\n"); return; }
    if (!isDeposit && amt > a.balance) { printf("Insufficient balance!\n"); return; }

    a.balance += isDeposit ? amt : -amt;

    FILE *fp = fopen(FILE_NAME, "r+b");
    if (!fp) { printf("File error!\n"); return; }
    fseek(fp, pos, SEEK_SET);
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    printf("%s successful. New balance: %.2f\n", isDeposit ? "Deposit" : "Withdrawal", a.balance);
}

void deposit(void)  { updateBalance(1); }
void withdraw(void) { updateBalance(0); }

void checkBalance(void) {
    int accNo;
    struct Account a;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    if (findAccount(accNo, &a, NULL))
        printf("Name: %s | Balance: %.2f\n", a.name, a.balance);
    else
        printf("Account not found!\n");
}

void displayAll(void) {
    FILE *fp = fopen(FILE_NAME, "rb");
    struct Account a;
    if (!fp) { printf("No accounts yet.\n"); return; }
    printf("\n%-10s %-20s %10s\n", "Acc No", "Name", "Balance");
    while (fread(&a, sizeof(a), 1, fp) == 1)
        printf("%-10d %-20s %10.2f\n", a.accNo, a.name, a.balance);
    fclose(fp);
}
