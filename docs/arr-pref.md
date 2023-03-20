
## arr-pref

- arr-pref
- ```
  https://thesobersobber.github.io/CP-Snippets/arr-pref
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L45)

```cpp
vector<int> pre(n, 0);
for(int i=1;i<n;i++) pre[i]=a[i]+pref[i-1]; 
```
