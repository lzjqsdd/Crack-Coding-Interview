//给定一个字符串（表示数字n,不超过18位),找出最接近这个n的数，这个数为回文数（可比n大也可以比n小)
//如果有两个结果都满足，则返回较小的那个数。

//例子:15781 -> 15751,15851,15651
//  123->121,111,131 ,显然121最接近
//  129->121,111,131 ，显然

//  出现相同的情况: 691 -> 696,686
//  （1）为了让变换后的数和原数相差尽可能小，则尽可能变换pivot之后的数。
//  （2）对于奇数个，讲pivot之后的调整为和前面回文，pivot可向上向下改动。仅可+1或者-1。若原来的数是回文，若pivot可向下调，则为结果。否则只能+1。
//      pivot后一位的元素与调整后的元素之差决定了调整的方向是+1/-1.
//      假设pivot位于第m位，m+1为元素原来为x_before,调整后为x_after,若x_before - x_after > 5,则主元+1代价小。否则主元-1代价小。
//  （3）对于偶数，调整后半截。若原数为回文，则中心两个若可以-1，则都减一，否则只能+1
//   (4) 关于返回较小的那个，比如 691,调整为696和686的代价一样，但是若策略为每次优先看是否可以-1，则可返回较小的。
//  （5）原数为回文，结果不可以为原数。
//   根据以上策略，可以避免比较大小。

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        if(n == "") return "";

        int si = n.size();
        int flag = 0,i = 0,j=si-1; //flag标示这个数是不是回文
        string tmp = n;
        while(i<j)
        {
            if(n[i] != n[j])
            {
                n[j] = n[i];flag = 1; //有不同，则原来不是回文
            }
            i++;j--;
        }

        if(si % 2) //若为奇数
        {
            cout << "here" << endl;
            int mid = (si-1)/2;
            if(!flag) //如果是回文
            {
                if(n[mid] > '0') n[mid]--;
                else n[mid]++;
            }
            else
            {
                if(abs(tmp[mid+1] - n[mid+1]) >= 5 && n[mid]>'0') n[mid]--;
            }
        }
        else
        {
            int mid = (si-1)/2;
            if(!flag)
            {
                if(n[mid] > '0') {n[mid]--;n[mid+1]--;}
                else {n[mid]++; n[mid+1]++;}
            }
        }
        return n;
    }
};



/*
"1"
"15751"
"1671"
"691"
"481"
"101010"
"111111"
"1232134561345673"
"97541067352371"
"987654321023456789"
"989898933542351455"
*/


//错误原因：奇数可以缩减为偶数的回文，偶数也可以缩减为奇数的回文
//10000001 为回文 ,对于999999形式的可转换为10000001形式的,代价仅为1
//99999999 为回文 ,对于100001形式的可转换为9999999形式,代价仅为1
//无法解决10000,100001,99999形式的

class Solution2{
public:
    string nearestPalindromic(string n) {
        if(n == "") return "";
        int si = n.size();

        //单独处理1000,100001,9999形式的
        if(n.size() > 1)
        {
            int k = 0;
            while(k<n.size() && n[k++] == '9');
            if(k == n.size())
            {
                string result(n.size(),'0');
                *result.begin() = '1';
                *result.end() = '1';
                return result;
            }
        }

        if(n.size() > 1 && n[0] == '1')
        {   
            int k = 1;
            while(k < n.size()-1 && n[k++] == '0');
            if(k == n.size()-1 && (n.back() == '0' || n.back() == '1'))
            {
                string result(n.size()-1,'9');
                return result;
            }
        }



        int flag = 0,i = 0,j=si-1; //flag标示这个数是不是回文
        string tmp = n;
        while(i<j)
        {
            if(n[i] != n[j])
            {
                n[j] = n[i];flag = 1; //有不同，则原来不是回文
            }
            i++;j--;
        }

        if(si % 2) //若为奇数
        {
            cout << "here" << endl;
            int mid = (si-1)/2;
            if(!flag) //如果是回文
            {
                if(n[mid] > '0') n[mid]--;
                else n[mid]++;
            }
            else
            {
                if(tmp[mid+1] - n[mid+1] >= 5 && n[mid]<'9') n[mid]++;
                else if(tmp[mid+1] - n[mid+1] <= -5 && n[mid]>'0') n[mid]--;
            }
        }
        else
        {
            int mid = (si-1)/2;
            if(!flag)
            {
                if(n[mid] > '0') {n[mid]--;n[mid+1]--;}
                else {n[mid]++; n[mid+1]++;}
            }
            else
            {
                if(tmp[mid+1] - n[mid+1] >= 5 && n[mid] < '9') {n[mid]++;n[mid+1]++;}
                else if(tmp[mid+1] - n[mid+1] <= -5 && n[mid] > '0') {n[mid]--;n[mid+1]--;}
                
            }
        }
        return n;
    }
};


