#include<bits/stdc++.h>
#define ll long long int
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5+5;
bool vis[N];
bool pathVisit[N];
vector<vector<int>> v(N);
bool ans;

void dfs(int parent){
    vis[parent]=true;
    pathVisit[parent]=true;
    for(auto child : v[parent]){
        if(pathVisit[child]){
            ans = true;
        }
        if(!vis[child]){
            dfs(child);
        }
    }
    pathVisit[parent] = false;
}

int main(){
    int n, e;
    cin>>n>>e;
    while(e--){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathVisit, false, sizeof(pathVisit));
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    (ans) ? cout<<"Cycle Detected!"<<endl : cout<<"No Cycle Detected!"<<endl;
    return 0;
}