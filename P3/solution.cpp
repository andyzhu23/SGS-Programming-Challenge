#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2, typename T3> 
inline T1 fp(T1 a, T2 b, T3 mod) {
    T1 c = 1;
    while(b) {
        if(b & 1) c = c * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return c;
}

namespace fast_io {
    int read() {
        int x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    long long readLL() {
        long long x = 0, f = 0; char ch = getchar();
        while (!isdigit(ch)) f |= ch == '-', ch = getchar();
        while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
            return f ? -x : x;
    }
    void read(int& x) {x = read();}
    void read(long long& x) {x = readLL();}
    template<typename T> void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x >= 10) print(x / 10);
            putchar(x % 10 + '0');
    }
    template<typename T> void print(T x, char let) {
        print(x), putchar(let);
    }
}
using namespace fast_io;

const int N = 5e5 + 5;
const int mod = 1e9 + 7;
vector<int> e[N];
int n, sz[N], dfn[N], dep[N], a[N], p[N];

struct segtree {
#define lc (rt << 1)
#define rc (rt << 1 | 1)
    int st[N << 2], lazy[N << 2];
    void push_down(int rt) {
        if(lazy[rt]) {
            st[lc] = st[rc] = lazy[lc] = lazy[rc] = lazy[rt];
            lazy[rt] = 0;
        }
    }
    void update(int rt, int l, int r, int x, int y, int val) {
        if(l == x && y == r) {
            st[rt] = val;
            lazy[rt] = val;
            return;
        }
        int mid = l + r >> 1;
        push_down(rt);
        if(y <= mid) update(lc, l, mid, x, y, val);
        else if(x > mid) update(rc, mid + 1, r, x, y, val);
        else update(lc, l, mid, x, mid, val), update(rc, mid + 1, r, mid + 1, y, val);
    }
    void build(int rt, int l, int r) {
        if(l == r) {
            st[rt] = 1;
            return;
        }
        int mid = l + r >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
    }
    int query(int rt, int l, int r, int pos) {
        if(l == r) return st[rt];
        int mid = l + r >> 1;
        push_down(rt);
        if(pos <= mid) return query(lc, l, mid, pos);
        else if(pos > mid) return query(rc, mid + 1, r, pos);
    }
    void update(int x, int val) {
        update(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, val);
    }
} st;

int tot = 0;

void dfs(int u = 1, int fa = 0) {
    sz[u] = 1;
    p[u] = a[u];
    dfn[u] = ++tot;
    dep[u] = dep[fa] + 1;
    for(int v : e[u]) if(v != fa) {
        dfs(v, u);
        sz[u] += sz[v];
        p[u] = 1ll * p[u] * p[v] % mod;
    }
}

void remove(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    int x = st.query(1, 1, n, dfn[u]);
    p[x] = 1ll * p[x] * fp(1ll * p[v], mod - 2, mod) % mod;
    st.update(v, v);
}

void merge(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    int fa = st.query(1, 1, n, dfn[u]);
    p[fa] = 1ll * p[fa] * p[v] % mod;
    st.update(v, fa);
}

unordered_set<int> c;
vector<pair<int, int> > edge;

int main() {
    read(n);
    for(int i = 1;i<=n;++i) a[i] = read();
    for(int i = 1;i<n;++i) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs();
    st.build(1, 1, n);
    int q = read();
    while(q--) {
        int opt = read();
        if(opt == 1) {
            int u = read(), v = read();
            edge.push_back({u, v});
        } else {
#define all(v) v.begin(), v.end()
            sort(all(edge), [&](pair<int, int>& a, pair<int, int>& b) {
                return dep[a.first] + dep[a.second] < dep[b.first] + dep[b.second];
            });
            for(auto[u, v] : edge) {
                remove(u, v);
            }
            long long ans = p[st.query(1, 1, n, dfn[1])];
            for(auto[u, v] : edge) {
                if(dep[u] < dep[v]) swap(u, v);
                ans = (ans + p[st.query(1, 1, n, dfn[u])]) % mod;
            }
            print(ans, '\n');
            for(int i = edge.size() - 1;~i;--i) {
                auto[u, v] = edge[i];
                merge(u, v);
            }
            edge.clear();
        }
    }
    return 0;
}
