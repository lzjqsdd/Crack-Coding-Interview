//判断s2中是否有子串是s1的全排列
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
	string tmp = s2;
	for(int i = 0;i<s2.size();++i)
	{
	    size_t pos = s1.find(s2[i]);
	    if(pos != std::npos) //如果找到了
	    {
		s1.erase(pos);
		int k = 1; //如果出现一个字母在s1中，则连续往下找看是否匹配
		int j = i+1;
		while(s1.size() > 0 && j < s2.size())
		{
		    if(s1.find(s2[i]) != std::npos) k++; //统计匹配的个数
		    else break; //如果当前的不匹配，则重新开始
		}
		if(k == tmp.size()) return true; //如果刚好够则是，否则从下一个开始重新继续找
		if(j == s2.size()) break;
		else  {
		    i = j-1;
		    s2 = tmp; //继续往下找
		}
	    }
	}

	return false;
    }
};

http://blog.csdn.net/liql2007/article/details/12168275
http://stackoverflow.com/questions/22737407/permutation-of-string-as-substring-of-another 	


class Solution {
public:
    bool checkInclusion(string t, string s) {
        int m = t.length(), n = s.length();
        if (m > n) return false;
        vector<int> cnt(26);
        for (int i = 0; i < m; ++i) {
            cnt[t[i] - 'a']++;
        }
        vector<int> cur(26);
        for (int i = 0; i < m; ++i) {
            cur[s[i] -  'a']++;
        }
        if (cur == cnt) return true;
        for (int k = 1; k + m <= n; ++k) {
	    //每次计算每个连续子串m的统计结果,每次统计结果实在前一个统计结果基础上减去一个字符，后面在加上一个字符
            cur[s[k - 1] - 'a']--;
            cur[s[k + m - 1] - 'a']++;
            if (cur == cnt) return true;
        }
        return false;
        
    }
};

//使用map不能直接比较两个map是否相同
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(128,0);
        vector<int> m2(128,0);
        int m = s1.size();
        int n = s2.size();
        if(s1.size() > s2.size()) return false;
        for(int i = 0;i<m;++i) m1[s1[i]]++;
        for(int i = 0;i<m;++i) m2[s2[i]]++; //Only calc m entries
        
        if(m1 == m2) return true;
        for(int i = 1;i+m<=n;++i)
        {
            m2[s2[i-1]] --; //slide window
            m2[s2[i+m-1]] ++;
            if(m1 == m2) return true;
        }
        return false;
    }
};
