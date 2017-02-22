//判断给定的序列数是不是合理的UTF-8编码。
//每个数表示一个字节编码。
//比如第一个数表示该字符有3个bytes组成，那么接下来两个应该也是10。如果编码合法。继续往下判断是不是正常的。

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        unsigned int len = data.size();
        if(len == 1 && ((data[0] & (1<<7))) != 0 ) return false;
        if(len >1 && len < 8)
        {
            //首先提取第一个字节data[0]
            //如果是3个字节表示，设置mask1 = 11100000
            //使用异或运算，如果匹配，那么前n+1位的异或值肯定为0，如果不匹配，则前n+1位中肯定有1.说明异或的结果大于等于 1 << (8-n);
            //后续位则随意设置不考虑。

            //同理对后续的字节，首位都是10. 所以设置掩码为1000 0000, 异或结果如果大于等于 1 << 6,则不是合法的uft8编码
            unsigned int mask1 = ((1 << len)-1) << (8-len); //Example. 1110 0000
            unsigned int mask2 = (1 << 7);

            if((data[0] ^ mask1) >= (1 << 6)) return false;
            for(int i=1;i<len;i++)
            {
                if(data[i] ^ mask2 >= (1 << 6)) return false;
            }
        }   
        
        return true;
    }
};