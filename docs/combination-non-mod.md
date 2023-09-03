
## combination-non-mod

- combination-non-mod
- ```
  https://thesobersobber.github.io/CP-Snippets/combination-non-mod
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L370)

```cpp
vector<vector<int>> dp(n+1, vector<int> (k+1));
int binomalCoeff(int n, int k){
    for (int i=0; i<=n; i++){
        for (int j=0; j<=k; j++){
             if (!j || j == i) dp[i][j] = 1;
             // binomial coefficient approach
             else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
         }
     }
     return dp[n][k];
}
```
