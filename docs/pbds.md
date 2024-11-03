
## pbds

- pbds
- ```
  https://thesobersobber.github.io/CP-Snippets/pbds
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L2021)

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// pbds = find_by_value(), order_of_key()
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
template<class T> using minheap = priority_queue<T,vector<T>,greater<T> >; 
template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
```
