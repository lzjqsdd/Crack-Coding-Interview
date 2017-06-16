//给定很多气球的横向的，纵向射箭，求最少的箭数
//Greedy
//根据起始坐标排序，每次尽可能多的找出重叠的气球，然后使用一支，然后继续

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end(),cmp);
        pair<int,int> spoint={INT_MIN,INT_MAX};
        int result = 1;
        for(int i=0;i<points.size();i++)
        {
            if(points[i].first >= spoint.first && points[i].first <= spoint.second)
            {
                spoint.first = points[i].first;
                spoint.second = min(points[i].second,spoint.second);
            }
            else
            {
                result++;
                spoint = points[i];    
            }
            
        }
        return result;
    }

    static bool cmp(const pair<int,int>&p1,const pair<int,int>&p2)
    {
        return p1.first < p2.first;
    }
};


[[10,16],[2,8],[1,6],[7,12],[2,5],[3,7],[10,11],[5,8],[11,18],[30,43],[41,34],[65,68],[49,70],[99,100]]
[]
[[3,5],[1,10],[4,6],[7,9],[3,7]]


//Greedy思路理解：
//为什么每次射箭时选择气球末端？ 从 区间重叠的角度考虑，选择末端有更大的可能性捎带这打到其他气球。如下
//  --------    ---------  ---------
//      ----------  ---   ------

//仍然从解的结构考虑，假设我们目前最优解为k，并且最优解射击目标并未选择末尾最靠前的那个气球，但是最优解显然已经把这个气球处理掉了。
//说明最优解中有某一箭位于 该气球与最优解的最靠前的一个气球的重叠的部分中。那么显然我们把射击对象换成末尾最靠前那个，这一箭还是在
//这个区间中，并不影响这一箭之外的其他的气球的最优解。所以采用贪心的算法，每次选择末尾最靠前的来处理。
//和会议室排期问题本质是一样的。