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
    vector<pair<int, int>> v;
    while(e--){
        int a,b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    for(pair<int, int> x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}