
## easy_seive

- easy_seive
- ```
  https://thesobersobber.github.io/CP-Snippets/easy_seive
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L387)

```cpp
void ez_seive(int n){
     vector<bool> prime(n,1);
     for (int p = 2; p*p <= n; p++){
         if (prime[p]){
            for (int i = p * p; i <= n; i += p) prime[i] = false;
         }
     }
}
for (int p = 2; p <= n; p++){
      // do whatever you want with those primes${1}
      if (prime[p]) cout << p << " ";
}

```
