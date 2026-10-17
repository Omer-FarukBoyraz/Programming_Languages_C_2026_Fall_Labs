
// week5_task1_file_io.c
// Name: Omer Faruk  Surname: Boyraz  Student ID: 241ADB161
//
// Task 1: Read and write data from text files
// Week 5 - Files & Modular Programming
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    const char *filename = DEFAULT_FILENAME;
    char line[LINE_LEN];
    int line_count = 0;

    // Use the provided filename, or data.txt by default.
    if (argc > 1) {
        filename = argv[1];
    }

    printf("Writing lines to %s...\n", filename);

    // Open the file for writing.
    fp = fopen(filename, "w");

    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // Write two lines to the file.
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");

    // Close the file after writing.
    fclose(fp);

    // Open the same file for reading.
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    printf("Reading contents:\n");

    // Read and display each line.
    while (fgets(line, LINE_LEN, fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    // Close the file after reading.
    fclose(fp);

    printf("Lines read: %d\n", line_count);

    return EXIT_SUCCESS;
}
