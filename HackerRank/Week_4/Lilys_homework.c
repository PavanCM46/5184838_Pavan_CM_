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

typedef struct {
    int val;
    int pos;
} node;

int cmp(const void* x, const void* y) {
    node* p = (node*)x;
    node* q = (node*)y;
    if (p->val < q->val) return -1;
    if (p->val > q->val) return 1;
    return 0;
}

int swaps(int n, int* a, int* b) {
    int* vis = (int*)calloc(n, sizeof(int));
    int ans = 0;
    int i, j;
    for (i = 0; i < n; i = i + 1) {
        if (vis[i] == 1 || b[i] == i) {
            continue;
        }
        int cycle = 0;
        j = i;
        while (vis[j] == 0) {
            vis[j] = 1;
            j = b[j];
            cycle = cycle + 1;
        }
        if (cycle > 0) {
            ans = ans + (cycle - 1);
        }
    }
    free(vis);
    return ans;
}

int lilysHomework(int n, int* a) {
    int i;
    node* arr1 = (node*)malloc(n * sizeof(node));
    node* arr2 = (node*)malloc(n * sizeof(node));
    for (i = 0; i < n; i = i + 1) {
        arr1[i].val = a[i];
        arr1[i].pos = i;
        arr2[i] = arr1[i];
    }
    qsort(arr1, n, sizeof(node), cmp);
    qsort(arr2, n, sizeof(node), cmp);

    int* map1 = (int*)malloc(n * sizeof(int));
    int* map2 = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i = i + 1) {
        map1[arr1[i].pos] = i;
        map2[arr2[n - i - 1].pos] = i;
    }
    int ans1 = swaps(n, a, map1);
    int ans2 = swaps(n, a, map2);

    free(arr1);
    free(arr2);
    free(map1);
    free(map2);
    return ans1 < ans2 ? ans1 : ans2;
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));
    char** temp = split_string(rtrim(readline()));
    int* a = malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i = i + 1) {
        int x = parse_int(*(temp + i));
        *(a + i) = x;
    }

    int res = lilysHomework(n, a);
    fprintf(fptr, "%d\n", res);

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
        alloc_length = alloc_length * 2;
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
    if (!str) return '\0';
    if (!*str) return str;
    while (*str != '\0' && isspace(*str)) {
        str++;
    }
    return str;
}

char* rtrim(char* str) {
    if (!str) return '\0';
    if (!*str) return str;
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
        if (!splits) return splits;
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
