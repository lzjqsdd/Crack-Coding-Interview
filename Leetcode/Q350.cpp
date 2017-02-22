#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//可以使用c++自带的集合操作,但是对vector求集合操作要先对vector进行排序
//sort 排序
//set_union 并集
//set_intersection 交集
//set_symmetric_difference 对称差集

int main()
{
    vector<int> nums1 = {1,2,3,4,4,5,6,7,7,7};
    vector<int> nums2 = {1,1,2,3,4,4,5,6,7,7,8,9};

    //set<int>sa;
    //set<int>sb;
    //for(auto it = a.begin();it!=a.end();it++) sa.insert(*it);
    //for(auto it = b.begin();it!=b.end();it++) sb.insert(*it);
    //set<int>result;
    vector<int> result;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),inserter(result,result.begin()));
    for(auto it = result.begin();it!=result.end();it++) cout << *it << endl;
}