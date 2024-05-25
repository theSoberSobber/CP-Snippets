
## seive

- seive
- ```
  https://thesobersobber.github.io/CP-Snippets/seive
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L2514)

```cpp
vector<bool> Prime;
vector<int> spf;
void sieve(int s = maxn) {
    Prime.resize(s + 1, 1);
    spf.resize(s + 1, s + 1);
    for(int i = 2 ; i <= s ; i++)   if(Prime[i]) {
        spf[i] = min(spf[i], i);
        for(int j = i ; (ll)j * i <= s ; j++)
            Prime[j * i] = 0, spf[j * i] = min(i, spf[j * i]);
    }
}

```
