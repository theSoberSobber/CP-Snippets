
## tokenizer

- tokenizer that has no use
- [Shareable Link](https://thesobersobber.github.io/CP-Snippets/tokenizer)
- [github](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1169)

```cpp
vec(string) tokenizer(string str,char ch) {std::istringstream var((str)); vec(string) v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}
```
