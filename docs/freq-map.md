
## freq-map

- freq-map
- [Shareable Link](https://thesobersobber.github.io/CP-Snippets/freq-map)
- [github](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L550)

```cpp
map<int, int> m;
for(int i=0; i<n;i++){
  if(m.find(a[i])==m.end()) m[a[i]]=1;
  else m[a[i]]++;
}
```
