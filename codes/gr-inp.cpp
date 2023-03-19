//gr-inp
//graph input

int e=f(n);
vector<vector<int>> g(n+1);
for(int i=1;i<=e;i++){
  int u,v; cin>>u>>v;
  g[u].push_back(v);
  g[v].push_back(u);
}