
## explanation_binsearch

- explanation_binsearch
- ```
  https://thesobersobber.github.io/CP-Snippets/explanation_binsearch
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L875)

```cpp
int lo = 0, hi = n-1; // see constraints for lo and hi, nahi mil rahe toh just take 0 and 1e18
while(hi-lo>1) {
    int mid = lo + ((hi-lo) >> 1); // to avoid overflows
    // lo will become the last index that satisfies X condition
    // hi is the first element that doesn't satisfy X condition
    // lower_bound = < 
    // upper_bound = <=
    // upper using lower = lo, < + ek for loop to traverse the same till upper is obtained
        
    // essence -> 
    // remember, lo ke left mai condition always true, lo last one jispe true
    // hi ke right mai condition always false, hi first one jispe false
    // hi will probably be the answer in most cases
    // hi+1, lo, lo-1 are also potential answers (maybe, mujhe toh bas lo and hi mile aaj tak)

    // always make condition such that when it's true, left segment is eliminated as potential answer container
    // if condition true toh bas right segment mai search hoga, left eliminated
    auto check = [&](ll mid) {
        // this is where majority is what you wanna write happens
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
