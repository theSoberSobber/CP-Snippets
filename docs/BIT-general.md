
## BIT-general

- easy BIT general with range updates by diff array too
- ```
  https://thesobersobber.github.io/CP-Snippets/BIT-general
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L2)

```cpp
template <class T>
class BIT
{
    static_assert(is_integral<T>::value, "Integer required");

private:
    const size_t N;
    vector<T> data;

public:
    // Binary indexed tree or fenwick tree
    // O (log n) all operations except order
    // order complexity - O (log n)
    // 1 based indexing
    BIT() : N(0) {}
    BIT(const size_t _N) : N(_N), data(_N + 1) {}

    size_t size()
    {
        return N;
    }
    // sum of [1, idx]
    // range sum query
    T sum(size_t idx)
    {
        T ans = 0;
        for (; idx > 0; idx -= (idx & -idx))
        {
            ans += data[idx];
        }
        return ans;
    }
    T sum(size_t l, size_t r)
    {
        return sum(r) - sum(l - 1);
    }

    // Point update
    void add(size_t idx, T val)
    {
        for (; idx <= N; idx += (idx & -idx))
        {
            data[idx] += val;
        }
    }

    // Range update
    void range_add(size_t l, size_t r, T val)
    {
        add(l, val);
        add(r + 1, -val);
    }
    template <class OStream>
    friend OStream &operator<<(OStream &os, BIT &bit)
    {
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.N; i++)
        {
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
};

```
