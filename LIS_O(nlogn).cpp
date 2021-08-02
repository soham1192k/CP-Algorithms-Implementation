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

void solve(){
	int n;cin>>n;
    vector<int>a(n);
    for(int&x:a) cin>>x;
    vector<int>dp(n+1,1e9);
    //d[l]<inf biggest such l
    dp[0]=-1e9;
    vector<int>index(n+1,-1);
    vector<int>p(n,-1);
    for(int i=0;i<n;i++){
        int j=upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
        if(dp[j-1]<a[i]&&a[i]<dp[j]){
            dp[j]=a[i];
            index[j]=i;
            p[i]=index[j-1];
        }
    }
    int maxx=0;int pos=-1;
    for(int i=n;i>=1;i--){
        if(dp[i]<1e9) {pos=index[i];break;}
    }
    vector<int>hold;
    int curr=pos;
    while(curr!=-1){
        hold.push_back(a[curr]);
        curr=p[curr];
    }
    reverse(hold.begin(),hold.end());
    for(auto x:hold) cout<<x<<" ";
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
