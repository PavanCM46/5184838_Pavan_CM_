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

char* highestValuePalindrome(char* s, int n, int k) {
    char* res = malloc(n + 1);
    if (!res) return strdup("-1");
    strcpy(res, s);
    int* changed = (int*)calloc(n, sizeof(int));
    if (!changed) {
        free(res);
        return strdup("-1");
    }
    int l = 0;
    int r = n - 1;
    while (l < r) {
        if (res[l] != res[r]) {
            if (res[l] > res[r]) {
                res[r] = res[l];
            } else {
                res[l] = res[r];
            }
            changed[l] = 1;
            changed[r] = 1;
            k = k - 1;
        }
        l = l + 1;
        r = r - 1;
    }
    if (k < 0) {
        free(res);
        free(changed);
        return strdup("-1");
    }
    l = 0;
    r = n - 1;
    while (l < r) {
        if (res[l] != '9') {
            if (changed[l] || changed[r]) {
                if (k >= 1) {
                    res[l] = '9';
                    res[r] = '9';
                    k = k - 1;
                }
            } else {
                if (k >= 2) {
                    res[l] = '9';
                    res[r] = '9';
                    k = k - 2;
                }
            }
        }
        l = l + 1;
        r = r - 1;
    }
    if (l == r && k > 0) {
        res[l] = '9';
    }
    free(changed);
    return res;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char* s = readline();

    char* result = highestValuePalindrome(s, n, k);

    fprintf(fptr, "%s\n", result);

    free(result);
    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
