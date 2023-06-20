
## kruskal

- kruskal
- ```
  https://thesobersobber.github.io/CP-Snippets/kruskal
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L915)

```cpp
auto kruskalMST(vector<Edge> &edges, int V){
    int cost = 0;
    DSU dsu(V);
    sort(begin(edges), end(edges));
    vector<Edge> tree;
    for (const auto &[u, v, w] : edges){
        if (dsu.getParent(u) != dsu.getParent(v)) {
            cost += w;
            tree.emplace_back(u, v, w);
            dsu.join(u, v);
        }
    }
    return make_pair(tree, cost);
}

```
