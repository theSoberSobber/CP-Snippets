
## bfs-dist

- bfs that measures levels/dist
- ```
  https://thesobersobber.github.io/CP-Snippets/bfs-dist
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L113)

```cpp
queue<int> q;
vector<int> dist, visG(n+1, 0);
q.push(1); visG[1]=1;
while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(auto i: g[curr]){
        if(!visG[i]) continue;
        dist[i] = dist[curr] + 1;
        q.push(i);
    }
}

```
