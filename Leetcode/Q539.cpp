//题意：给定一组字符串，Hour:Min格式，时间在24小时内表示。找出相差最小的两个点
//思路：原数组无序，找最小的两个（查找的假设空间为n^2),因此先排序，然后遍历亮亮相邻的大小。

//Input: ["23:59","00:00"]
//Output: 1

//注意"00:00"也表示“24:00”
//计算的是绝对值，所以考虑末尾和第一个的差值。判断差值是否超过半圈
//该方法并未考虑到虽然两个时间点如果按照同一天求差得到最小，但是反过来差值较大的在两天之间的差值反而变小。（思考钟表的结构）
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //时间的大小为字典序，可以直接按照字符串排序
        sort(timePoints.begin(),timePoints.end());
        //if(timePoints[0] == "00:00") timePoints.push_back("24:00");
        int mindiff = INT_MAX;
        for(int i = 0;i+1<timePoints.size();++i)
        {
            int curdiff = diff(timePoints[(i-1+n)%n],timePoints[i]);
            if(mindiff > curdiff) mindiff = curdiff;
        }
        //最大的和最小的差可看做第二天的差值
        int curdiff = diff(timePoints.front(),timePoint.back());
        if(curdiff < mindiff) mindiff = curdiff;
        return mindiff;
    }

    int diff(string s1,string s2) //t2 >= t1
    {
        //全部转换成秒
        int tt1 = ((s1[0]-'0')*10 + (s1[1]-'0'))*60 + (s1[3]-'0')*10 + (s1[4]-'0');
        int tt2 = ((s2[0]-'0')*10 + (s2[1]-'0'))*60 + (s2[3]-'0')*10 + (s2[4]-'0');
        int res = tt2 - tt1;
        if(res > 720) res = 1440 - res;
        return res;
    }
};

["23:59","00:00"]
["23:45","11:11","14:34","08:00","00:34","00:00"]
["05:31","22:08","00:35"]
*/

//思路：首先，排好序之后，两两之间的差比其他的要小。但是，存在第二天的问题。比如23:59 和 00:02相差应该从23:59为起点才比较小。
//所以还应该判断首尾元素的差。初次之外，对于其他元素的差，如果超过12个小时，反过来才是最小
//所以这里的关键思路：不是相邻时间点差值最小。而是从表针的观点考虑，相邻的表指针之间差值比其他表针之间的差值小（不管正向还是反向）

//AC
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        //时间的大小为字典序，可以直接按照字符串排序
        sort(timePoints.begin(),timePoints.end());
        //if(timePoints[0] == "00:00") timePoints.push_back("24:00");
        int mindiff = INT_MAX;
        for(int i = 0;i<timePoints.size();++i)
        {
            int curdiff = abs(diff(timePoints[(i-1+n)%n],timePoints[i])); //i-1+n实现了最后一个和第一个的比较，不用单独拿出来
            curdiff = min(curdiff,1440-curdiff);
            mindiff = min(curdiff,mindiff);
        }
        return mindiff;
    }

    int diff(string s1,string s2) //t2 >= t1
    {
        //全部转换成秒
        int tt1 = ((s1[0]-'0')*10 + (s1[1]-'0'))*60 + (s1[3]-'0')*10 + (s1[4]-'0');
        int tt2 = ((s2[0]-'0')*10 + (s2[1]-'0'))*60 + (s2[3]-'0')*10 + (s2[4]-'0');
        return tt2 - tt1;
    }
};



//AC
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        //时间的大小为字典序，可以直接按照字符串排序
        sort(timePoints.begin(),timePoints.end());
        //if(timePoints[0] == "00:00") timePoints.push_back("24:00");
        int mindiff = INT_MAX;
        for(int i = 0;i<timePoints.size();++i)
        {
            int curdiff = abs(diff(timePoints[(i-1+n)%n],timePoints[i]));
            if(mindiff > curdiff) mindiff = curdiff;
        }
        //最大的和最小的差可看做第二天的差值
        int curdiff = diff(timePoints.front(),timePoints.back());
        mindiff = min(curdiff,mindiff);
        return mindiff;
    }

    int diff(string s1,string s2) //t2 >= t1
    {
        //全部转换成秒
        int tt1 = ((s1[0]-'0')*10 + (s1[1]-'0'))*60 + (s1[3]-'0')*10 + (s1[4]-'0');
        int tt2 = ((s2[0]-'0')*10 + (s2[1]-'0'))*60 + (s2[3]-'0')*10 + (s2[4]-'0');
        int res = tt2 - tt1;
        if(res > 720) res = 1440 - res;
        return res;
    }
};





//Ref RightAnswer
class Solution {
public:
    int findMinDifference(vector<string>& times) {
        int n = times.size();
        sort(times.begin(), times.end());
        int mindiff = INT_MAX;
        for (int i = 0; i < times.size(); i++) {
            int diff = abs(timeDiff(times[(i - 1 + n) % n], times[i]));
            diff = min(diff, 1440 - diff);
            mindiff = min(mindiff, diff);
        }
        return mindiff;
    }

private:
    int timeDiff(string t1, string t2) {
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};