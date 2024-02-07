#include<bits/stdc++.h>
#define ll long long int
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e3+3;
int main(){
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    while(e--){
        int a,b;
        cin>>a>>b;
        mat[a][b]=1;
    }
    int q;
    cin>>q;
    while(q--){
        int c,d;
        cin>>c>>d;
        if(c==d || mat[c][d]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
