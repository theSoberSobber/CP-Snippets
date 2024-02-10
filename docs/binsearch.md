
## binsearch

- binsearch
- ```
  https://thesobersobber.github.io/CP-Snippets/binsearch
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L514)

```cpp
int lo = 0, hi = n-1;
while(hi-lo>1) {
    int mid = lo + ((hi-lo) >> 1);
    // if condition true toh bas right segment mai search hoga, left eliminated
    auto check = [&](ll mid) {
      return (/*condition here*/);
    };
    if(check(mid)){
        // do stuff here
        lo = mid;
    }
    else {
        hi = mid;
    }
}
```
