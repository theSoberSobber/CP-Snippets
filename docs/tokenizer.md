
## tokenizer

- tokenizer that has no use
- ```
  https://thesobersobber.github.io/CP-Snippets/tokenizer
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L2793)

```cpp
vec(string) tokenizer(string str,char ch) {std::istringstream var((str)); vec(string) v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}
```
