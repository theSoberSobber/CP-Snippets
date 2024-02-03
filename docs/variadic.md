
## variadic

- variadic lambdas with 1 and 2 arguments
- ```
  https://thesobersobber.github.io/CP-Snippets/variadic
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L2162)

```cpp
#define f(u, args...)     [&](auto &&u) { return args; }
#define g(u, v, args...)  [&](auto &&u, auto &&v) { return args; }

```
