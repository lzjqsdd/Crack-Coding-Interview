//题意，同95，给出1～n可能组成的BST的个数
//

//递归会超时
class Solution {
public:
    int numTrees(int n) {
        return DandC(1,n);
    }
    int DandC(int l,int r)
    {
        if(l > r) return 0;
        if(l == r) return 1;
        else
        {
            int res = 0;
            for(int i=l;i<=r;++i)
            {
                int lres = DandC(l,i-1);
                int rres = DandC(i+1,r);
                if(lres == 0 && rres > 0)  res+= rres;
                else if(lres > 0 && rres == 0) res+=lres;
                else res += (lres*rres);
            }
            return res;
        }
    }
};


class Solution {
public:
    int numTrees(int n) {
        vector<int> dict(n+1,-1); //这里为n+1
        DandC(dict,n);
        return dict[n];
    }
    void DandC(vector<int>&dict,int n)
    {
        if(n == 0) dict[0] = 0;
        else if(n == 1) dict[1] = 1;
        else
        {
            int res = 0;
            for(int i=1;i<=n;++i)
            {
                int lres,rres;
                if(dict[i-1] == -1) DandC(dict,i-1);
                if(dict[n-i] == -1) DandC(dict,n-i);
                if(dict[i-1] == 0 && dict[n-i] !=0) res+= dict[n-i];
                else if(dict[i-1] !=0 && dict[n-i] == 0) res+=dict[i-1];
                else res+=(dict[n-i]*dict[i-1]);
            }
            dict[n] = res;
        }
    }
};