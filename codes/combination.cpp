//combination
//combination

int C(int n, int r){
    int v = (fac[n] * inv[r])%mod;
    v = (v * inv[n-r])%mod;
    
    return v;
}
