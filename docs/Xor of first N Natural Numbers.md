
## Xor-Of-First-N-Natural-Numbers

- based on the fact that if n%4==3 then xor till n from 1 is 0
- ```
  https://thesobersobber.github.io/CP-Snippets/Xor of first N Natural Numbers
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L746)

```cpp
auto xorOfFirstN = [&](int n) -> int {
    // n%4 = 3 => xor = 0
    int t = n, ans = 0;
    while(t%4!=3) ans^=t, --t;
    return ans;
};

// more explicit version
int computeXOR(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// source: https://www.geeksforgeeks.org/calculate-xor-1-n/

```
