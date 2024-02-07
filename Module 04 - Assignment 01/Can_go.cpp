#include<bits/stdc++.h>
#define ll long long int
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int n,m;
int srci, srcj, desi, desj;
bool vis[1000][1000];
char a[1000][1000];
vector<pair<int, int>> v = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}

void dfs(int si, int sj){
    //cout<<si<<" "<<sj<<endl;
    vis[si][sj]=true;
    for(int i=0; i<4; i++){
        int ci = si+v[i].first;
        int cj = sj+v[i].second;
        if(valid(ci,cj)==true && vis[ci][cj]==false && (a[ci][cj]=='.' || a[ci][cj]=='B')){
            dfs(ci,cj);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                srci=i;
                srcj=j;
            }
            if(a[i][j]=='B'){
                desi=i;
                desj=j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(srci,srcj);
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<vis[i][j];
    //     }
    //     cout<<endl;
    //}
    if(vis[desi][desj]) yes;
    else no;
    return 0;
}