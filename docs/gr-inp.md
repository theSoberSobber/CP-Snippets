
## gr-inp

- graph input
- ```
  https://thesobersobber.github.io/CP-Snippets/gr-inp
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1425)

```cpp
int e=f(n);
vector<vector<int>> g(n+1);
for(int i=1;i<=e;i++){
  int u,v; cin>>u>>v;
  g[u].push_back(v);
  g[v].push_back(u);
}
```
