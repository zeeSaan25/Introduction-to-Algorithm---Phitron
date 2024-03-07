#include<bits/stdc++.h>
#define ll long long int
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5+5;

int main(){
    ll n,e;
    cin>>n>>e;
    ll adj[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj[i][j] = INT_MAX;
            if(i==j) adj[i][j] = 0;
        }
    }
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a][b] = c;
    }
    cout<<"BEFORE"<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj[i][j]==INT_MAX) cout<<"INF ";
            else cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    cout<<endl<<"AFTER"<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(adj[i][j]==INT_MAX) cout<<"INF ";
            else cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}