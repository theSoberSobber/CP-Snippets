
## modpow

- modpow
- ```
  https://thesobersobber.github.io/CP-Snippets/modpow
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1098)

```cpp
ll modpow(ll a, ll b){
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
```
