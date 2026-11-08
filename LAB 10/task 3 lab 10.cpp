#include <stdio.h>
#include <string.h>

int main()
{
    char email[100];
    char domain[100];
    char *position;

    printf("Enter your email address: ");
    scanf("%99s", email);

    // Find @ symbol
    position = strchr(email, '@');

    if (position == NULL)
    {
        printf("Invalid Email Format");
    }
    else
    {
        // Copy domain after @
        strcpy(domain, position + 1);

        if (strlen(domain) == 0)
        {
            printf("Invalid Email Format");
        }
        else
        {
            printf("Extracted Domain: %s", domain);
        }
    }

    return 0;
}
