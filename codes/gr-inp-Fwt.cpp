//gr-inp-Fwt
//graph input weight

int e=f(n);
vector<vector<pair<int,int>>> g(n+1);
for(int i=1;i<=e;i++){
  int u,v,wt; cin>>u>>v>>wt;
  g[u].push_back({v,wt});
  g[v].push_back({u,wt});
}