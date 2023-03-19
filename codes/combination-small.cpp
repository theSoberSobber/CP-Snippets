//combination-small
//combination-small

int C(int n,int r){
    r = min(r,n-r);
    int ans = 1;
    for(int i=1;i<=r;i++,n--){
        ans *=n;
        ans/=i;
    }
    return ans;
}
