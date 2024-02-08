#include<bits/stdc++.h>
#define ll long long int
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 1e5+5;
bool vis[N];
int parentArray[N];
vector<vector<int>> v(N);
bool ans;

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        //cout<<parent<<endl;
        for(auto child : v[parent]){
            if(vis[parent]==true && parentArray[parent]!=child){
                ans = true;
            }
            
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                parentArray[child]=parent;
            }
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
    memset(parentArray, -1, sizeof(parentArray));
    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans = false;
            bfs(i);
        }
    }

    (ans) ? cout<<"Cycle Detected"<<endl : cout<<"No Cycle Detected"<<endl;
    return 0;
}
