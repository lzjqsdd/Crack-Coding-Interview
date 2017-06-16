//题意：实现字典树
//http://www.cnblogs.com/binyue/p/3771040.html
//http://dongxicheng.org/structure/trietree/


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(char ch:word)
        {
            int pos = ch-'a';
            if(p->child[pos] == NULL) p->child[pos] = new TrieNode(ch); //没有就建立节点
            p = p->child[pos];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(char ch:word)
        {
            int pos = ch-'a';
            if(p->child[pos] == NULL) return false;
            p = p->child[pos];
        }
        //但是word可能能搜到，但是只是一个前缀，所以必须判断是否到叶子节点了
        return p->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(char ch:prefix)
        {
            int pos = ch-'a';
            if(p->child[pos] == NULL) return false;
            p = p->child[pos];
        }
        return true;
    }
    class TrieNode{
    public:
        char c;
        bool isword; //表示当前位置是否可以组成一个单词，比如字典树中abc,abcdef都存在，那么abc也是单词。
        TrieNode *child[26];
        TrieNode(){
            for(int i = 0;i<26;++i) child[i] = NULL;
            isword = false;
        }
        TrieNode(char c){
            for(int i = 0;i<26;++i) child[i] = NULL;
            this->c = c;
            isword = false;
        }
    };
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */