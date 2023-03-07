#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b) rng() % (b - a + 1) + a

vector<int> ns = {0, 2, 4, 6, 8, 16, 15, 7, 33, 50, 50, 50, 50, 50, 31, 32, 1000, 2000, 5000, 6000, 7000, 8000, 1024, 1023, 10000, 10000, 10000, 10000, 10000, 8191, 8192};

int main(int argc, char **argv) {
    int S = atoi(argv[1]);
    printf("%d\n", ns[S]);
    vector<int> ans;
    for(int i = 1;i<=ns[S];++i) ans.push_back(i);
    for(int i = 1;i<=ns[S];++i) {
        if(S == 9 || S == 24) {
            printf("%d", i - 1);
            putchar(" \n"[i==ns[S]]);
        } else if(S == 10 || S == 25) {
            printf("%d", ns[S] - i);
            putchar(" \n"[i==ns[S]]);
        } else {
            int x = random(0, ns[S] - i);
            printf("%d", ans[x] - 1);
            putchar(" \n"[i==ns[S]]);
            swap(ans[x], ans[ns[S] - i]);
        }
    }
    return 0;
}

