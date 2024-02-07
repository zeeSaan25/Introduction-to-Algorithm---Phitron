#include<bits/stdc++.h>
#define ll long long int
#define boost() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int>> v(n);
    while(e--){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin>>q;
    while(q--){
        vector<int> d;
        int src;
        cin>>src;
        for(auto u:v[src]){
            d.push_back(u);
        }
        sort(d.rbegin(), d.rend());
        if(d.empty()){
            cout<<-1<<endl;
        }
        else{
            for(auto ans : d){
                cout<<ans<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}