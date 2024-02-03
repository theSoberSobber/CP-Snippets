
## combination

- combination
- ```
  https://thesobersobber.github.io/CP-Snippets/combination
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L475)

```cpp
int C(int n, int r){
    int v = (fac[n] * inv[r])%mod;
    v = (v * inv[n-r])%mod;
    
    return v;
}

```
