
## fac

- fac
- ```
  https://thesobersobber.github.io/CP-Snippets/fac
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L612)

```cpp
int fac[maxn];
int inv[maxn];
fac[1] = inv[1] = 1;
for (int i=2; i<maxn; i++){
  fac[i] = (fac[i-1] * i)%mod;
  inv[i] = power(fac[i], mod - 2);
}

```
