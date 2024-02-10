
## kosaraju

- kosaraju
- ```
  https://thesobersobber.github.io/CP-Snippets/kosaraju
  ```
- [github-snip-file](https://github.com/theSoberSobber/CP-Snippets/blob/main/snippets.json#L1360)

```cpp
class Graph {
 int V;
 vector<int> *adj;

 void fillOrder(int v, bool visited[], stack<int> &s);

 void dfsUtil(int v, bool visited[]);

public:
 Graph(int V) : V(V)
 {
   adj = new vector<int>[V];
 }
 ~Graph()
 {
    delete[] adj;
 }

 void addEdge(int v, int w);

 void printSCCs();

 Graph getTranspose();
};

void Graph::dfsUtil(int v, bool visited[]) {
 visited[v] = true;
 cout << v <<  " ";
 for (auto &it : adj[v])
     if (!visited[it])
        dfsUtil(it, visited);
}

Graph Graph::getTranspose() {
 Graph g(V);
 for (int i = 0; i < V; i++) {
     for (auto &it : adj[i])
         g.adj[it].push_back(i);
 }
 return g;
}

void Graph::addEdge(int v, int w) {
 adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &s) {
 visited[v] = true;
 for (auto &it : adj[v])
     if (!visited[it])
         fillOrder(it, visited, s);
 s.push(v);
}

void Graph::printSCCs() {
 stack<int> s;
 bool visited[V] = {0};
 for (int i = 0; i < V; i++)
      if (!visited[i])
        fillOrder(i, visited, s);

 Graph gr = getTranspose();
 for (int i = 0; i < V; i++)
     visited[i] = false;

 while (!s.empty()) {
     int v = s.top();
     s.pop();
     if (!visited[v]){
        gr.dfsUtil(v, visited);
        cout << "
";
     }
 }
}
```
