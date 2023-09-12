#include <bits/stdc++.h>
using namespace std;

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

const int INF = 0x3f3f3f3f;
const int N = 405;
const int M = 1e6 + 5;
int n, m, k, S, T, tot = 1, head[N], cur[N], SS;
int ans, dist[N];
bitset<N> vis;

struct edge {
    int u, v;
    int w, f;
    int nxt;
} e[M];

void add(int u, int v, int w, int f) {
    e[++tot] = {u, v, w, f, head[u]};
    head[u] = tot;
    e[++tot] = {v, u, -w, 0, head[v]};
    head[v] = tot;
}

bool spfa() {
    vis.reset();
    queue<int> q;
    for(int i = S;i<=T;++i) cur[i] = head[i], dist[i] = -INF;
    dist[S] = 0;
    q.push(S);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u];i;i=e[i].nxt) {
            if(dist[e[i].v] < dist[u] + e[i].w && e[i].f) {
                dist[e[i].v] = dist[u] + e[i].w;
                if(!vis[e[i].v]) {
                    vis[e[i].v] = 1;
                    q.push(e[i].v);
                }
            }
        }
    }
    return dist[T] != -INF;
}

int dfs(int u = S, int f = INF) {
    if(u == T) {
        ans += f * dist[T];
        return f;
    }
    vis[u] = 1;
    int ret = 0;
    for(int& i = cur[u];i;i=e[i].nxt) {
        if(!vis[e[i].v] && dist[e[i].v] == dist[u] + e[i].w && e[i].f) {
            int tmp = dfs(e[i].v, min(e[i].f, f));
            e[i].f -= tmp;
            e[i ^ 1].f += tmp;
            f -= tmp;
            ret += tmp;
            if(f == 0) break;
        }
    }
    vis[u] = 0;
    if(ret == 0) dist[u] = -INF;
    return ret;
}

int dinic() {
    int ans = 0;
    while(spfa()) ans += dfs();
    return ans;
}

int main() {
    read(n), read(m), read(k);
    T = m * 2 + 2, SS = m * 2 + 1;
    add(S, SS, 0, n);
    for(int i = 1;i<=m;++i) {
        int h = read(), s = read();
        add(SS, i, 0, s);
        add(i + m, T, 0, INF);
        for(int j = 1;j<=n;++j) add(i, i + m, h / j, 1);
    }
    for(int i = 1;i<=k;++i) {
        int c = 0, a = read(), b = read(), d = read();
        add(c ? a + m : a, b, -d, INF);
    }
    dinic();
    print(ans);
}
