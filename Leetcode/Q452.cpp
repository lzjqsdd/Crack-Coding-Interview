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