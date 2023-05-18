
## kadane

- max subarray sum O(n)
- ```
  https://thesobersobber.github.io/CP-Snippets/kadane
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L725)

```cpp
int maxSubArraySum(vector<int> &v, int size){
    int max_so_far=INT_MIN, max_ending_here = 0;
    for (int i=0; i<v.size(); i++){
        max_ending_here += a[i];
        if (max_so_far<max_ending_here) max_so_far=max_ending_here;
        if (max_ending_here < 0) max_ending_here = 0;
    }
    return max_so_far;
}

```
