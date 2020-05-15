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

bool isCycleUtil(vector<int> adj[], int u, int parent, vector<bool> &vis){
    vis[u] = true;
    iter(adj[u]){
        if(!vis[*it]){
            if(isCycleUtil(adj, *it, u, vis))
                return true;
        }
        else if(*it != parent)
            return true;
    }
    return false;
}

bool isCycle(vector<int> adj[], int v){
    vector<bool> vis(v, false);
    for(int i = 0; i < v; i++){
        if(!vis[i])
            if(isCycleUtil(adj, i, -1, vis))
                return true;
    }
    return false;
}

int main(){
    int v, e; //no of vertices and edges
    cin >> v >> e;
    vector<int> adj[v];
    while(e--){
        int u, c;
        cin >> u >> c;
        adj[u].pb(c); 
        adj[c].pb(u);
    }
    if(isCycle(adj, v)) cout << "Yes";
    else cout << "No";
}