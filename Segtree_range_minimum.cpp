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

int ar[100001],st[400004];
void build(int si,int ss,int se){
    if(ss==se) {st[si]=ar[ss];return;}
    int m=(ss+se)>>1;
    build(2*si,ss,m);
    build(2*si+1,m+1,se);
    st[si]=min(st[2*si],st[2*si+1]);
}
int query(int si,int ss,int se,int qs,int qe){
    if(ss>qe||se<qs) return 1e18;
    if(ss>=qs&&se<=qe) return st[si];
    int m=(ss+se)>>1;
    int m1=query(2*si,ss,m,qs,qe);
    int m2=query(2*si+1,m+1,se,qs,qe);
    return min(m1,m2);
}
void solve(){
    int n,q,l,r;cin>>n;
    for(int i=1;i<=n;i++) cin>>ar[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<query(1,1,n,l+1,r+1)<<'\n';
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
