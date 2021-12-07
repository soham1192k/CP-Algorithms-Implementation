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

vector<int>rabin_karp(string& s,string& t){
    int p=31;
    int m=1e9+9;
    int S=s.length();
    int T=t.length();
    vector<int>ans;
    vector<int>p_pow(max(S,T));
    p_pow[0]=1;
    for(int i=1;i<(int)p_pow.size();i++){
        p_pow[i]=(p_pow[i-1]*p)%m;
    }
    vector<int>hash(T+1,0);
    for(int i=0;i<T;i++){
        hash[i+1]=(hash[i]+((t[i]-'a'+1)*p_pow[i])%m)%m;
    }
    for(int i=0;i<T;i++){
        cout<<i+1<<": "<<hash[i+1]<<'\n';
    }
    int hash_s=0;
    for(int i=0;i<S;i++){
        hash_s=(hash_s+((s[i]-'a'+1)*p_pow[i])%m)%m;
    }
    cout<<hash_s<<'\n';
    for(int i=0;i+S-1<T;i++){
        int curr_hash=(hash[i+S]-hash[i]+m)%m;
        if(curr_hash==(hash_s*p_pow[i])%m)
        ans.push_back(i);
    }
    return ans;
}
void solve(){
    string s="soham";
    string t="sohamisbadsohamisgood";
    vector<int>ans=rabin_karp(s,t);
    for(auto x:ans) cout<<x<<" ";
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
