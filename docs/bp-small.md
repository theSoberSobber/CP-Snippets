
## bp-small

- bp-small
- ```
  https://thesobersobber.github.io/CP-Snippets/bp-small
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L386)

```cpp
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#else
#define dbg(x...) "11-111"
#endif

using namespace std;

#define ll long long
#define int long long // because mai bevakoof hu

constexpr int mod = 1e9+7;
// constexpr int mod = 998244353;
constexpr int maxn = 1e6+5;

// pows
inline ll po(ll a, ll b) { ll res = 1; for (; b; b >>= 1) { if (b & 1)res = res * a; a = a * a; }return res; }
inline ll modpow(ll a, ll b, ll mod) { ll res = 1; for (; b; b >>= 1) { if (b & 1)res = (res * a)%mod; a = (a * a)%mod; }return res; }

void pre_process(){
    
}

int solve(){
    int n; cin>>n;
    dbg(n);
    return 2*n; 
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pre_process();
    int t; cin>>t;
    while(t--) cout<<solve()<<'
';
}

```
