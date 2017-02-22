//Number of Boomerangs
//multimap 分别以x,y为主键，按y轴分层，找x，看是否构成。对x同样处理。

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int numberOfBoomerangs(vector<pair<int, int>>& points) {
    multimap<int,int> X; //以X坐标分层
    multimap<int,int> Y; //以Y坐标分层

    for(auto p : points)
    {
        X.insert(p);
        Y.insert(make_pair(p.second,p.first));
    }

    //以Y为层进行统计

}


int main()
{
}
