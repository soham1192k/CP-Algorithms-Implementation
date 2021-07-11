class Trie{
    public:
    map<char,Trie*>children;
    bool endOfWord;
    Trie(){
        this->endOfWord=false;
    }
};
Trie* root=new Trie();
void insert(string& s){
    Trie* curr=root;
    for(int i=0;i<s.length();i++){
        Trie* node=curr->children[s[i]];
        if(node==NULL){
            node=new Trie();
            curr->children[s[i]]=node;
        }
        curr=node;
    }
    curr->endOfWord=true;
}
bool search(string& s){
    Trie* curr=root;
    for(int i=0;i<s.length();i++){
        Trie* node=curr->children[s[i]];
        if(node==NULL){
            return false;
        }
        curr=node;
    }
    if(curr->endOfWord) return true;
    return false;
}
bool delete_word(Trie* curr,string& s,int idx){
    if(idx==s.length()){
        if(!curr->endOfWord) return false;
        curr->endOfWord=false;
        return curr->children.size()==0;
    }
    Trie* node=curr->children[s[idx]];
    if(node==NULL){
        return false;
    }
    bool shouldDelete=delete_word(node,s,idx+1);
    if(shouldDelete){
        curr->children.erase(s[idx]);
        return curr->children.size()==0;
    }
    return false;
}
