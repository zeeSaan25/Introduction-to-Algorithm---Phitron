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
    vector<int> mat[n];
    while(e--){
        int a,b;
        cin>>a>>b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    for(auto u:mat[1]){
        cout<<u<<" ";
    }
    return 0;
}