#include <stdio.h>
#include <string.h>

int main()
{
    char feedback[500];
    char newFeedback[600];
    char *position;

    printf("Enter customer feedback: ");
    fgets(feedback, sizeof(feedback), stdin);

    // Remove the newline character
    feedback[strcspn(feedback, "\n")] = '\0';

    // Count total characters
    printf("\nTotal characters: %d", (int)strlen(feedback));

    // Check sentiment
    if (strstr(feedback, "good") != NULL)
    {
        printf("\nSentiment: Positive");
    }
    else if (strstr(feedback, "bad") != NULL)
    {
        printf("\nSentiment: Negative");
    }
    else
    {
        printf("\nSentiment: Neutral");
    }

    // Replace bad with not good
    strcpy(newFeedback, feedback);

    position = strstr(newFeedback, "bad");

    if (position != NULL)
    {
        char remaining[500];

        strcpy(remaining, position + 3);

        *position = '\0';

        strcat(newFeedback, "not good");
        strncat(newFeedback, remaining, sizeof(newFeedback) - strlen(newFeedback) - 1);

        printf("\nUpdated Feedback: %s", newFeedback);
    }
    else
    {
        printf("\nUpdated Feedback: %s", newFeedback);
    }

    return 0;
}
