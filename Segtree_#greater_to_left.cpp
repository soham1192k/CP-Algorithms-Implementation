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
//******************************************************************************************************************************************************************
 
struct segtree{
    int size;
    vector<int>sum;
    void init(int n){
        size=1;
        while(size<n) size*=2;
        sum.assign(2*size,0ll);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            sum[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        sum[x]=sum[2*x+1]+sum[2*x+2];
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    int calc(int l,int r,int x,int lx,int rx){
        if(lx>=r||rx<=l) return 0;
        if(lx>=l&&rx<=r) return sum[x];
        int m=(lx+rx)/2;
        int s1=calc(l,r,2*x+1,lx,m);
        int s2=calc(l,r,2*x+2,m,rx);
        return s1+s2;
    }
    int calc(int l,int r){
        return calc(l,r,0,0,size);
    }
};
void solve(){
    int n;cin>>n;
    segtree st;
    st.init(n);
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.set(i,0);
    }
    // vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        int now=a[i];
        cout<<st.calc(now,n)<<" ";
        st.set(now-1,1);
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
