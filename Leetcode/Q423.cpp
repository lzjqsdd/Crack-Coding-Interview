class Solution {
public:
    string originalDigits(string s) {
        map<char,int> dict;
        vector<int> re(10,0); //0~9的个数
        string search = "zwxghsrvin"; // 依次判别{0,2,6,8},{3,7},{4,5},{9},{1}
        vector<int> number = {0,2,6,8,3,7,4,5,9,1};
         
        //关键字母对应的数字
        map<char,int> dictn = {{'z',0},{'w',2},{'x',6},{'g',8},{'h',3},
                        {'s',7},{'r',4},{'v',5},{'i',0},{'n',1}};
        map<char,string> dicts = {{'z',"zero"},{'w',"two"},{'x',"six"},{'g',"eight"},{'h',"three"},
                        {'s',"seven"},{'r',"four"},{'v',"five"},{'i',"nine"},{'n',"one"}};



        for(char c:s) dict[c]++; //统计


        for(char sc:search)
        {
            if(dict.find(sc) != dict.end())
            {
                for(char c:dicts[sc])
                    dict[c] -= dict[sc];
                re[dictn[sc]] = dict[sc];
            }
        }

        string result;
        for(int i=0;i<re.size();i++)
             result.append(re[i],'0'+i);
        return result;
        
    }
};