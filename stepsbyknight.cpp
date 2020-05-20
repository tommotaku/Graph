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

int steps(int kpos[2], int tpos[2], int n){
    int row[8] = {-2,-1,1,2,-2,-1,1,2};
    int col[8] = {1,2,2,1,-1,-2,-2,-1};
    //8 postions of a knight

    int vis[n+1][n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            vis[i][j] = 0;

    //using bfs
    queue<tuple<int,int,int> > q; //tpos[0], tpos[1], dist
    q.push(make_tuple(kpos[0], kpos[1], 0));
    vis[kpos[0]][kpos[1]] = 1;
    while(!q.empty()){
        tuple<int, int, int> t = q.front();
        q.pop();
        int i = get<0>(t);
        int j = get<1>(t);
        int d = get<2>(t);
        if(i == tpos[0] && j == tpos[1])
            return d;
        for(int k = 0; k < 8; k++){
            if(i+row[k] >= 1 &&  i+row[k] <= n && j+col[k] >= 1 && j+col[k] <= n && !vis[i+row[k]][j+col[k]]){
                vis[i+row[k]][j+col[k]] = 1;
                q.push(make_tuple(i+row[k], j+col[k], d+1));
            }
        }
    }

}

int main(){
    int n;
    cin >> n; //n*n matrix
    int kpos[2], tpos[2]; //postion of knight and position of target;
    cin >> kpos[0] >> kpos[1];
    cin >> tpos[0] >> tpos[1];
    cout << steps(kpos, tpos, n);

}