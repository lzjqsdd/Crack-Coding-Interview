//Greedy

/*
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


[5,0],[7,0],[5,2],[6,1],[4,4],[7,1],
*/
#include<vector>
#include <string>

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        for(int i=0;i<people.size();i++)
        {
            int num = people[i].second;
            if(num >= i) continue; //[7,0][4,4]
            else
            {
                int n = 0;
                int j;
                for(j=0;j<i && n<=num;j++)
                {
                    if(people[j].first >= people[i].first )   n++;
                }
                //插入到j前面
                pair<int,int> tmp = people[i];
                memmove(&people[j],&people[j+1],sizeof(pair<int,int>)*(i-j));
                people[i] = tmp;
                
            }
        }
    }
};