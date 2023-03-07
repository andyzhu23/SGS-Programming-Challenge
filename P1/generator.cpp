#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b) rng() % (b - a + 1) + a
using ll = long long;
int N = 2e5 + 5;
int n;
vector<int> a(N);

vector<int> ns = {200000, 200000, 200000, 200000, 200000, 200000, 200000, 200000, 200000, 200000};

vector<bool> b(N);

bool get() {
    ll cnt1 = 0, cnt2 = 0;
    for(int i = 1;i<=n;++i) {
        cnt1 += (ll)b[i] * i * (n - i + 1);
        cnt2 += (ll)(b[i] ^ 1) * i * (n - i + 1);
    }
    return cnt2 < cnt1;
}


int main(int argc, char **argv) {
    int tmp = atoi(argv[1]);
    if(tmp <= 15) {
        n = ns[tmp > 9 ? 9 : tmp];
        cout << n << '\n';
        for(int i = 1;i<=n;++i) {
            if(tmp == 1) a[i] = 1;
            else if(tmp == 2) a[i] = 0;
            else if(tmp == 3) a[i] = i % 10 == 0;
            else if(tmp == 4) a[i] = !(i > n / 4 && i < n - n / 4);
            else if(tmp == 5) a[i] = !(i > n / 5 && i < n - n / 5);
            else if(tmp == 6) a[i] = i % 2 != 0;
            else if(tmp == 7) a[i] = i % 7 != 0;
            else if(tmp == 8) a[i] = i > n / 5 && i < n - n / 5;
            else if(tmp == 9) a[i] = i > n / 4 && i < n - n / 4;
            else if(tmp == 10) a[i] = 1;
            else if(tmp == 11) a[i] = 0;
            else if(tmp == 12) a[i] = random(1, 10) == 1;
            else if(tmp == 13) a[i] = random(1, 100) != 1;
            else a[i] = random(0, 1);
            cout << a[i] << " \n"[i==n]; 
        }
    } else {
        n = ns[tmp - 15 > 9 ? 9 : tmp - 15];
        cout << n << '\n';
        for(int i = 1;i<=n;++i) {
            if(tmp == 16) a[i] = i;
            else if(tmp == 17) a[i] = 536870912;
            else if(tmp == 18) a[i] = 536870911;
            else if(tmp == 19) a[i] = 0;
            else a[i] = random(0, (int)1e9);
            cout << a[i] << " \n"[i==n];
        }
    }
    int ans = 0;
    for(int i = 0;i<=31;++i) {
        for(int j = 1;j<=n;++j) b[j] = a[j] >> i & 1;
        ans |= get() << i;
    }
    cerr << ans << '\n';
    return 0;
}

