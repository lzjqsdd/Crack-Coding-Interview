//count and say
//while(n--) 极易出错，尤其当n==0时，实际上为负值了，陷入死循环了


class Solution {
public:
    string countAndSay(int n) {
        if(n==0) return "1";
        string seq = "1";
        n--;
        while(n--)
        {
            string curr;
            char tmp = seq[0];
            int no = 1;
            for(int i=1;i<seq.size();i++)
            {
                if(tmp!= seq[i])
                {
                    curr+=to_string(no);
                    curr.append(1,tmp);
                    tmp = seq[i];
                    no = 1;
                }
                else
                    no++;
            }
            curr+=to_string(no);
            curr.append(1,tmp); //加最后一组
            swap(seq,curr);
        }
        return seq;
    }
    
};