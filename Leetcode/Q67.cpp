//Add binary

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int k=0;
        int maxsize = max(a.size(),b.size())+1;
        string result(maxsize,'0');
        while(i && j)
        {
            int sum = a[i--]-'0'+b[j--]-'0'+result[k]-'0';
            if(sum <= 1) result[k++] += sum; //'0'+1 = '1';
            else
            {
                result[++k] = '1'; 
            }
        }

        while(i--) result[k++] =  
    }
};


class Solution {
public:
    string addStrings(string num1, string num2) {
        
        const int len = num1.size()>num2.size() ? num1.size()+1:num2.size()+1;
        string result(len,'0');
        cout << result << endl;
        int i = num1.size()-1;
        int j = num2.size()-1;
        int k = 0;
        while(i>=0 && j>=0)
        {
            int s = (num1[i--]-'0')+(num2[j--]-'0')+(result[k]-'0');
            int m = s%2;
            int qu = s/2;
            cout << "余数" << m << " 进位" << qu << endl;
            result[k++] = m+'0';
            result[k] = qu+'0';
        }
        while(i>=0)
        {
            int s = (num1[i--]-'0')+(result[k]-'0');
            int m = s%2;
            int qu = s/2;
            result[k++] = m+'0';
            result[k] = qu+'0'; //进位;
        }
        while(j>=0)
        {
            int s = (num2[j--]-'0')+(result[k]-'0');
            int m = s%2;
            int qu = s/2;
            result[k++] = m+'0';
            result[k] = qu+'0'; //进位;
        }
        if(result[k--] == '0') result.erase(result.end()-1);
        reverse(result.begin(),result.end());
        return result;
    }
};