
## euclid

- euclid
- ```
  https://thesobersobber.github.io/CP-Snippets/euclid
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1313)

```cpp
int euclid_gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a % b);
}

int euclid_gcdExtended(int a, int b, int *x, int *y){
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}


```
