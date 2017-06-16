//Longest Word in Dictionary through Deleting
//题意：给定一个长字符串，以及一组字典。从字典中找出最长的字符串，该字符串可以由长字符串删减去某些字符得到
//可以对字符串排序，然后找最长子串即可。然而排序后字符串可能对不上号，所以不能直接根据子串查找




//下列方法，由于对s进行了排序，导致原有的序发生了变化，所有结果不正确
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),cmp);
        //for(auto ss:d) cout << ss << endl;
        map<char,int> dict;
        for(auto c:s) dict[c]++;
        for(auto it = d.rbegin();it!=d.rend();++it) //从长的字符串查起
        {
            map<char,int> tmp(dict);
            int flag = 0;
            for(auto c:*it)
                if(tmp.find(c) != tmp.end() && tmp[c] > 0) tmp[c]--;
                else {flag = 1;break; }
            if(flag == 0) return *it;
        }
        return "";
    }
private:
        static bool cmp(const string&s1,const string &s2)
        {
            //return (s1.size() < s2.size() || s1 < s2); //先看长度
            if(s1.size() < s2.size()) return true;
            else if(s1.size() > s2.size()) return false;
            else return s1 > s2;
        }
};


//关键是排好序
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),cmp);
        for(auto it = d.rbegin();it!=d.rend();++it) //从长的字符串查起
        {
            int i = 0,j=0;
            while(i<it->size() && j<s.size())
            {
                if((*it)[i] == s[j] ) {++i;++j;}
                else {++j;}
            }
            if(i==it->size()) return *it;
        }
        return "";
    }
private:
        static bool cmp(const string&s1,const string &s2)
        {
            //return (s1.size() < s2.size() || s1 < s2); //先看长度
            if(s1.size() < s2.size()) return true;
            else if(s1.size() > s2.size()) return false;
            else return s1 > s2;
        }
};