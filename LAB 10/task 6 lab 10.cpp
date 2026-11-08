#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fptr;

    char username[50];
    char password[50];

    char savedUsername[50];
    char savedPassword[50];

    // Take username and password
    printf("Enter Username: ");
    scanf("%49s", username);

    printf("Enter Password: ");
    scanf("%49s", password);

    // Open credentials file
    fptr = fopen("credentials.txt", "r");

    if (fptr == NULL)
    {
        printf("Error opening credentials file!");
        return 1;
    }

    // Read saved username and password
    if (fscanf(fptr, "%49s %49s", savedUsername, savedPassword) != 2)
    {
        printf("Invalid credentials file!");
        fclose(fptr);
        return 1;
    }

    // Compare entered and saved details
    if (strcmp(username, savedUsername) == 0 &&
        strcmp(password, savedPassword) == 0)
    {
        printf("\nAccess Granted!");
    }
    else
    {
        printf("\nAccess Denied!");
    }

    // Close file
    fclose(fptr);

    return 0;
}
