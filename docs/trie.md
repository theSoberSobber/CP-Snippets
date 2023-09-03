
## trie

- trie
- ```
  https://thesobersobber.github.io/CP-Snippets/trie
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1856)

```cpp
struct Trie{
    struct node{
        node* next[10];
        node(){
            for(int i=0;i<10;i++) next[i]=NULL;
        }
    };
 
    node root;
 
    void add(vector<int>&val){
        node* temp=&root;
        for(auto ele : val){
            if(temp->next[ele]==NULL) temp->next[ele]=new node();
            temp=temp->next[ele];
        }
    }
 
    int query(vector<int>&val){
        node* temp=&root;
        int ans=0;
        for(auto ele : val){
            if(temp->next[ele]==NULL) break;
            ans++;
            temp=temp->next[ele];
        }
        return ans;
    }
};

```
