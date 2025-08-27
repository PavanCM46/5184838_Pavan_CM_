#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* solve(int n, int* a, int q, int* b, int* rc) {
    int* prev = (int*)malloc(n * sizeof(int));
    int* next = (int*)malloc(n * sizeof(int));
    int* st = (int*)malloc(n * sizeof(int));
    int* temp = (int*)malloc((n + 2) * sizeof(int));
    int* res = (int*)malloc(q * sizeof(int));
    int i, top;

    for (i = 0; i < n; i++) {
        prev[i] = -1;
    }

    top = 0;
    for (i = 0; i < n; i++) {
        while (top > 0 && a[st[top - 1]] <= a[i]) {
            top--;
        }
        if (top > 0) {
            prev[i] = st[top - 1];
        }
        st[top++] = i;
    }

    for (i = 0; i < n; i++) {
        next[i] = n;
    }

    top = 0;
    for (i = n - 1; i >= 0; i--) {
        while (top > 0 && a[st[top - 1]] <= a[i]) {
            top--;
        }
        if (top > 0) {
            next[i] = st[top - 1];
        }
        st[top++] = i;
    }

    for (i = 0; i <= n; i++) {
        temp[i] = INT_MAX;
    }

    for (i = 0; i < n; i++) {
        int len = next[i] - prev[i] - 1;
        if (a[i] < temp[len]) {
            temp[len] = a[i];
        }
    }

    for (i = n - 1; i >= 1; i--) {
        if (temp[i] > temp[i + 1]) {
            temp[i] = temp[i + 1];
        }
    }

    for (i = 0; i < q; i++) {
        res[i] = temp[b[i]];
    }

    *rc = q;
    free(prev);
    free(next);
    free(st);
    free(temp);
    return res;
}

int main() {
    int n, q, i;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    int* a = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    int* b = (int*)malloc(q * sizeof(int));
    for (i = 0; i < q; i++) scanf("%d", &b[i]);

    int rc;
    int* r = solve(n, a, q, b, &rc);

    for (i = 0; i < rc; i++) {
        printf("%d\n", r[i]);
    }

    free(a);
    free(b);
    free(r);
    return 0;
}
