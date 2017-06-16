//题意：给定一个松鼠，一颗树和多个松果，每次松鼠只能取一个松果放到树下。
//求最小的步数。松鼠可以上下左右行走

//思路：如果只有一个松果，松鼠只需要送到树下即可。但是如果有多个，第一次到树下之后，接下来就每次从树的
//位置出发，并回到树下。
//所以，(1)计算每个松果和树的距离，(2)计算每个松果到松鼠的距离. 则第一次选择取松果到松鼠最小的距离+松果到树的最小的距离。
//其他直接计算2*(松果到树的距离)

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int max_dis_tree_nuts = 0,min_dis_squ_nuts = INT_MAX;
        int sum = 0;
        for(auto n:nuts)
        {
             //松果到树的距离
            int dis = abs(n[0]-tree[0]) + abs(n[1] - tree[1]);
            max_dis_tree_nuts = max(min_dis_tree_nuts,dis);
            sum += dis*2;

            //松果到初始松鼠位置的距离
            int dis2 = abs(n[0] - squirrel[0]) + abs(n[1] - squirrel[1]);
            min_dis_squ_nuts = min(min_dis_squ_nuts,dis2);
        }
        return sum - max_dis_tree_nuts + min_dis_squ_nuts; //两个max,min的dis可能都不是一个nutstore了
    }
};

class Solution {
public:
    int minDistance(int n, int m, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        vector<int> d1(nuts.size());
        vector<int> d2(nuts.size());
        int sd1 = 0;
        for(int i = 0; i < (int) nuts.size(); ++i)
        {
            d1[i] = abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]);
            d2[i] = abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]);
            sd1 += d1[i];
        }
        int ans = INT_MAX;
        for(int i = 0; i < (int) nuts.size(); ++i)
            ans = min(ans, sd1 * 2 - d1[i] + d2[i]); //松鼠--》果子 --> 树

        //第一步的选择都是 松鼠--》果子 --> 树 sd1*2 + (d2[i] - d1[i]).
        //如果第一步选择是 松鼠 -- > 树 -- > 果子 -- > 树。则结果为sd1*2 + dis(松鼠，树)
        //考虑(d2[i] - d1[i]) 和 dis(松鼠，树)大小。从严格的三角形考虑，两边之差小于第三边。即使按照直角走法，还是小于斜边
        //此时斜边如果改为直线走法会更长。无论如何d2[i]-d1[i]都会比dis(松鼠，树)小
        return ans;
    }
};


class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int> >& nuts) {
      int i,j,ans,tmp,tmp1;
      tmp=0;
      for (i=0;i<nuts.size();i++)
      {
        tmp+=2*(abs(nuts[i][0]-tree[0])+abs(nuts[i][1]-tree[1]));
      }
      ans=2000000000;
      for (i=0;i<nuts.size();i++)
      {
        tmp1=tmp-(abs(nuts[i][0]-tree[0])+abs(nuts[i][1]-tree[1]))+(abs(nuts[i][0]-squirrel[0])+abs(nuts[i][1]-squirrel[1]));
        if (tmp1<ans) ans=tmp1;
      }
      return ans;
    }
};