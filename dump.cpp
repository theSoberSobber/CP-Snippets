#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifndef ONLINE_JUDGE
#include "debug.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#else
#define dbg(x...) "11-111"
#endif

using namespace std;
using namespace __gnu_pbds;

// pbds = find_by_value(), order_of_key()
template<class T> using minheap = priority_queue<T,vector<T>,greater<T> >; 
template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ll                  long long int
#define all(a)              (a).begin(), (a).end()
#define rall(a)             (a).rbegin(), (a).rend()
#define sz(a)               ((int)((a).size()))
#define spr(x)              for(int i=1; i<=n; i++) cout<<x[i]<<' ';
#define uniq(x)             x.erase(unique(all(x)),x.end());

// amax and amin
template<typename T,typename T1> inline bool amax(T &a,T1 b){ if(b>a) { a=b; return true; } return false; }
template<typename T,typename T1> inline bool amin(T &a,T1 b){ if(b<a) { a=b; return true; } return false; }

/*----------------------------------x--- Constants --x--------------------------------*/
constexpr ll Inf = 4e18;
constexpr int mod = 1e9+7;
// constexpr int mod = 998244353;
constexpr int maxn = 1e6+5;

// precomp defs
vector<int> fac(maxn); vector<int> inv(maxn);

//random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a,ll b){if(a > b){return -1;}return a + (ll)rng() % (b - a + 1);}

// file io for bad OJs :(
void file_io(){
    freopen("./tests/test01.txt", "r", stdin);
    freopen("./tests/output01.txt", "w", stdout);
}

/*----------------------------------x---Excessive Macros---x--------------------------------*/

#define pb                emplace_back
#define pf                push_front
#define sumv(v,b,e)       accumulate((v).begin()+b,(v).begin()+e,0LL)
#define minv(v,b,e)       min_element((v).begin()+b,(v).begin()+e)
#define maxv(v,b,e)       max_element((v).begin()+b,(v).begin()+e)
#define precise(n)        cout<<fixed<<setprecision((n))

#define bpc(n)            std::popcount((unsigned long long)(n))
#define hsb(n)            std::has_single_bit((unsigned long long)(n))
#define MSB(n)            std::bit_floor((unsigned long long)(n))
#define ctz(n)            ((n) ? __builtin_ctzll((unsigned long long)(n)) : 0)
#define clz(n)            ((n) ? __builtin_clzll((unsigned long long)(n)) : 64)
#define LSB(n)            ((n)&(-(n)))
#define PO2(n)            !((n)&(n-1)) // boolean to return whether PO2 or not

#define pq                priority_queue<int> pq;
#define minpq             priority_queue<int, vector<int>, greater<>> pq;
#define ter(c,t,f)        ((c) ? (t) : (f))

/*----------------------------------x---Utils---x--------------------------------*/

template<class T> struct BIT{
    int n;
    vector<T> tree;
    BIT(int __n = 0) : n(__n + 1){
        tree = vector<T>(n, 0);
    }
    void update(int i, T delta){
        for(i++ ; i < n ; i += (i & -i))    tree[i] += delta;
    }
    T psum(int i){
        T sum = 0;
        for(i++ ; i > 0 ; i -= i & -i)    sum += tree[i];
        return sum;
    }
    T rsum(int i, int j){
        return (psum(j) - psum(i-1));
    }
};

int C(int n, int r){
    int v = (fac[n] * inv[r])%mod;
    v = (v * inv[n-r])%mod;
    return v;
}

ll modpow(ll a, ll b){
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

ll binpow(ll x, ll y){
    ll res = 1;
    while (y>0){
        if (y&1) res = (ll)(res*x);
        y = y>>1;
        x = (ll)(x*x);
    }
    return res;
}

vector<bool> prime;
vector<int> spf;
void sieve(int s = maxn) {
    prime.resize(s + 1, 1);
    spf.resize(s + 1, s + 1);
    for(int i = 2 ; i <= s ; i++)   if(prime[i]) {
        spf[i] = min(spf[i], i);
        for(int j = i ; (ll)j * i <= s ; j++) prime[j * i] = 0, spf[j * i] = min(i, spf[j * i]);
    }
}

/*----------------------------------x---Code-Below---x--------------------------------*/

void pre_process(){
    fac[1] = inv[1] = 1;
    for (int i=2; i<maxn; i++) fac[i] = (fac[i-1] * i)%mod;
    // O(n)
    inv[maxn-1] = modpow(fac[maxn-1], mod - 2);
    for (int i=maxn-1; i>1; i--) inv[i] = (i + 1) * inv[i + 1];
    sieve(maxn);
}

int solve(){
    int n; cin>>n;
    string s; cin>>s;
    // dbg(n);
    return 2*n; 
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // pre_process();
    int t; cin>>t;
    while(t--) cout<<solve()<<'\n';
}
