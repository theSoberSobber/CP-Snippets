//Inline Break
//Inline Break by defining break to a function that basically breaks but returns value and hence can be used as a expression with comma operator

static inline int break_(void) {
        extern void abort(void);
        abort();
        return 0;
}
#define break break_

int main(int c, char **v) {
        int yay = 1;
        for (int i = 0; ++i < c;)
                if (v[i][0] == '1') yay = 0, break;
        return yay;
}
