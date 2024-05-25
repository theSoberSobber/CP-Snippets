
## recur-modpow

- recur-modpow
- ```
  https://thesobersobber.github.io/CP-Snippets/recur-modpow
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L2231)

```cpp
int power(int x, int y){
    if (y==0) return 1;
    
    int v = power(x, y/2);
    v *= v;
    v %= mod;
    if (y&1) return (v*x)%mod;
    else return v;
}

```
