
## rr-segtree

- best segtree
- ```
  https://thesobersobber.github.io/CP-Snippets/rr-segtree
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1793)

```cpp
int phi[N+1];
 
struct node
{
     long long sum,max,lca,size;
     node()
     {  
          lca=-1;
          max=-1;
          sum=-1;
          size=0;
     };
};
 
struct Segment_Tree
{
     vector<node> segtree;
     int n;
     node identity;
 
     void init(int _n)
     {
          identity.lca=-1;
          identity.sum=0;
          identity.max=-1;
          identity.size=0;
 
          n=1;
          while(n<_n)
               n=n*2;
          segtree.resize(2*n);
     }
 
     node merge(node a,node b)
     {
            if(a.lca<1)
                return b;
            if(b.lca<1)
                return a;
 
            node ans;
            ans.max=std::max(a.max,b.max);
            ans.sum=a.sum+b.sum;
            ans.size=a.size+b.size;
 
            int ex=50;
            int A=a.lca;
            int B=b.lca;
 
            while(true)
            {
                if(A==B)
                    break;
                if(A>B)
                {
                    ans.sum=ans.sum+a.size;
                    A=phi[A];
                }
                else
                {
                    ans.sum=ans.sum+b.size;
                    B=phi[B];
                }
            }
            ans.lca=A;
 
            return ans;
     }
 
     void build(int curr,int left,int right,vector<int>&ar)
     {
 
          if(right-left==1)
          {
               if(left<ar.size())
               {
                    segtree[curr].sum=0;
                    segtree[curr].max=ar[left];
                    segtree[curr].lca=ar[left];
                    segtree[curr].size=1;
               }
               else
               {
                    segtree[curr].sum=0;
                    segtree[curr].max=-1;
                    segtree[curr].lca=-1;
                    segtree[curr].size=0;
               }
               return;
          }
 
          int mid=(left+right)/2;
          build(2*curr+1,left,mid,ar);
          build(2*curr+2,mid,right,ar);
 
          segtree[curr]=merge(segtree[2*curr+1],segtree[2*curr+2]);
      }
 
     node sum(int lq,int rq,int node,int left,int right)
     {
 
          if(lq>=right || rq<=left)
               return identity;
          if(left>=lq && rq>=right)
               return segtree[node];
 
          int mid=(left+right)/2;
          return merge(sum(lq,rq,2*node+1,left,mid),sum(lq,rq,2*node+2,mid,right));
     }
 
     void operate(int lq,int rq,int curr,int left,int right)
     {
          if(lq>=right || rq<=left)
                    return;
 
          if(right-left==1)
          {
               int val=segtree[curr].lca;
               val=phi[val];
               segtree[curr].lca=val;
               segtree[curr].max=val;
               segtree[curr].sum=0;
               segtree[curr].size=1;
               return;
          }
 
          if(segtree[curr].max<=1)
               return;
 
          int mid=(left+right)/2;
          operate(lq,rq,2*curr+1,left,mid);
          operate(lq,rq,2*curr+2,mid,right);
 
          segtree[curr]=merge(segtree[2*curr+1],segtree[2*curr+2]);
     }
 
};

```
