
## combination-small

- combination-small
- ```
  https://thesobersobber.github.io/CP-Snippets/combination-small
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L196)

```cpp
int C(int n,int r){
    r = min(r,n-r);
    int ans = 1;
    for(int i=1;i<=r;i++,n--){
        ans *=n;
        ans/=i;
    }
    return ans;
}

```
