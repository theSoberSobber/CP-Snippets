//binpow
//binpow

ll binpow(ll x, ll y){
    ll res = 1;
    while (y>0){
        if (y&1) res = (ll)(res*x);
        y = y>>1;
        x = (ll)(x*x);
    }
    return res;
}