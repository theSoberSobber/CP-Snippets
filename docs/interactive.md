
## interactive

- essential measures for interactive problems
- ```
  https://thesobersobber.github.io/CP-Snippets/interactive
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1056)

```cpp
void solve(){
    int n; cin>>n;
    
    auto querySystem = [&](int l, int r) {
        // print your query
        cout<<r-l+1<<endl;
        cout<<endl;
        // receive and return reply from system
        int wt; cin>>wt;
        return wt;
    };

    // write your logic here and use querySystem to receive answer to query
    // do a cout<<endl after each cout

    
    cout<<endl;
}

```
