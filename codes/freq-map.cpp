//freq-map
//freq-map

map<int, int> m;
for(int i=0; i<n;i++){
  if(m.find(a[i])==m.end()) m[a[i]]=1;
  else m[a[i]]++;
}