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
int par[100005];
int size[100005];
struct edge{
    int u,v,w;
};
edge ar[100005];
void make_set(int v){
    par[v]=v;
    size[v]=1;
}
//path compression
int find(int v){
    if(v==par[v]) return v;
    return par[v]=find(par[v]);
}
//union by rank
void union_set(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b]) swap(a,b);
        par[b]=a;
        size[a]+=size[b];
    }
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
void solve(){
    int cost=0;
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) make_set(i);
    for(int i=0;i<m;i++){
        cin>>ar[i].u>>ar[i].v>>ar[i].w;
    }
    sort(ar,ar+m,cmp);
    for(int i=0;i<m;i++){
        if(find(ar[i].u)!=find(ar[i].v)){
            cost+=ar[i].w;
            union_set(ar[i].u,ar[i].v);
        }
    }
    cout<<cost;
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