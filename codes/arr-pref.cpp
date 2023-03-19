//arr-pref
//arr-pref

vector<int> pre(n, 0);
for(int i=1;i<n;i++) pre[i]=a[i]+pref[i-1]; 