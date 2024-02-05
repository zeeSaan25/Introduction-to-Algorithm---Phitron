#include<bits/stdc++.h>
#define ll long long int
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 1e5+5;
vector<vector<int>> v(N);
bool vis[N];

void dfs(int src){
    cout<<src<<" ";
    vis[src] = true;
    for(auto child : v[src]){
        if(vis[child]==false){
            dfs(child);
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    while(e--){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    dfs(0);    ///Assumeing source 0 
    return 0;
}
