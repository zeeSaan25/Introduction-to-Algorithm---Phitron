#include<bits/stdc++.h>
#define ll long long int
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<vector<int>> v(1005);
bool vis[1005];
int level[1005];
int par[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    level[src]=0;
    vis[src] = true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(auto child : v[parent]){
            if(vis[child]==false){
                q.push(child);
                vis[child] = true;
                level[child] = level[parent]+1;
                par[child] = parent;
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src,des;
    cin>>src>>des;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(par, -1, sizeof(par));
    bfs(src);
    vector<int> path;
    int x = des;
    while(x!=-1){
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(), path.end());
    for(auto u:path){
        cout<<u<<" ";
    }
    return 0;
}