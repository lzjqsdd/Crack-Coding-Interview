//290. Word Pattern 
//bijection 单射，一对一 ,建立双向的dict

pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.



bool wordPattern(string pattern, string str) {
    map<char,string> dict;
    map<string,char> dict2;
    vector<string> sv;
    istringstream in(str);
    string s;
    while(in>>s) sv.push_back(s);
    if(pattern.size() != sv.size()) return false;
    for(int i=0;i<pattern.size();i++)
    {
            if( dict.find(pattern[i]) == dict.end() &&  dict2.find(sv[i])==dict2.end()  ) //映射不存在
            {
                dict[pattern[i]] = sv[i];
                dict2[sv[i]] = pattern[i];
            }
            else
            {
                if(dict[pattern[i]] != sv[i]) return false;
            }
    }
    return true;
}