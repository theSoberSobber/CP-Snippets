
## Weird_Lazy_Segtree

- A lazy segtree taken from a abc340 E mridulahi submission, it's supposed to be able to do range updates and point queries
- ```
  https://thesobersobber.github.io/CP-Snippets/Lazy Segtree
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L315)

```cpp

// I can see a merge operation but not default values where to change, see build for more, change epsilon to something suitable for your operation like INF for min etc.
#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) static_cast<int>((x).size())
#define int long long

const int INF = 1e18;

struct lazy {
        int val, lazyy;
};

struct SegtreeLazy {
        int size;
        vector<lazy> val;
        void init (int n) {
                size = 1;
                while (size < n) size *= 2;
                val.resize (2 * size - 1);
        }

        lazy merge (int x, int y) {
                return {min (val[x].val, val[y].val), 0};
        }        
        
        void propagate (int x) {
                val[2 * x + 1].val += val[x].lazyy;
                val[2 * x + 2].val += val[x].lazyy;
                val[2 * x + 1].lazyy += val[x].lazyy;
                val[2 * x + 2].lazyy += val[x].lazyy;
                val[x].lazyy = 0;
        }

        void build (vector<int> &a, int x, int lx, int rx) {
                if (rx - lx == 1) {
                        if (lx < sz(a)) val[x] = {a[lx], 0};
                        else val[x] = {INF, 0};
                        return;
                }
                int m = (lx + rx) / 2;
                build (a, 2 * x + 1, lx, m);
                build (a, 2 * x + 2, m, rx);
                val[x] = merge (2 * x + 1, 2 * x + 2);
        }

        void build (vector<int> &a) {
                build (a, 0, 0, size);
        }
        
        void RangeUpdate (int l, int r, int x, int lx, int rx, int v) {
                if (rx - lx == 1) {
                        val[x].val += v;
                        return;
                }
                if (lx >= l && rx <= r) {
                        val[x].val += v;
                        val[x].lazyy += v;
                        return;
                }
                int m = (lx + rx) / 2;
                propagate (x);
                if (m > l) {
                        RangeUpdate (l, r, 2 * x + 1, lx, m, v);
                }
                if (m < r) {
                        RangeUpdate (l, r, 2 * x + 2, m, rx, v);
                }
                val[x] = merge (2 * x + 1, 2 * x + 2);
                
        }

        void update (int l, int r, int v) {
                if (r <= l) return;
                RangeUpdate (l, r, 0, 0, size, v);
        }

        int get (int l, int r, int x, int lx, int rx) {
                if (rx - lx == 1) {
                        return val[x].val;
                }
                if (lx >= l && rx <= r) {
                        return val[x].val;
                }
                int m = (lx + rx) / 2;
                propagate (x);
                int a1 = INF, a2 = INF;
                if (m > l) {
                        a1 = get (l, r, 2 * x + 1, lx, m);
                }
                if (m < r) {
                        a2 = get (l, r, 2 * x + 2, m, rx);
                }
                return min (a1, a2);                
        }

        int get (int l, int r) {
                return get (l, r, 0, 0, size);
        }
        void out () {                
                for (int i = 0; i < sz(val); i++) cout << val[i].val << " " << val[i].lazyy << "  ";
        }

};
// EXAMPLE USAGE

// signed main() {

//         ios::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);

//         int n, m;
//         cin >> n >> m;
//         vector<int> a(n);
//         for (auto &x : a) cin >> x;
//         int b[m];
//         for (auto &x : b) cin >> x;
//                                                     SegtreeLazy seg;
//                                                     seg.init(n);
//                                                     seg.build(a);  

//         for (auto i : b) {
//                 int x = seg.get(i, i + 1);
//                 int y = (i + 1) % n, z = (i + x) % n;
//                 if (y <= z) {
//                                                     seg.update(y, z + 1, 1);
//                 }
//                 else {
//                                                     seg.update(y, n, 1);
//                                                     seg.update(0, z + 1, 1);
//                 }
//                                                     seg.update(0, n, (x - 1) / n);
//                                                     seg.update(i, i + 1, -x);
//         }      

//         for (int i = 0; i < n; i++) cout <<         seg.get(i, i + 1) << " ";
        
// }

```
