
## General-Hash

- General Hash functions that returns two hashes, takes in 0 indexed arr or string, allows hash query on range, beware that this uses the decreasing power convention
- ```
  https://thesobersobber.github.io/CP-Snippets/General-Hash
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L231)

```cpp
struct PolyHash {
    /*
        WARNING: make sure the values in the array or string are in the range [0,5e8]
        */
    vector<long long> powers;
    vector<long long> powers2;
    vector<long long> hashes;
    vector<long long> hashes2;
    long long seed = 500002961;
    long long seed2 = 500003263;
    const long long mod = (long long)1e9 + 7;
    const long long mod2 = 998244353;
    vector<long long> arr;
    void init(long long n){
        powers.resize(n + 5);
        powers[0] = 1;
        powers2.resize(n + 5);
        powers2[0] = 1;
        hashes.resize(n + 5);
        hashes[0] = arr[0];
        hashes2.resize(n + 5);
        hashes2[0] = arr[0];
        for (long long i = 1; i <= n; i++){
            powers[i] = powers[i - 1] * seed;
            powers[i] %= mod;
            powers2[i] = powers2[i - 1] * seed2;
            powers2[i] %= mod2;
        }
        for (long long i = 1; i <= n; i++){
            hashes[i] = hashes[i - 1] * seed + arr[i];
            hashes[i] %= mod;
            hashes2[i] = hashes2[i - 1] * seed2 + arr[i];
            hashes2[i] %= mod2;
        }
    }
    void init(long long n, string s){ //string is 0 indexed
        arr.resize(n + 5);
        for (long long i = 1; i <= n; i++){
            arr[i] = s[i - 1];
        }
        init(n);
    }
    void init(long long n, vector<long long> a){ //a is 0 indexed
        arr.resize(n + 5);
        for (long long i = 1; i <= n; i++){
            arr[i] = a[i - 1];
        }
        init(n);
    }
    // returns hash like a1 a2 a3 a4 a5 a6 a7 a8 a9 a10
    // 2,5 query will yeild: a2*p^3 + a3*p^2 + a4*p^1 + a5 and similar so now hash hai pehle se tumhare liye
    // no need of power combi manually
    pair<long long, long long> subhash(long long l, long long r){ //inclusive
        long long hsh = hashes[r] - hashes[l - 1] * powers[r - l + 1] % mod;
        hsh += mod;
        hsh %= mod;
        long long hsh2 = hashes2[r] - hashes2[l - 1] * powers2[r - l + 1] % mod2;
        hsh2 += mod2;
        hsh2 %= mod2;
        return {hsh, hsh2};
    }
};

// Example Usage:
// PolyHash hsh;
// int n = word.size();
// hsh.init(n,word);
// subhash is inclusive of l and r remember that

```
