
## gr-inp-Fwt

- graph input weight
- ```
  https://thesobersobber.github.io/CP-Snippets/gr-inp-Fwt
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1015)

```cpp
int e=f(n);
vector<vector<pair<int,int>>> g(n+1);
for(int i=1;i<=e;i++){
  int u,v,wt; cin>>u>>v>>wt;
  g[u].push_back({v,wt});
  g[v].push_back({u,wt});
}
```
