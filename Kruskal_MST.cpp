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
int n,m;
struct edge{
    int a;
    int b;
    int w;
};
edge ar[100005];
int par[100005];
bool cmp(edge p,edge q){
    return p.w<q.w;
}
int find(int a){
    if(par[a]==-1) return a;
    return par[a]=find(par[a]);
}
void merge(int a,int b){
    par[a]=b;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++) par[i]=-1;
    for(int i=0;i<m;i++){
        cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }
    int sum=0;int a,b;
    sort(ar,ar+m,cmp);
    for(int i=0;i<m;i++){
        a=find(ar[i].a);
        b=find(ar[i].b);
        // cout<<a<<" "<<b<<'\n';
        if(a!=b){
            sum+=ar[i].w;
            merge(a,b);
        }
    }
    cout<<sum<<'\n';
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