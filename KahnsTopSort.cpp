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

queue<int> topSortUtil(vector<int> adj[], vector<int>& indegrees, queue<int> q){
    queue<int> s;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        iter(adj[u]){
            if(--indegrees[*it] == 0)
                q.push(*it);
        }
        s.push(u);
    }
    return s;
}

void topologicalSort(vector<int> adj[], int v){
    queue<int> q; //queue to keep nodes with lowest indegrees;
    vector<int> indegrees(v, 0);    
    for(int i = 0; i < v; i++){
        iter(adj[i])
            indegrees[*it]++;
    }
    loop(i, v)
        if(indegrees[i] == 0)
            q.push(i);
    queue<int> s = topSortUtil(adj, indegrees, q);
    while(!s.empty()){
        cout << s.front() << " ";
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