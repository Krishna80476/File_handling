#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char filename[100], ch;

    // Step 1: Create and write to a file
    printf("Enter the name of the file to create: ");
    scanf("%s", filename);

    fptr = fopen(filename, "w");  // open file in write mode
    if (fptr == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    printf("Enter text to write to the file (press Enter then Ctrl+D to stop):\n");
    getchar(); // To consume newline character left by scanf
    while ((ch = getchar()) != EOF) {
        fputc(ch, fptr);
    }

    fclose(fptr);
    printf("Data written successfully.\n");

    // Step 2: Read the content from the file
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nContents of the file:\n");
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }

    fclose(fptr);
    return 0;
}
