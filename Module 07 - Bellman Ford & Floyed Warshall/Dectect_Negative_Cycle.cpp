#include<bits/stdc++.h>
#define ll long long int
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5+5;
int dis[N];
class Edge{
    public:
    int u,v,c;
    Edge(int u, int v, int c){
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main(){
    bool flag = false;
    vector<Edge> edgeList;
    int n,e;
    cin>>n>>e;
    while(e--){
        int u,v,c;
        cin>>u>>v>>c;
        edgeList.push_back(Edge(u,v,c));
    }
    
    for(int i=0; i<n; i++){
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    for(int i=0; i<n-1; i++){
        for(auto edge : edgeList){
            if(dis[edge.u] < INT_MAX && dis[edge.u] + edge.c < dis[edge.v]){
            dis[edge.v] = dis[edge.u] + edge.c;
            }
        }
    }
    for(auto edge : edgeList){
        if(dis[edge.u] < INT_MAX && dis[edge.u] + edge.c < dis[edge.v]){
            flag = true;
            break;
        }
    }
    
    if(flag == true){
        cout<<"Cycle Detected!"<<endl<<"No Answer"<<endl;
    }
    else{
        for(int i=0; i<n; i++){
            cout<<"0 -> "<<i<<" = "<<dis[i]<<endl;
        }
    }
    return 0;
}