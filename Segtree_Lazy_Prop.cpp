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

const int N=1e5+5;
int st[4*N];
bool lazy[4*N];//true if there are some unpropagated updates
int upd[4*N];//value of that unpropagated update
//this is the process of telling the node to remember the value
void apply(int si,int ss,int se,int val){
    st[si]+=val*(se-ss+1);//store the correct info
    if(ss!=se){
        lazy[si]=1;//mark it lazy
        upd[si]+=val;//store the unpropagated value
    }
}
//pushing down the unpropagated value deeper into the tree
void pushdown(int si,int ss,int se){
    if(lazy[si]){
        lazy[si]=false;//no more lazy
        int m=(ss+se)>>1;
        apply(2*si,ss,m,upd[si]);
        apply(2*si+1,m+1,se,upd[si]);
        upd[si]=0;//update done
    }
}
int query(int si,int ss,int se,int qs,int qe){
    if(se<qs||qe<ss) return 0;
    if(ss>=qs&&se<=qe) return st[si];
    //we remove lazy tag before going down,so that children have correct info
    pushdown(si,ss,se);
    int m=(ss+se)>>1;
    return query(2*si,ss,m,qs,qe)+query(2*si+1,m+1,se,qs,qe);
}
void update(int si,int ss,int se,int qs,int qe,int val){
    if(se<qs||qe<ss) return;
    if(ss>=qs&&se<=qe){
        apply(si,ss,se,val);
        return;
    }
    pushdown(si,ss,se);
    int m=(ss+se)>>1;
    update(2*si,ss,m,qs,qe,val);
    update(2*si+1,m+1,se,qs,qe,val);
    st[si]=st[2*si]+st[2*si+1];
}
void solve(){
    
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
