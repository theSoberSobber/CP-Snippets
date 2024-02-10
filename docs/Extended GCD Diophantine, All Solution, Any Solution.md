
## ExtendedGcdDiophantine

- Diophantine any and all soln
- ```
  https://thesobersobber.github.io/CP-Snippets/Extended GCD Diophantine, All Solution, Any Solution
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L109)

```cpp
int _abs(int a) {
    if(a < 0) return -a;
    return a;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int64_t X, Y;

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(_abs(a), _abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    X = (int64_t)x0;
    Y = (int64_t)y0;
    return true;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / _abs(b) + 1;
}


// EXAMPLE USAGE
// void solve(){
//     int64_t a, b; cin >> a >> b;

//     swap(a, b);

//     if(a == 0) {
//         if(2 % b == 0) {
//             cout << 0 << " " << 2 / b << "
";
//             return;
//         }
//     }

//     swap(a, b);

//     if(a == 0) {
//         if(2 % b == 0) {
//             cout << 2 / b << " " << 0 << "
";
//             return;
//         }
//     }


//     if(                                      find_all_solutions(b, -a, 2, -INF, INF, -INF, INF) == 0) {
//         cout << "-1";
//     }
//     else {
//         cout << X << " " << Y << "
";
//     }
// } 

```
