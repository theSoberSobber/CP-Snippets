//bfs-dist
//bfs that measures levels/dist

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
