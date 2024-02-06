#include<bits/stdc++.h>
#define ll long long int
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m;
char a[20][20];
int dis[20][20];
bool vis[20][20];
vector<pair<int, int>> d = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj]=true;
    dis[si][sj]=0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        //int a = p.first, b=p.second;
        q.pop();
        //cout<<p.first<<" "<<p.second<<endl;
        for(int i=0; i<4; i++){
            int ci = p.first+d[i].first;
            int cj = p.second+d[i].second;
            if(valid(ci, cj)==true && vis[ci][cj]==false){
                q.push({ci, cj});
                vis[ci][cj]=true;
                dis[ci][cj]=dis[p.first][p.second]+1;
            }
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
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);
    cout<<dis[2][2];
    return 0;
}