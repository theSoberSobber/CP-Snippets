
## clock_for_TL

- clock
- [Shareable Link](https://thesobersobber.github.io/CP-Snippets/clock_for_TL)
- [github](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L167)

```cpp
auto start = chrono::high_resolution_clock::now();
// code goes here
auto stop = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
cout << duration.count() << " ms
";

```
