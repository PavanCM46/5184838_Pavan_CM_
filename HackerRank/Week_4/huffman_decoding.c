#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
};

void decode_huff(struct node *root, char *s) {
    struct node *cur = root;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
        if (cur->left == NULL && cur->right == NULL) {
            printf("%c", cur->data);
            cur = root;
        }
    }
}

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}
