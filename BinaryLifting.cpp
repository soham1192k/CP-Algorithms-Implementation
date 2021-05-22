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
const int mxN=2e5+2;
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
//***************************************************************************************************************************************************************
vector<int>adj[10005];
int lca[10005][15];
int lvl[10005];
void dfs(int src,int par,int l){
    lca[src][0]=par;
    lvl[src]=l;
    for(auto edge:adj[src]){
        if(edge!=par) dfs(edge,src,l+1);
    }
}
int leastca(int a,int b){
    if(lvl[a]>lvl[b]) swap(a,b);
    int d=lvl[b]-lvl[a];
    while(d>0){
        int i=log2(d);
        b=lca[b][i];
        d-=(1ll<<i);
    }
    if(a==b) return a;
    for(int i=14;i>=0;i--){
        if(lca[a][i]!=-1&&(lca[a][i]!=lca[b][i])){
            a=lca[a][i];
            b=lca[b][i];
        }
    }
    return lca[a][0];
}
void solve(){
    int n;cin>>n;
    memset(lca,-1,sizeof(lca));
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,0);
    for(int j=1;j<=14;j++){
        for(int i=1;i<=n;i++){
            if(lca[i][j-1]!=-1){
                int par=lca[i][j-1];
                lca[i][j]=lca[par][j-1];
            }
        }
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int a,b;cin>>a>>b;
        cout<<leastca(a,b)<<'\n';
    }
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