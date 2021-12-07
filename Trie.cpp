class Node{
    public:
    Node* links[26];
    bool flag;
    int wordcount;
    int prefixcount;
    Node(){
        for(int i=0;i<26;i++){
            this->links[i]=NULL;
        }
        this->flag=false;
        this->wordcount=this->prefixcount=0;
    }
    bool containsKey(char ch){
        return (this->links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return this->links[ch-'a'];
    }
    void put(char ch,Node* node){
        this->links[ch-'a']=node;
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string& word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->prefixcount++;
        }
        node->wordcount++;
        node->flag=true;
    }
    int countWordsEqualTo(string& word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->wordcount;
    }
    int countWordsStartingWith(string& prefix){
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return 0;
            }
            node=node->get(prefix[i]);
        }
        return node->prefixcount;
    }
    void erase(string& word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->prefixcount--;
            }
            else return;
        }
        node->wordcount--;
    }
};
