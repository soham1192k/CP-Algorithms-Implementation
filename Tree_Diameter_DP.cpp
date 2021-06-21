//Soham
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define soham1192k ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<'\n';
#else
#define debug(x)
#endif
const int mod=1e9+7;
const double pi = 3.14159265358979323846;
const int mxN=2e5+1;
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//******************************************************************************************************************************************
vector<int>adj[200005];
int f[200005];
int g[200005];
void dfs(int src,int par){
    f[src]=0;g[src]=0;
    bool leaf=true;
    vector<int>hold;
    for(auto edge:adj[src]){
        if(edge==par) continue;
        leaf=false;
        dfs(edge,src);
        f[src]=max(f[src],f[edge]);
        hold.push_back(f[edge]);
    }
    if(!leaf) f[src]++;
    if(leaf) return;
    sort(hold.begin(),hold.end());
    if(hold.size()==1) g[src]=1+hold.back();
    else g[src]=2+hold.back()+hold[(int)hold.size()-2];
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    int maxx=0;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,g[i]);
    }
    cout<<maxx<<'\n';
}
int32_t main(){
    soham1192k;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
#endif 
    int T=1;
    // cin>>T;  
    while(T--){
        solve();
    }
    return 0;
}
