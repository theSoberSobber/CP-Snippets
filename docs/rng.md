
## rng

- rng
- ```
  https://thesobersobber.github.io/CP-Snippets/rng
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1432)

```cpp
//random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a,ll b){if(a > b){return -1;}return a + (ll)rng() % (b - a + 1);}
```
