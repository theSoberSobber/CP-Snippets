
## combi-mint

- combi template with mint
- ```
  https://thesobersobber.github.io/CP-Snippets/combi-mint
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L929)

```cpp
const int mod=1e9+7;
struct mi {
    int64_t v; explicit operator int64_t() const { return v % mod; }
    mi() { v = 0; }
    mi(int64_t _v) {
        v = (-mod < _v && _v < mod) ? _v : _v % mod;
        if (v < 0) v += mod;
    }
    friend bool operator==(const mi& a, const mi& b) {
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) {
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) {
        return a.v < b.v; }

    mi& operator+=(const mi& m) {
        if ((v += m.v) >= mod) v -= mod;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((v -= m.v) < 0) v += mod;
        return *this; }
    mi& operator*=(const mi& m) {
        v = v*m.v%mod; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, int64_t p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0);
        return pow(a,mod-2); }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    mi operator++(int32_t) { mi temp; temp.v = v++; return temp; }
    mi operator--(int32_t) { mi temp; temp.v = v--; return temp; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        int64_t x; is >> x;
        m.v = x;
        return is;
    }
    friend void __print(const mi &x) {
        cerr << x.v;
    }
};
const int maxn=2e5+5;
vector<mi> fct(maxn, 1), invf(maxn, 1);
void calc_fact() {
    for(int i = 1 ; i < maxn ; i++) {
        fct[i] = fct[i - 1] * i;
    }
    invf.back() = mi(1) / fct.back();
    for(int i = maxn - 1 ; i ; i--)
        invf[i - 1] = i * invf[i];
}
 
mi choose(int n, int r) { // choose r elements out of n elements
    if(r > n)   return mi(0);
    assert(r <= n);
    return fct[n] * invf[r] * invf[n - r];
}

```
