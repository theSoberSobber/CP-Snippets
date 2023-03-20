
## recur-binsearch

- recursive binary search implementation to make intution easier ig
- [Shareable Link](https://thesobersobber.github.io/CP-Snippets/recur-binsearch)
- [github](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L995)

```cpp
auto check = [&](int mid) {
      // smthing here
      return bool ();
};
function<int(int,int)> recur_binsearch = [&](int lo, int hi) {
  if(hi<=lo) return lo;
  int mid=(lo+hi)/2;
  if(check(mid)) return recur_binsearch(lo, mid-1);
  return recur_binsearch(mid+1, hi);
}

```
