
## fenwick

- binary indexed tree
- ```
  https://thesobersobber.github.io/CP-Snippets/fenwick
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1351)

```cpp
// 0-indexed BIT (binary indexed tree / Fenwick tree) (i : [0, len))
template <class T>
struct BIT{
    int n;
    vector<T> data;
    BIT(int len = 0) : n(len), data(len) {}
    void reset() { fill(data.begin(), data.end(), T(0)); }
    void add(int pos, T v){ 
        // a[pos] += v
        pos++;
        while (pos > 0 and pos <= n)
            data[pos - 1] += v, pos += pos & -pos;
    }
    T sum(int k) const{ 
        // a[0] + ... + a[k - 1]
        T res = 0;
        while (k > 0)
            res += data[k - 1], k -= k & -k;
        return res;
    }

    T sum(int l, int r) const { return sum(r) - sum(l); } // a[l] + ... + a[r - 1]
    // dbg functions
    template <class OStream>
    friend OStream &operator<<(OStream &os, const BIT &bit){
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.n; i++){
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
};
```
