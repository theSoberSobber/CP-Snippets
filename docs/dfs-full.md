
## dfs-full

- dfs with lots of stuff implemented
- ```
  https://thesobersobber.github.io/CP-Snippets/dfs-full
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L666)

```cpp
auto dfs = [&](auto &&dfs, int curr, int parent, vector<int> &visG, vector<int> &visPath ,vector<int> &comp, bool &cycle_directed, stack<int> topo, vector<int> &adj) -> void {
    for(auto i: adj[curr]){
        if(visPath[i]) cycle_directed|=1;
        if(i==parent || visG[i]) continue;
        dfs(dfs, i, curr, visG, visPath, comp, cycle_directed, topo);
        topo.push(i);
    }
};
int cnt_comp=0;
vector<int> visG(n+1, 0), visPath(n+1, 0), comp;
vector<vector<int>> components;
stack<int> topo;
bool cycle_directed=0;
for(int i=1; i<=n; i++){
    if(visG[i]) continue;
    visG[i]=visPath[i]=1;
    comp.push_back(i);
    dfs(dfs, 1, -1, visG, visPath, comp, cycle_directed, topo, g);
    components.push_back(comp);
    comp.clear();
    visPath.assign(n+1, 0);
    cnt_comp++;
}

```
