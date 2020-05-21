
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

bool isCyclicUtil(vector<int> adj[], vector<int> indegree, queue<int> q, int v){
    int count = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            if(--indegree[*it] == 0)
                q.push(*it);
        }
        count++;
    }
    if(count != v) return true;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++){
        for(auto it = adj[i].begin(); it != adj[i].end(); it++)
            indegree[*it]++;
    }
    queue<int> q;
    for(int i = 0; i < V; i++)
        if(indegree[i] == 0)
            q.push(i);
            
    return isCyclicUtil(adj, indegree, q, V);
}

int main(){
    int v, e; //no of vertices and edges
    cin >> v >> e;
    vector<int> adj[v];
    while(e--){
        int u, c;
        cin >> u >> c;
        adj[u].pb(c); 
    }
    if(isCyclic(v, adj)) cout << "Yes";
    else cout << "No";
}