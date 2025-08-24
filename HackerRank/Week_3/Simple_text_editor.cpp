#include <bits/stdc++.h>
using namespace std;

struct A {
    int a;
    string b;
    int c;
};

int main() {
    int a;
    cin >> a;
    string b = "";
    stack<A> c;
    for (int d = 0; d < a; d = d + 1) {
        int e;
        cin >> e;
        if (e == 1) {
            string f;
            cin >> f;
            int g = f.size();
            for (int h = 0; h < g; h = h + 1) {
                b.push_back(f[h]);
            }
            A i;
            i.a = 1;
            i.b = f;
            i.c = 0;
            c.push(i);
        } else {
            if (e == 2) {
                int f;
                cin >> f;
                string g = "";
                int h = b.size();
                for (int j = h - f; j < h; j = j + 1) {
                    g.push_back(b[j]);
                }
                b.erase(h - f, f);
                A i;
                i.a = 2;
                i.b = g;
                i.c = f;
                c.push(i);
            } else {
                if (e == 3) {
                    int f;
                    cin >> f;
                    cout << b[f - 1] << endl;
                } else {
                    if (e == 4) {
                        if (!c.empty()) {
                            A f = c.top();
                            c.pop();
                            if (f.a == 1) {
                                int g = f.b.size();
                                int h = b.size();
                                b.erase(h - g, g);
                            } else {
                                if (f.a == 2) {
                                    int g = f.b.size();
                                    for (int h = 0; h < g; h = h + 1) {
                                        b.push_back(f.b[h]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
