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
pair<pair<int,int>,int> gcd(int a,int b,int x,int y){
    if(b==0){
        return {{1,0},a};
    }
    int x1,y1;
    pair<pair<int,int>,int> g=gcd(b,a%b,x1,y1);
    x=g.first.second;
    y=g.first.first-(a/b)*g.first.second;
    return {{x,y},g.second};
}
void solve(){
    int a,b,c;cin>>a>>b>>c;
    int x,y;
    pair<pair<int,int>,int> ans=gcd(a,b,x,y);
    if(c%ans.second!=0) {cout<<"No solutions\n";return;}
    ans.first.first*=c/ans.second;
    ans.first.second*=c/ans.second;
    cout<<ans.first.first<<" "<<ans.first.second<<'\n';
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