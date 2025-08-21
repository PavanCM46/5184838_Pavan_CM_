#include <stdio.h>
#include <stdlib.h>

int stA[100000], stB[100000];
int topA = -1, topB = -1;

void pushA(int val) { stA[++topA] = val; }
void pushB(int val) { stB[++topB] = val; }

int popA() { return stA[topA--]; }
int popB() { return stB[topB--]; }

int emptyA() { return (topA == -1) ? 1 : 0; }
int emptyB() { return (topB == -1) ? 1 : 0; }

void shiftStacks() {
    while (!emptyA()) {
        pushB(popA());
    }
}

void enqueue(int val) {
    pushA(val);
}

void dequeue() {
    if (emptyB()) {
        shiftStacks();
    }
    if (!emptyB()) {
        popB();
    }
}

void frontElement() {
    if (emptyB()) {
        shiftStacks();
    }
    if (!emptyB()) {
        printf("%d\n", stB[topB]);
    }
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            frontElement();
        }
    }
    return 0;
}
