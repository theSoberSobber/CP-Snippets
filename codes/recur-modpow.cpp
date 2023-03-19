//recur-modpow
//recur-modpow

int power(int x, int y){
    if (y==0) return 1;
    
    int v = power(x, y/2);
    v *= v;
    v %= mod;
    if (y&1) return (v*x)%mod;
    else return v;
}
