
## Simpler-Segtree

- Init with an array simply using the build fn, customize operation and epslion in the struct itself, supports point updates and range queries
- ```
  https://thesobersobber.github.io/CP-Snippets/Simpler-Segtree
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L469)

```cpp
struct segtree {
    vector<int> t;
    int emptyans = -1e18; 
    int n;
    int op(int a, int b){
        return max(a, b); // custom operation
    }
    int construct(int v, int l, int r, vi &a){
        if(l == r){
            t[v] = a[l];
            return t[v];
        }
        int mid = (r + l)/2;
        return t[v] = op(construct(2*v+1, l, mid, a), construct(2*v+2, mid+1, r, a));
    }
    void build(vi &a){
        n = a.size();
        t = vector<int> (4*n);
        construct(0, 0, n-1, a);
    }     
    int queryans(int v, int curl, int curr, int l, int r){
        if(curl >= l && curr <= r){
            return t[v];
        }
        if(curr < l || curl > r){
            return emptyans;
        }
        int mid = (curl + curr)/2;
        return op(queryans(2*v+1, curl, mid, l, r), queryans(2*v+2, mid+1, curr, l, r));
    }
    int query(int l, int r){
        return queryans(0, 0, n-1, l, r);
    }
    int updateval(int v, int i, int x, int l, int r){
        if(r < i || l > i){
            return t[v];
        }
        if(l == r && l == i){
            return t[v] = x;
        }
        int mid = (r + l)/2;
        return t[v] = op(updateval(2*v+1, i, x, l, mid), updateval(2*v+2, i, x, mid + 1, r));
    }
    void update(int i, int x){
        updateval(0, i, x, 0, n-1);
    }
};

```
