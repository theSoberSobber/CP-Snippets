
## LCA-RMQ

- LCA using Range Min Query(Sparse) on ETT ([Reference](https://codeforces.com/contest/1975/submission/262585070))
- ```
  https://thesobersobber.github.io/CP-Snippets/LCA-RMQ
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L334)

```cpp
template<class T> 
struct RMQ{
    int n, logn;
    vector<vector<int>> b;
    vector<T> A;
    void build(const vector<T> &a) {
        A = a, n = sz(a);
        logn = 32 - __builtin_clz(n);
        b.resize(logn, vi(n));
        iota(all(b[0]), 0);
        for(int i = 1; i < logn ; i++){
            for(int j = 0; j < n ; j++){
                b[i][j] = b[i - 1][j];
                if(j + (1 << (i - 1)) < n && A[b[i - 1][j + (1 << (i - 1))]] < A[b[i][j]]) 
                    b[i][j] = b[i - 1][j + (1 << (i - 1))];
            }
        }
    }
    int rangeMin(int x, int y){
        int k = 31 - __builtin_clz(y - x + 1);
        return min(A[b[k][x]], A[b[k][y - (1 << k) + 1]]);
    }
    int minIndx(int x, int y){
        int k = 31 - __builtin_clz(y - x + 1);
        return A[b[k][x]] < A[b[k][y - (1 << k) + 1]] ? b[k][x] : b[k][y - (1 << k) + 1];
    }
};
 
struct LCA {
    vector<int> tour, Findx, dpth;
    RMQ<int> rmq;
    void build(const vector<vector<int>> &adj, int src) {
        vector<bool> vis(sz(adj));
        vector<int> dpth1(sz(adj));
        function<void(int, int)> dfs = [&](int i, int d) {
            tour.pb(i);
            vis[i] = 1;
            dpth1[i] = d;
            for(auto &u: adj[i]) if(!vis[u])    dfs(u, d + 1), tour.pb(i);
        };
        dfs(src, 0);
        Findx.resize(sz(adj));
        dpth.resize(sz(tour));
        for(int i = sz(tour) - 1 ; i >= 0 ; i--) {
            dpth[i] = dpth1[tour[i]], Findx[tour[i]] = i;
        }
        rmq.build(dpth);
    }
    int lca(int x, int y) {
        x = Findx[x], y = Findx[y];
        if(x > y)     swap(x, y);
        return tour[rmq.minIndx(x, y)];
    }
    int dist(int x, int y) {
        x = Findx[x], y = Findx[y];
        if(x > y)     swap(x, y);
        return dpth[x] + dpth[y] - 2 * rmq.rangeMin(x, y);
    }
};

```
