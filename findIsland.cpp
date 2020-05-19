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

void dfs(vector<vector<int> > adj, int i, int j, int n, int m, vector<vector<int> > &vis){
    vis[i][j] = 1;
    int row[8] = {-1, -1, -1, 0,0 , 1, 1,1};
    int col[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for(int k = 0; k < 8; k++){
        if(i+row[k] >= 0 && i+row[k] < n && j+col[k] >= 0 && j+col[k] < m && !vis[i+row[k]][j+col[k]]
            && adj[i+row[k]][j+col[k]])
                dfs(adj, i+row[k], j+col[k], n, m, vis);
    }
}

int findisland(vector<vector<int> > adj, int n, int m){
    vector<vector<int> > vis;
    loop(i,n){
        vector<int> v;
        loop(j,m){
            v.pb(0);
        }
        vis.pb(v);
    }
    int count = 0;
    loop(i,n){
        loop(j,m){
            if(!vis[i][j] && adj[i][j]){
                dfs(adj, i, j, n, m, vis);
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<int> > adj;
    int n, m; //row and column;
    cin >> n >> m;
    loop(i,n){
        vector<int> v(m);
        loop(j,m){
            cin >> v[j];
        }
        adj.pb(v);
    }
    cout << findisland(adj, n, m) << endl;
}