#include <bits/stdc++.h>
using namespace std;
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b) rng() % (b - a + 1) + a
using ll = __int128;
const int N = 1e5 + 5;
int n, cnt[N], dep[N], tot, f[N][22];
ll dp[N], leaf[N], b;
bool flag = 1;
int k, q;
vector<int> e[N];
vector<int> dfn;

void dfs(int u = 0) {
    for(int i = 1;i<=20;++i) f[u][i] = f[f[u][i - 1]][i - 1];
    cnt[u] = tot;
    if(e[u].size() == 0) {
        ++tot;
        if(flag) {
            b = dfn.size();
            flag = 0;
        }
    }
    dfn.pb(u);
    for(int v : e[u]) {
        dep[v] = dep[u] + 1;
        f[v][0] = u;
        dfs(v);
    }
}

int bs(int x, int y) {
    int lo = 0, hi = dfn.size() - 1, ans = 0;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(mid + cnt[dfn[mid]] * dp[y] >= 0 && mid + cnt[dfn[mid]] * dp[y] < x) 
            ans = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    return ans;
}

deque<int> get(int x) {
    deque<int> ans;
    for(int i = 0;i<=k;++i) {
        int idx = bs(x, k - i);
        ans.pb(dfn[idx]);
        if(idx + cnt[dfn[idx]] * dp[k - i] + 1 == x) break;
        x -= idx + cnt[dfn[idx]] * dp[k - i];
    }
    return ans;
}

int LCA(int u, int v) {
    if(dep[v] > dep[u]) swap(u, v);
    for(int i = 20;~i;--i) {
        if(dep[f[u][i]] >= dep[v]) u = f[u][i];
        if(u == v) return u;
    }
    for(int i = 20;~i;--i) {
        if(f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

const int MX = 1e9;

int aa[N], bb[N], cc;

void order(int u = 0) {
    aa[u] = ++cc;
    for(int v : e[u]) {
        order(v);
        bb[aa[v]] = aa[u];
    }
}

int main(int argc, char** argv) {
    int S = atoi(argv[1]);
    cin.tie(0)->ios::sync_with_stdio(0);
    n = 1e5;
    if(S == 16 || S == 31) n = 2;
    if(S == 17 || S == 32 || S == 55 || S == 56) n = 3;
    if(S == 35) n = 100;
    if(S == 36) n = 10;
    if(S == 37) n = 1000;
    cout<<n<<'\n';
    bool flag = 1;
    for(int i = 1;i<n;++i) {
        int x = random(0, i - 1);
        if(S == 17 || S == 32 || S == 18 || S == 33) x = 0;
        else if(S == 19 || S == 34) x = i - 1;
        else if(x == i - 1 && flag) x = 0, flag = 0;
        e[x].pb(i);
    }
    order();
    for(int i = 2;i<=n;++i) cout<<bb[i]<<" \n"[i==n];
    dfs();
    if(S <= 15) k = 0;
    else if(S <= 30) k = 30;
    else {
        if(S <= 40) k = 50 + 40 - S;
        else if(S <= 45) k = 100 + (45 - S) * 100;
        else if(S <= 50) k = 1000 + (50 - S) * 1000;
        else if(S <= 55) k = 10000 + (55 - S) * 10000;
        else k = 1e9;
    }
    q = 1e5;
    cout<<k<<' '<<q<<'\n';
    int ok = k;
    k = min(k, 30);
    ok -= k;
    dp[0] = 0, leaf[0] = 1;
    for(int i = 1;i<=k;++i) {
        leaf[i] = leaf[i - 1] * tot;
        if(leaf[i] > MX) leaf[i] = MX + 5;
        if(dp[i - 1] > MX) dp[i] = MX + 5;
        else dp[i] = dp[i - 1] + leaf[i - 1] * (n - 1);
        if(dp[i] > MX) dp[i] = MX + 5;
    }
    while(q--) {
        int u, v;
        if(S <= 15) {
            u = random(1, n);
            v = random(1, n);
        } else if(S == 16 || S == 31) {
            u = random(1, min(MX, n + k));
            v = random(1, min(MX, n + k));
            if(q == 0) v = min(MX, n + k);
        } else if (S == 19 || S == 34) {
            u = random(1, n + k * (n - 1));
            v = random(1, n + k * (n - 1));  
            if(q == 0) v = n + k * (n - 1);
        } else {
            int tmp = random(1, 2);
            int tmp2 = random(1, 2);
            if(tmp == 1) u = random(1, MX);
            else u = random(1, 10000);
            if(tmp2 == 1) v = random(1, MX);
            else v = random(1, 10000);
            if(q == 0) v = MX;
        }
        cout<<u<<' '<<v<<'\n';
        int ans = 0;
        if(u < ok * b + 1 && v < ok * b + 1) {
            ans = abs(u - v);
            cerr<<ans<<'\n';
            continue;
        } else if(u < ok * b + 1) {
            ans += ok * b + 1 - u;
            u = ok * b + 1;
        } else if(v < ok * b + 1) {
            ans += ok * b + 1 - v;
            v = ok * b + 1;
        }
        u -= ok * b, v -= ok * b;
        auto a = get(u);
        auto b = get(v);
        while((!a.empty() && !b.empty()) && a.front() == b.front()) a.pop_front(), b.pop_front();
        if(a.empty()) a.pb(0);
        if(b.empty()) b.pb(0);
        int lca = LCA(a.front(), b.front());
        for(auto x : a) ans += dep[x];
        for(auto x : b) ans += dep[x];
        ans -= dep[lca] * 2;
        cerr<<ans<<'\n';
    }
    return 0;
}


