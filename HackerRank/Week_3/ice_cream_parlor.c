#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'icecreamParlor' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER_ARRAY arr
 */

int* icecreamParlor(int m, int arr_count, int* arr, int* result_count) {
    int *indices = malloc(2 * sizeof(int));
    *result_count = 2;
    bool found = false;

    for (int first = 0; first < arr_count - 1 && !found; first++) {
        for (int second = first + 1; second < arr_count; second++) {
            if (arr[first] + arr[second] == m) {
                indices[0] = first + 1;
                indices[1] = second + 1;
                found = true;
                break;
            }
        }
    }
    return indices;
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int case_no = 0; case_no < t; case_no++) {
        int m = parse_int(ltrim(rtrim(readline())));
        int n = parse_int(ltrim(rtrim(readline())));

        char** arr_temp = split_string(rtrim(readline()));
        int* arr = malloc(n * sizeof(int));

        for (int k = 0; k < n; k++) {
            arr[k] = parse_int(arr_temp[k]);
        }

        int result_count;
        int* result = icecreamParlor(m, n, arr, &result_count);

        for (int p = 0; p < result_count; p++) {
            fprintf(fptr, "%d", result[p]);
            if (p < result_count - 1) {
                fprintf(fptr, " ");
            }
        }
        fprintf(fptr, "\n");
        free(arr);
        free(result);
    }

    fclose(fptr);
    return 0;
}

char* readline() {
    size_t alloc_len = 1024;
    size_t data_len = 0;
    char* buffer = malloc(alloc_len);

    while (true) {
        char* cursor = buffer + data_len;
        char* line = fgets(cursor, alloc_len - data_len, stdin);
        if (!line) break;

        data_len += strlen(cursor);
        if (data_len < alloc_len - 1 || buffer[data_len - 1] == '\n') break;

        alloc_len <<= 1;
        buffer = realloc(buffer, alloc_len);
    }

    if (buffer[data_len - 1] == '\n') {
        buffer[data_len - 1] = '\0';
        buffer = realloc(buffer, data_len);
    } else {
        buffer = realloc(buffer, data_len + 1);
        buffer[data_len] = '\0';
    }
    return buffer;
}

char* ltrim(char* str) {
    while (*str && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** parts = NULL;
    char* token = strtok(str, " ");
    int count = 0;

    while (token) {
        parts = realloc(parts, sizeof(char*) * ++count);
        parts[count - 1] = token;
        token = strtok(NULL, " ");
    }
    return parts;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
