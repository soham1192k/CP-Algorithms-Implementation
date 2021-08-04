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

class TrieNode{
public:
    TrieNode* children[26];
    bool isEndofWord;
    TrieNode(){
        for(int i=0;i<=25;i++) this->children[i]=NULL;
        this->isEndofWord=false;
    }
};
void insert(TrieNode* root,string key){
    TrieNode* curr=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(curr->children[index]==NULL) curr->children[index]=new TrieNode();
        curr=curr->children[index];
    }
    curr->isEndofWord=true;
}
bool search(TrieNode* root,string key){
    TrieNode* curr=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(curr->children[index]==NULL) return false;
        curr=curr->children[index];
    }
    if(curr->isEndofWord) return true;
    return false;
}
bool isEmpty(TrieNode* root){
    for(int i=0;i<26;i++){
        if(root->children[i]) return false;
    }
    return true;
}
TrieNode* remove(TrieNode* root,string key,int depth=0){
    if(root==NULL) return NULL;
    if(depth==key.size()){
        if(root->isEndofWord) root->isEndofWord=false;
        if(isEmpty(root)) {delete(root);root=NULL;}
        return root;
    }
    int index=key[depth]-'a';
    root->children[index]=remove(root->children[index],key,depth+1);
    if(isEmpty(root)&&root->isEndofWord==false){
        delete(root);
        root=NULL;
    }
    return root;
}
void solve(){
    int n;cin>>n;
    TrieNode* root=new TrieNode();
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        insert(root,s);
    }
    int m;cin>>m;
    for(int i=1;i<=m;i++){
        string s;cin>>s;
        cout<<search(root,s)<<'\n';
    }
    remove(root,"heroplane",0);
    cout<<search(root,"heroplane")<<'\n';
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
