//整数转罗马数字(第一遍)
//I(1),V(5),X(10),L(50),C(100),D(500),M(1000)
//罗马数字所表示最大为3999.M最多可连续3个。

//这里主要解决4和9的表示方式，4的表示为IV, 9可以由4和5加起来(IV+V)，但是实际9可以直接由10-1表示，即(IX)

//3999表示为(3000+900+90+9)
//所以对能表示范围建立区间
//1000,900,500,400,100,90,50,40,10,9,5,4
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<int> in = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> ro = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        int i = 0;
        string result;
        while(num)
        {
            int k = num / in[i];
            while(k--) result+=ro[i];
            num = num % in[i];
            i++;
        }
        return result;
    }
};