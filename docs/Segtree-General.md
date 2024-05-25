
## Segtree-General

- General segree, needs node struct (with members def and epsilon(default) for all of them) and operation lambda (merge)
- ```
  https://thesobersobber.github.io/CP-Snippets/Segtree-General
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L372)

```cpp
template <typename T>
class segtree
{
public:
    // 0 based indexing
    // def= default value
    vector<T> t;
    int n;
    T def;
    function<T(T, T)> merge;
    void build(int _n, T _def, function<T(T, T)> _fx)
    {
        n = _n;
        def = _def;
        merge = _fx;
        t.assign(n * 2, def);
        for (int i = n - 1; i; i--)
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
    }
    void build(vector<T> &a, T _def, function<T(T, T)> _fx)
    {
        n = a.size();
        def = _def;
        merge = _fx;
        t.assign(n * 2, def);
        for (int i = 0; i < n; i++)
            t[i + n] = T(a[i]);
        for (int i = n - 1; i; i--)
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
    }
    void update(int i, T v)
    {
        for (t[i += n] = T(v); i;)
        {
            i /= 2;
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
        }
    }
    // this query is made on [l, r]
    T query(int l, int r)
    {
        T lans = def, rans = def;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2)
        {
            if (l % 2)
                lans = merge(lans, t[l++]);
            if (r % 2)
                rans = merge(t[--r], rans);
        }
        return merge(lans, rans);
    }
};

// demo usage
struct node
{
    int val;
    node(int x)
    {
        val = x;
    }
    // default value
    node()
    {
        val = 1e18;
    }
};

segtree<node> seg;
seg.build(n + 1, node(), [&](node x, node y){ return node(min(x.val, y.val)); });

```
