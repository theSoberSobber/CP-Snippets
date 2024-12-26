
## dsu-rr

- dsu-rr
- ```
  https://thesobersobber.github.io/CP-Snippets/dsu-rr
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1329)

```cpp
class Solution {
    struct DSU
    {
        vector<int> siz,parent;
        void init()
        {
            siz.resize(26);
            parent.resize(26);
            for(int i=0;i<26;i++)
            {
                siz[i]=1;
                parent[i]=i;
            }
        }
        int leader(int ex)
        {
            if(ex==parent[ex])
                return ex;
            return parent[ex]=leader(parent[ex]);
        }
        void merge(int a,int b)
        {
            a=leader(a);
            b=leader(b);
            if(a==b)
                return;
            if(siz[a]<siz[b])
                swap(a,b);
            siz[a]+=siz[b];
            parent[b]=parent[a];
        }
    };

```
