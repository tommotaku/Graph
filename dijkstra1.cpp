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

vector<int> dijkstra(int adj[][9], int v, int src){
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    set<pii> s;
    s.insert(mp(dist[src], src));
    while(!s.empty()){
        int u = (*s.begin()).S;
        s.erase(s.begin());
        if(dist[u] != INT_MAX)//to avoid overflow during addtion
        {
            for(int i = 0; i < v; i++){
                if(dist[u]+adj[u][i] < dist[i] && adj[u][i]!=0){
                    if(dist[i]!=INT_MAX){//some distance of i exists in set
                        s.erase(s.find(mp(dist[i], i)));
                    }
                    dist[i] = dist[u]+adj[u][i];
                    s.insert(mp(dist[i], i));
                }
            }
        }
    }
    return dist;
}

int main(){
    int v = 9;
    int adj[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    //shortest distance from 0 to every other vertex;
    vector<int> dist = dijkstra(adj, v, 0);
    cout << "Distance of each vertext from 0" << endl;
    for(int i = 0; i < v; i++)
        cout << i << " " << dist[i] << endl;
}