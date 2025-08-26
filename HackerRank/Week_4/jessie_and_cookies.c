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
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

void heapify(int* a, int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int s = i;
    if (l < n) {
        if (a[l] < a[s]) {
            s = l;
        }
    }
    if (r < n) {
        if (a[r] < a[s]) {
            s = r;
        }
    }
    if (s != i) {
        int t = a[i];
        a[i] = a[s];
        a[s] = t;
        heapify(a, n, s);
    }
}

int extract(int* a, int* n) {
    if (*n == 0) {
        return -1;
    }
    int r = a[0];
    a[0] = a[*n - 1];
    *n = *n - 1;
    heapify(a, *n, 0);
    return r;
}

void insert(int* a, int* n, int v) {
    int i = *n;
    a[i] = v;
    *n = *n + 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (a[p] > a[i]) {
            int t = a[p];
            a[p] = a[i];
            a[i] = t;
            i = p;
        } else {
            break;
        }
    }
}

int cookies(int k, int n, int* a) {
    int i = n / 2 - 1;
    while (i >= 0) {
        heapify(a, n, i);
        i = i - 1;
    }
    int c = 0;
    while (n > 0 && a[0] < k) {
        if (n < 2) {
            return -1;
        }
        int x = extract(a, &n);
        int y = extract(a, &n);
        int z = x + 2 * y;
        insert(a, &n, z);
        c = c + 1;
    }
    return c;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** A_temp = split_string(rtrim(readline()));

    int* A = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int A_item = parse_int(*(A_temp + i));

        *(A + i) = A_item;
    }

    int result = cookies(k, n, A);

    fprintf(fptr, "%d\n", result);

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
