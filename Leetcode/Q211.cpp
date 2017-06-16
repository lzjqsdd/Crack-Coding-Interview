//211. Add and Search Word - Data structure design
//题意：设计数据结构，支持添加单词以及查询单词。其中查询可以支持正则表达式查询

class WordDictionary {
public:
    /** Initialize your data structure here. */
    class TrieNode; //内部类前置声明
    WordDictionary() {
         root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for(char ch:word)
        {
            int pos = ch-'a';
            if(p->child[pos] == NULL) p->child[pos] = new TrieNode(ch); //没有就建立节点
            p = p->child[pos];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        //主要处理正则通配问题
        //每个点'.'只通配一个字符
        return search(word,root);
    }

    bool search(string word,TrieNode *proot)
    {
        TrieNode *p = proot;
        for(int i =0;i<word.size();++i)
        {
            if(word[i] == '.')
            {
                bool flag = false;
                for(int j=0;j<26;++j)
                {
                    if(p->child[j] != NULL) flag|= search(word.substr(i+1),p->child[j]);
                    if(flag) return true;
                }
                return false;
            }
            else
            {
                int pos = word[i] - 'a';
                if(p->child[pos] == NULL) return false;
                p = p->child[pos];
            }
        }
        return p->isword;
    }
public:
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
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */