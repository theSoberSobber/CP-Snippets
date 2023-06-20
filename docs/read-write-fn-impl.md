
## re-write

- a bunch of re and write functions based on template meta programming heklpful in cp.
- ```
  https://thesobersobber.github.io/CP-Snippets/read-write-fn-impl
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1358)

```cpp
template <class T1, class T2> void re(pair<T1, T2> &p);
template <class T> void re(vector<T> &a);
template <class T, size_t SZ> void re(array<T, SZ> &a);
template <class T> void re(T &x) { cin >> x; }
void re(double &x) { string t;re(t); x = stod(t);}
template <class Arg, class... Args> void re(Arg &first, Args &...rest) { re(first);  re(rest...); } 
template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.ff, p.ss); }
template <class T> void re(vector<T> &a) {for (int i = 0; i < sz(a); i++) re(a[i]); }
template <class T, size_t SZ>void re(array<T, SZ> &a) { for (int i = 0; i < SZ; i++)      re(a[i]); }
template <class T>
void write(T x) { cout << x << " "; }
template <class T> void writen(T x) { cout << x << nl; }
template<class T> using minheap = priority_queue<T,vector<T>,greater<T> >;
template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

```
