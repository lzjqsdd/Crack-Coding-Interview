//Zig-Zag模式输出
//按照每行输出
//可以观察到，对于每行之间的元素之差在每次减2.比如
//PAYPALISHIRING
//P   A   H   N
//A P L S I I G
//Y   I   R

//考虑两个方向，往下填充，网上填充，构建一个二维数组模拟填充，耗费空间
//直接根据规律填充,输出每一行
//第一行之间的元素diff = 2*row - 3;
//连续元素差值是变换的，对于首尾行，元素差为2*row-3
//对于其他行，元素差是交替变化，diff1+diff2总和和row有关
//row = 6, sum = 8
//row = 5, sum = 6
//row = 4, sum = 4
//row = 3, sum = 2
//row = 2, 只有首位行

//从[1,row-1]行，起始diff从(2*row-3)逐渐减2

#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() < numRows) return s;
       
        string result;
        int diff = 2*numRows - 2;
        //输出第一行 i=0;
        int j = 0;
        while(j < s.size()) {result+=s[j];j+=diff;}

        //输出中间行
        int sum = 2*(numRows-1);
        int startdiff = diff;
        for(int i = 1;i<numRows-1;++i)
        {
            startdiff -= 2;
            diff = startdiff;
            int j = i;
            while(j < s.size()) {result+=s[j];j+=diff;diff = sum - diff;}
        }

        diff  = 2*numRows - 2;
        j = numRows-1;
        while(j<s.size())  {result+=s[j];j+=diff;}
        return result;
    }
};