#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

//求组合数，交换10为10，直到不存在10序列

int main()
{
    /*
    vector<vector<unsigned int> > hour;
    vector<vector<unsigned int> > minute;

    for(int i=0;i<6;i++)
    {
        vector<unsigned int> eminute;
        const int val = (1<<i)-1;
        bitset<6> m(val);
        cout << m << endl;
        while(true)
        {
            int flag = 0;
            for(std::size_t i=0;i<5;i++)
            {
                if(m.test(i) && !m.test(i+1)) 
                { 
                    //cout << i << "->INPUT :" << m << endl;
                    m.reset(i);
                    m.set(i+1);
                    cout << i << "->OUTPUT:" << m << endl;
                    eminute.push_back(m.to_ulong());
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) break;
        }
        minute.push_back(eminute);
        for(auto it = eminute.begin();it!=eminute.end();++it)
            cout << *it << ",";
        cout << endl;
    }

    for(auto it = minute.begin();it!=minute.end();++it)
    cout << (*it).size() << ",";
    */

    vector<unsigned int> eme;
    vector<vector<unsigned int>> minute(6, eme);
    vector<vector<unsigned int>> hour(4, eme);
   /*
    for (int i = 0; i < 6; i++)
    {
        vector<unsigned int> mm;
        minute.push_back(mm);
    }
    for (int i = 0; i < 6; i++)
    {
        vector<unsigned int> mm;
        minute.push_back(mm);
    }
    */
    for (int i = 0; i < 60; i++)
    {
        bitset<6> m(i);
        minute[m.count()].push_back(m.to_ulong());
    }
    for (int i = 0; i < 12; i++)
    {
        bitset<4> m(i);
        hour[m.count()].push_back(m.to_ulong());
    }
    /*
    for (int i = 0; i < 4; i++)
    {
        for (auto it = hour[i].begin(); it != hour[i].end(); ++it)
        {
            cout << *it << ",";
        }
        cout << endl;
    }*/

    int n = 1;
    vector<string> result;
    for(int i=0;i<=n;i++)
    {
        if(i<4)
        {
            for(auto it = hour[i].begin();it!= hour[i].end();++it)
            {
                int j = n-i;
                if(j<6)
                {
                    for(auto itm = minute[j].begin();itm!=minute[j].end();++itm)
                    {
                        string re;
                        re+=to_string(*it);
                        re+=":";
                        if(*itm <= 9)
                            re+="0";
                        re+= to_string(*itm);
                        cout << re << endl;
                        result.push_back(re);
                    }
                }
            } 
        }
    }
}