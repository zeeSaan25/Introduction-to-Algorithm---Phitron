#include<bits/stdc++.h>
#define ll long long int
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5+5;
vector<vector<pair<int, int>>> v(N);
int dis[N];

void djkstra(int src){
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src]=0;
    while(!q.empty()){
        pair<int,int> parent = q.front();
        q.pop();
        int parentNode = parent.first;
        int parentDistance = parent.second;
        for(pair<int,int> child : v[parentNode]){
            int childNode = child.first;
            int childCost = child.second;
            if(parentDistance + childCost < dis[childNode]){
                dis[childNode] = parentDistance + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    while(e--){
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=0; i<n; i++){
        dis[i]=INT_MAX;
    }
    djkstra(0);   //source 0
    for(int i=0; i<n; i++){
        cout<<"0 -> "<<i<<" = "<<dis[i]<<endl;
    }
    return 0;
}
