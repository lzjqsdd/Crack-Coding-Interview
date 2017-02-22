//大数乘法
//两个非负的数
//两个数相乘最大的位数位两个数位数之和。
//9999*999 最大是7位

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> result(num1.size()+num2.size(),0); //先用整型存储，避免多次转换成字符。
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num1.size();i++)
        {
            int xi = num1[i]-'0';
            int k = i; 
            for(int j=0;j<num2.size();j++)
            {
                int xj = num2[j]-'0';
                int total = xi*xj+result[k];
                result[k] = total%10; //每一位相乘的余数
                result[k+1] += total/10;
                int tmpK = k+1;
                while(result[tmpK] > 10)
                {
                    result[tmpK+1]+=(result[tmpK])/10;
                    result[tmpK] = result[tmpK]%10;
                    tmpK++;
                }
                k++;         
            }
        }

        while(result.size() > 1 && result.back() == 0) result.erase(result.end()-1);
        string re;
        for(auto rit = result.rbegin();rit!=result.rend();++rit)
            re.append(1,(*rit)+'0');

        return re; 
    }
};