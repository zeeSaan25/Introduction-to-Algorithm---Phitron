#include<bits/stdc++.h>
#define ll long long int
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<vector<int>> v(1005);
bool vis[1005];

void bfs(int src, int des){
    queue<pair<int,int>> q;
    q.push({src, 0});
    vis[src] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int parent = p.first;
        int level = p.second;
        if(parent == des){
            cout<<level;
        }
        for(auto child : v[parent]){
            if(vis[child]==false){
                q.push({child,level+1});
                vis[child] = true;
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
    int src, des;
    cin>>src>>des;
    memset(vis, false, sizeof(vis));
    bfs(src, des);
    return 0;
}