"100"
"101"
"99"
"999"
"1000"
"10001"
"9"
"0"
"1"
"5"
"11"
"12"
"1"
"15751"
"1671"
"691"
"481"
"101010"
"111111"
"1232134561345673"
"97541067352371"
"987654321023456789"
"989898933542351455"
"1283"
"1823"
"18923"
"12983"

//尚未解决n[mid] == 9时进位问题,所以应该先只考虑前半截,进位什么确定好之后更新后半截.


//用数字的思路,将字符串转换为数字.默认的回文装换是用前半截替换后半截.如果替换后的数p > n,那么找原数小的.用前半部分-1来获取.反之用前半截+1来获得.
//MinDiff(half + reserve(half), (half + 1) + reserve(half + 1 ) , (half - 1) + reserve(half - 1 ) )
int main()
{
    string test = "111111";
    Solution2 s;
    cout << s.nearestPalindromic(test) << endl;
}


class Solution {
public:
    string palindromeStr(const string& s) {
        int i = 0; 
        int j = s.size() - 1;
        string ret = s;
        while (i<=j) {
            ret[j] = ret[i];
            i++;
            j--;
        }
        return ret;
    }
    
    string dec2Palindrome(const string& s) {
        string pal = s;
        int left = (int) (s.size() - 1) / 2; 
        int right = (int) s.size() / 2;
        while (left >= 0) {
            if (pal[left] > '0') {
                pal[left] = pal[left] - 1;
                if (left < right) {
                    pal[right] = pal[right] - 1;
                }
                break;
            } else {
                pal[left] = pal[right] = '9';
                left--;
                right++;
            }
        }
        if ((pal[0] == '0') && (pal.size() > 1)) {
            pal[right] = '9';
            pal.erase(pal.begin());
        }
        return pal;
    }
    
    string inc2Palindrome(const string& s) {
        string pal = s;
        int left = (int) (s.size() - 1) / 2; 
        int right = (int) s.size() / 2; 
        while (left >= 0) {
            if (pal[left] < '9') {
                pal[left] = pal[left] + 1;
                if (left < right) {
                    pal[right] = pal[right] + 1;
                }
                break;
            } else {
                pal[left] = pal[right] = '0';
                left--;
                right++;
            }
        }
        if (pal[0] == '0') {
            pal.back() = '1';
            pal.insert(pal.begin(), '1');
        }
        return pal;        
    }
    
    string nearestPalindromic(string n) {
        if (n == "0") {
            return "-1";
        }
        //Find the almost closest palindrome integer
        string pal = palindromeStr(n);
        long low;
        long up;
        long num = stoll(n);
        string lowPal;
        string upPal;
        if (pal == n) {
            //For n is a palindrome number, find the two closest palindrome integer, 
            //one is larger than n and the other is less than n
            lowPal = dec2Palindrome(n);
            upPal = inc2Palindrome(n);            
        }
        //For the other cases, find the corresponding another palindrome integer
        else if (pal < n) {
            lowPal = pal;
            upPal = inc2Palindrome(pal);
        } else {
            upPal = pal;
            lowPal = dec2Palindrome(pal);
        }
        low = stoll(lowPal);
        up = stoll(upPal);
        if (num - low <= up - num) {
            return lowPal;
        } else {
            return upPal;
        }
    }
};

//判断奇数偶数 n&1