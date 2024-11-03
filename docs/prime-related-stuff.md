
## prime-related-stuff

- implements prime fac, fac list and is_prime in both space optimized and time optimized ways
- ```
  https://thesobersobber.github.io/CP-Snippets/prime-related-stuff
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L2044)

```cpp
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
void sieve(int maximum)
{
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
    for (int p = 2; p <= maximum; p++)
        if (prime[p])
        {
            smallest_factor[p] = p;
            primes.push_back(p);
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i])
                {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}


// Determines whether n is prime in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(1) time.
bool is_prime(int64_t n)
{
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    if (n <= sieve_max)
        return prime[n];
    for (int64_t p : primes)
    {
        if (p * p > n)
            break;
        if (n % p == 0)
            return false;
    }
    return true;
}




// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
template <typename T>
vector<pair<T, int>> prime_factorize(T n)
{
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<T, int>> result;
    if (n <= sieve_max)
    {
        while (n != 1)
        {
            int p = smallest_factor[n];
            int exponent = 0;
            do
            {
                n /= p;
                exponent++;
            } while (n % p == 0);
            result.emplace_back(p, exponent);
        }
        return result;
    }
    for (int p : primes)
    {
        if (int64_t(p) * p > n)
            break;
        if (n % p == 0)
        {
            result.emplace_back(p, 0);
            do
            {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }
    if (n > 1)
        result.emplace_back(n, 1);
    return result;
}



template <typename T>
vector<T> generate_factors(const vector<pair<T, int>> &prime_factors, bool sorted = false)
{
    // See http://oeis.org/A066150 and http://oeis.org/A036451 for upper bounds on number of factors.
    static vector<T> buffer;
    int product = 1;
    for (auto &pf : prime_factors)
        product *= pf.second + 1;
    vector<T> factors = {1};
    factors.reserve(product);
    if (sorted)
        buffer.resize(product);
    for (auto &pf : prime_factors)
    {
        T p = pf.first;
        int exponent = pf.second;
        int before_size = int(factors.size());
        for (int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);
        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < int(factors.size()); section *= 2)
                for (int i = 0; i + section < int(factors.size()); i += 2 * section)
                {
                    int length = min(2 * section, int(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section,
                          factors.begin() + i + section, factors.begin() + i + length,
                          buffer.begin());
                    copy(buffer.begin(), buffer.begin() + length, factors.begin() + i);
                }
    }
    assert(int(factors.size()) == product);
    return factors;
}


void pre_process() {
    sieve(1e6+5);
}


// mint

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

```
