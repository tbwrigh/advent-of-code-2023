#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINES 256

bool isNumber(char c);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a file path as a command line argument.\n");
        return 1;
    }

    char **lines = NULL;
    char buffer[MAX_LINE_LENGTH];
    int lineCount = 0;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        char **temp = realloc(lines, (lineCount + 1) * sizeof(char *));
        if (temp == NULL) {
            perror("Memory allocation failed");
            // Free previously allocated memory
            for (int i = 0; i < lineCount; i++) {
                free(lines[i]);
            }
            free(lines);
            fclose(file);
            return 1;
        }
        lines = temp;

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        lines[lineCount] = malloc(strlen(buffer) + 1);
        if (lines[lineCount] == NULL) {
            perror("Memory allocation failed");
            return 1;
        }
        strcpy(lines[lineCount], buffer);
        lineCount++;
    }


    fclose(file);

    int sum = 0;

    int lineLength = strlen(lines[0]);

    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; j < lineLength; j++) {
            if (lines[i][j] != '.' && !(isNumber(lines[i][j]))) {
                int i1_start = i-1;
                if (i1_start < 0) {
                    i1_start = 0;
                }

                int i1_end = i+1;
                if (i1_end >= lineCount) {
                    i1_end = lineCount - 1;
                }

                int j1_start = j-1;
                if (j1_start < 0) {
                    j1_start = 0;
                }

                int j1_end = j+1;
                if (j1_end >= lineLength) {
                    j1_end = lineLength - 1;
                }

                int *nums = NULL;
                int numsCount = 0;

                for (int i1 = i1_start; i1 <= i1_end; i1++) {
                    for (int j1 = j1_start; j1 <= j1_end; j1++) {
                        if (isNumber(lines[i1][j1])) {
                            int num_start = j1;
                            
                            while (isNumber(lines[i1][num_start])) {
                                num_start--;
                            }
                            num_start++;
                            
                            int num = 0;

                            while (isNumber(lines[i1][num_start])) {
                                num *= 10;
                                num += lines[i1][num_start] - '0';
                                lines[i1][num_start] = '.';
                                num_start++;
                            }

                            int *tempNums = realloc(nums, (numsCount + 1) * sizeof(int *));
                            if (tempNums == NULL) {
                                perror("Memory allocation failed");
                                // Free previously allocated memory
                                for (int i = 0; i < numsCount; i++) {
                                    free(lines[i]);
                                }
                                free(lines);
                                fclose(file);
                                return 1;
                            }
                            nums = tempNums;
                            numsCount++;

                            nums[numsCount - 1] = num;
                        }
                    }
                }

                if (numsCount == 2 && lines[i][j] == '*') {
                    sum += nums[0] * nums[1];
                }

                free(nums);
            }
        }
    }

    printf("Sum: %d\n", sum);

    for (int i = 0; i < lineCount; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}

bool isNumber(char c) {
    return c == '0' ||
        c == '1' ||
        c == '2' ||
        c == '3' ||
        c == '4' ||
        c == '5' ||
        c == '6' ||
        c == '7' ||
        c == '8' ||
        c == '9';
}