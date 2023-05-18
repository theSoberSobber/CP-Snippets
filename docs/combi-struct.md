
## combi-struct

- combi-struct
- ```
  https://thesobersobber.github.io/CP-Snippets/combi-struct
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L179)

```cpp
struct Comb {
    int n;
    std::vector<int> _fac;
    std::vector<int> _invfac;
    std::vector<int> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    int fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    int invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    int inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    int binom(int n, int r) {
        if (n < r || r < 0) return 0;
        return fac(n) * invfac(r) * invfac(n - r);
    }
};
```
