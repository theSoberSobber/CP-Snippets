
## totient-seive

- totient-seive
- [Shareable Link](https://thesobersobber.github.io/CP-Snippets/totient-seive)
- [github](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1178)

```cpp
  for (int i = 1; i < MN; i++)
    phi[i] = i;

  for (int i = 1; i < MN; i++)
    if (!sieve[i]) // is prime
      for (int j = i; j < MN; j += i)
        phi[j] -= phi[j] / i;

```
