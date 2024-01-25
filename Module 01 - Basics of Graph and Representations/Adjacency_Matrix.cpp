#include<bits/stdc++.h>
#define       ll               long long int
#define       F                first
#define       S                second
#define       yes              cout<<"YES"<<endl
#define       no               cout<<"NO"<<endl
#define       all(a)           a.begin(),a.end()
#define       pb               push_back
#define       nl               cout<<endl
#define       lcm(a,b)         (a*b)/__gcd(a,b)
#define       endl             '\n'
#define       boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    while(e--){
        int a,b;
        cin>>a>>b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
