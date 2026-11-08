#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fptr;

    char name[50];
    int accountNumber;
    float amount;

    // Take customer details
    printf("Enter Customer Name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter Account Number: ");
    scanf("%d", &accountNumber);

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    // Remove newline from name
    name[strcspn(name, "\n")] = '\0';

    // Open file in append mode
    fptr = fopen("bank_log.txt", "a");

    if (fptr == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    // Save transaction details
    fprintf(fptr, "Customer Name: %s\n", name);
    fprintf(fptr, "Account Number: %d\n", accountNumber);
    fprintf(fptr, "Withdrawal Amount: %.2f\n", amount);
    fprintf(fptr, "----------------------\n");

    // Close file
    fclose(fptr);

    printf("\nTransaction saved successfully!");

    return 0;
}
