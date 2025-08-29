void noPrefix(int n, char** w) {
    typedef struct t {
        struct t* c[10];
        int e;
    } T;
    T* r = calloc(1, sizeof(T));
    for (int i = 0; i < n; i++) {
        char* s = w[i];
        T* p = r;
        for (int j = 0; s[j]; j++) {
            int k = s[j] - 'a';
            if (!p->c[k]) p->c[k] = calloc(1, sizeof(T));
            p = p->c[k];
            if (p->e) {
                printf("BAD SET\n%s\n", s);
                return;
            }
        }
        for (int j = 0; j < 10; j++) {
            if (p->c[j]) {
                printf("BAD SET\n%s\n", s);
                return;
            }
        }
        p->e = 1;
    }
    printf("GOOD SET\n");
}
