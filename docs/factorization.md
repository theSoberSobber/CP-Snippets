
## factorization

- factorization
- ```
  https://thesobersobber.github.io/CP-Snippets/factorization
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L793)

```cpp
void printFactors(int n) { 
    for (int i=1; i * i<=n; i++){} 
        if (n%i == 0) { 
            if (n/i == i) cout << i << " "; 
            else cout << i << " " << n/i << " "; 
        } 
    }
    cout << "
";
} 

void printPrimeFactors(int n){
 set<int> f;
 for (int i = 2; i*i <= n; i++){
     while (n % i == 0){
         f.insert(i);
         n /= i;
      }
 }
 for (auto &i : f){
     cout << i << " ";
 }
 cout << "
";
}

```
