#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fptr;

    int rollNo;
    char name[50];
    float marks;

    // Open file in read mode
    fptr = fopen("marks.txt", "r");

    // Check if file exists
    if (fptr == NULL)
    {
        printf("Error: File Not Found!");
        return 1;
    }

    printf("\n-----------------------------------\n");
    printf("Roll No\t\tName\t\tMarks\n");
    printf("-----------------------------------\n");

    // Read records until end of file
    while (fscanf(fptr, "%d %49s %f", &rollNo, name, &marks) == 3)
    {
        printf("%d\t\t%s\t\t%.2f\n", rollNo, name, marks);
    }

    printf("-----------------------------------\n");

    // Close file
    fclose(fptr);

    return 0;
}
