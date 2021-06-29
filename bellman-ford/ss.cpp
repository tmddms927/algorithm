#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 500, m = 6000;
    printf("%d %d\n", n, m);
    for (int i = 0; i < m; ++i) {
        printf("%d %d %d\n", 1+i%2, 1+(i+1)%2, -10000);
    }
}
