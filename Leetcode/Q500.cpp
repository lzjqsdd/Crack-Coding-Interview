
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        char line[][] = {"QWERTYUIOPqwertyuiop","ASDFGHJKLasdfghjkl","ZXCVBNMzxcvbnm"};
        map<char,int> dict;
        for(int i=0;i<2;i++)
        for(int j=0;j!='\0';++j)
        {
            dict[line[i][j]]=i;
        }
        
        vector<string> result;
        for(auto it=words.begin();it!=words.end();++it)
        {
            for(int k=1;k<words.size();++k)
            {
                if( dict[(*it)[k]] != dict[(*it)[k-1]] )
                    break;
            }
            if(k == word.size()-1)
        }
        
    }
};