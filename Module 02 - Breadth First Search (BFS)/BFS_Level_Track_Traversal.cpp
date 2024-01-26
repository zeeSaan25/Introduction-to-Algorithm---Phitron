#include<bits/stdc++.h>
#define ll long long int
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<vector<int>> v(1005);
bool vis[1005];
int level[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    level[src]=0;
    vis[src] = true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        //cout<<parent<<" ";
        for(auto child : v[parent]){
            if(vis[child]==false){
                q.push(child);
                vis[child] = true;
                level[child] = level[parent]+1;
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
    int src;
    cin>>src;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(src);
    for(int i=0; i<n; i++){
        cout<<i<<" "<<level[i]<<endl;
    }
    return 0;
}