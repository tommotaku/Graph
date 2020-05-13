#include <bits/stdc++.h>
using namespace std;
#define pb push_back  
#define loop(i,n) for(int i = 0; i < n; i++)
#define mp make_pair
#define F first
#define S second
#define asort(a) sort(a,a+n)
#define vsort(v) sort(v.begin(), v.end())
#define remdup(v) v.erase(unique(v.begin(), v.end()), v.end())
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

void topSortUtil(int u, vector<int> adj[], vector<bool>& vis, stack<int>& s){
    vis[u] = true; //mark visited
    iter(adj[u]){
        if(!vis[*it])
            topSortUtil(*it, adj, vis, s); //first mark all children of children of.... 
    }
    s.push(u);
}

void topologicalSort(vector<int> adj[], int v){
    vector<bool> vis(v, false); // vector to keep track of visited nodes;
    stack<int> s; //stack to keep the topological sorted nodes;
    for(int i = 0; i < v; i++){
        if(!vis[i])
            topSortUtil(i, adj, vis, s);
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

int main(){
    int v, e; //no of vertices and edges
    cin >> v >> e;
    vector<int> adj[v];
    while(e--){
        int u, c;
        cin >> u >> c;
        adj[u].pb(c); //directed graph
    }
    topologicalSort(adj, v);
}