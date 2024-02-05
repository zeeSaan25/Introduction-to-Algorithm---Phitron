#include<bits/stdc++.h>
#define ll long long int
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n,m;
char a[20][20];
bool vis[20][20];
vector<pair<int, int>> d = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}

void dfs(int si, int sj){
    cout<<si<<" "<<sj<<endl;
    vis[si][sj]=true;
    for(int i=0; i<4; i++){
        int ci = si+d[i].first;
        int cj = sj+d[i].second;
        if(valid(ci, cj)==true && vis[ci][cj]==false){
            dfs(ci, cj);
        }

    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    int si, sj;
    cin>>si>>sj;
    memset(vis, false, sizeof(vis));
    dfs(si, sj);
    return 0;
}
