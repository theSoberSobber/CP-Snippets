
## highest_exponent

- power_in_fac
- ```
  https://thesobersobber.github.io/CP-Snippets/highest_exponent
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L762)

```cpp
int highest_exponent(int p, const int &n){
  int ans = 0;
  int t = p;
  while(t <= n){
    ans += n/t;
    t*=p;
  }
  return ans;
}
```
