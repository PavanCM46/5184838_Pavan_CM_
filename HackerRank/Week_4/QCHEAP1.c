#include <stdio.h>
#include <stdlib.h>

int a[100000];
int b = 0;

void s(int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void u(int i) {
    while (i > 0) {
        int j = (i - 1) / 2;
        if (a[j] > a[i]) {
            s(i, j);
            i = j;
        } else {
            break;
        }
    }
}

void v(int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int m = i;
        if (l < b && a[l] < a[m]) {
            m = l;
        }
        if (r < b && a[r] < a[m]) {
            m = r;
        }
        if (m != i) {
            s(i, m);
            i = m;
        } else {
            break;
        }
    }
}

void w(int x) {
    a[b] = x;
    b = b + 1;
    u(b - 1);
}

int x() {
    int y = a[0];
    a[0] = a[b - 1];
    b = b - 1;
    v(0);
    return y;
}

void y(int z) {
    int i = 0;
    while (i < b) {
        if (a[i] == z) {
            a[i] = a[b - 1];
            b = b - 1;
            u(i);
            v(i);
            break;
        }
        i = i + 1;
    }
}

int main() {
    int q;
    scanf("%d", &q);
    int i = 0;
    while (i < q) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int n;
            scanf("%d", &n);
            w(n);
        } else if (t == 2) {
            int n;
            scanf("%d", &n);
            y(n);
        } else {
            printf("%d\n", a[0]);
        }
        i = i + 1;
    }
    return 0;
}

