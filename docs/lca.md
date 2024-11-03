
## lca

- LCA path satisfying some condition
- ```
  https://thesobersobber.github.io/CP-Snippets/lca
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1826)

```cpp
constexpr int N = 5; // No. of vertices
constexpr int L = 4; // ceil(logN / log2) + 1

// Vertices from 1 to N.
vector<int> adj[N + 1];
int up[N + 1][L];
int level[N + 1];

void dfs(int u, int prev = 0){
 up[u][0] = prev;
 for (auto &v : adj[u]){
     if (v == prev) continue;

     level[v] = level[u] + 1;
     dfs(v, u);
 }
}

void binaryLift(){
 dfs(1);
 for (int i = 1; i < L; i++)
     for (int j = 1; j <= N; j++)
          up[j][i] = up[up[j][i - 1]][i - 1];
}

int LCA(int a, int b){
 if (level[a] > level[b])
     swap(a, b);

 int diff = level[b] - level[a];
 for (int i = 0; i < L; i++){
     if ((diff & (1 << i)))
         b = up[b][i];
 }

 if (a == b) return a;

 for (int i = L - 1; i >= 0; i--){
     if (up[a][i] != up[b][i]){
         a = up[a][i];
         b = up[b][i];
     }
 }
 return up[a][0];
}

void addEdge(int u, int v){
 adj[u].push_back(v);
 adj[v].push_back(u);
}

int dist(int a, int b){
 return level[a] + level[b] - 2 * level[LCA(a, b)];
}

```
