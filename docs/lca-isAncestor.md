
## lca-isAncestor

- lca that uses isAncestor instead of level jumping, sets a level upper limit of 25 itself since 2^25 is bigger than any N give anyways
- ```
  https://thesobersobber.github.io/CP-Snippets/lca-isAncestor
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1246)

```cpp
void dfs(int node,int parent,vector<vector<pair<int,int>>>&g,vector<vector<int>>&up,vector<vector<ll>>&dp,
                                    vector<int>&tin,vector<int>&tout,vector<int>&depth){
   up[node][0]=parent;
 
   for(int i=1;i<25;i++)
      up[ node ][i] = up[ up[node][i-1] ][i-1];
 
   tin[node]=timer++;
 
   for(auto &[child,wt] : g[node])
   {
         if(child==parent)
               continue;
         depth[child]=depth[node]+1;
         
         dp[child]=dp[node];
         dp[child][wt]++;
         
         dfs(child,node,g,up,dp,tin,tout,depth);
   }
 
   tout[node]=timer++;
}
 
bool is_ancestor(int u,int v,vector<int>&tin,vector<int>&tout)
{
   return tin[u]<=tin[v] && tout[u]>=tout[v];
}
 
int LCAquery(int u,int v,vector<vector<int>>&up,vector<int>&tin,vector<int>&tout)
{
      if( is_ancestor(u,v,tin,tout) )
            return u;
      if( is_ancestor(v,u,tin,tout) )
            return v;
      for(int i=24;i>=0;i--)
      {
           if (!is_ancestor(up[u][i], v,tin,tout))
           {
                u = up[u][i];
           }
      }
      return up[u][0];
}

```
