//判断s是不是t的字串（不一定连续）abc  ahbgdc
//因为要求字串有序，所以从左往右扫描，遍历一次即可。遇到相同的共同往下扫，否则对t往下走直到找到
//匹配的
//如果t很长，但是t不变？
//对t建立HashMap，value位序号（multimap),对s扫描，如果找不到记录，返回false,否则，每次取出记录，
//得到最小的Index（why)，并消化一个。


bool solve(string s,string t)
{
    int num = 0;
    for(int i=0,j=0;i<s.size() && j<t.size();)
    {
        if(s[i] == t[j]) {i++;j++;num++;}
        else j++;
    }
    if(num == s.size()) return true;
    return false;
}
