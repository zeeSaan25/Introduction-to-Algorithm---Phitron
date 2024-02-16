#include<bits/stdc++.h>
#define ll long long int
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const long long int N = 1e5+5;
vector<vector<int>> v(N);
bool vis[N];
ll parentArray[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        ll parent = q.front();
        q.pop();
        for(auto child : v[parent]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                parentArray[child]=parent;
            }
        }
    }
}

int main(){
    ll n,e;
    cin>>n>>e;
    ll des = n;
    while(e--){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    bfs(1);
    vector<ll> path;
    ll x = des;
    if(parentArray[des]==-1) cout<<"IMPOSSIBLE"<<endl;
    else{
        while(x!=-1){
            path.push_back(x);
            x = parentArray[x];
        }
        cout<<path.size()<<endl;
        reverse(path.begin(), path.end());
        for(int i=0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }
    }

    return 0;
}
