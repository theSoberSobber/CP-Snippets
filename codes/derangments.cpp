//derangments
//derangments

int countDerangements(int n){
    int dp[n + 1];
    if (n < 3) return (dp[n]=(n % 2)?1:0);
    dp[0] = 1, dp[1] = 0, dp[2] = 1;
    for (int i=3; i< n; i++) dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    return dp[n];
}