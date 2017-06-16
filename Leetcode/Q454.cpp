//454. 4Sum II
//和Q18很想,不错Q454是把四个数分到四个数组中去选择,并且要求返回的是有多少种tuple(i,j,p,q)
//4sum.

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.size() == 0 || B.size() == 0 || C.size()==0 || D.size()==0) return 0;


        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());

        int result = 0;
        for(int i=0;i<A.size();++i)
        {
            //if(i-1 >= 0 && A[i-1] == A[i]) continue; //去重
            for(int j = 0;j<B.size();++j)
            {
                //if(j-1 >= 0 && B[j-1] == B[j]) continue; //去重的思路是为了防止子问题有相同的前缀,但不影响相同元素可以组合.
                int p = 0,q = D.size() - 1;
                int t =  0 - A[i] - B[j];
                while(p < C.size() && q >=0)
                {
                    if(C[p] + D[q] > t)
                    {
                        //while(q-1 >= 0 && D[q] == D[q-1]) q--;
                        q--;
                    }
                    else if(C[p] + D[q] < t)
                    {
                        //while(p+1 < C.size() && C[p] == C[p+1]) p++;
                        p++;
                    }
                    else
                    {
                        result++;
                        //while(q-1 >= 0 && D[q] == D[q-1]) q--;
                        //while(p+1 < C.size() && C[p] == C[p+1]) p++;
                        p++;q--;
                    }
                }
            }
        }
        return result;
    }
};

[0,1,-1]
[-1,1,0]
[0,0,1]
[-1,1,1]


//TLE O(n^3logn)
class Solution {
public:
     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.size() == 0 || B.size() == 0 || C.size()==0 || D.size()==0) return 0;


        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());

        int result = 0;
        for(int i=0; i< A.size() ;++i)
        for(int j=0; j< B.size() ;++j)
        for(int k=0; k< C.size() ;++k)
        {
            int t = 0 - A[i]-B[j]-C[k];
            auto it = lower_bound(D.begin(),D.end(),t);
            if(it != D.end() && *it == t)
            {
                result+= (upper_bound(D.begin(),D.end(),t) - upper_bound(D.begin(),D.end(),t-1));
            }
        }
        return result;
    }
};

//TLE O(n^2logn)
class Solution {
public:
     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.size() == 0 || B.size() == 0 || C.size()==0 || D.size()==0) return 0;


        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());

        int result = 0;
        for(int i=0; i< A.size() ;++i)
        for(int j=0; j< B.size() ;++j)
        {
            int t = 0 - A[i] - B[j];
            int p = 0,q = D.size()-1;
            while(p < C.size() && q >=0)
            {
                if(C[p] + D[q] > t)
                {
                    while(q-1 >= 0 && D[q] == D[q-1]) q--;
                    q--;
                }
                else if(C[p] + D[q] < t)
                {
                    while(p+1 < C.size() && C[p] == C[p+1]) p++;
                    p++;
                }
                else
                {
                    int r1 = 1,r2 = 1;
                    while(q-1 >= 0 && D[q] == D[q-1]) {q--;r2++;}
                    while(p+1 < C.size() && C[p] == C[p+1]) {p++;r1++;}
                    result += r1 * r2;
                    p++;q--;
                }
            }
        }
        return result;
    }
};

//改进3:
//TLE O(n^3logn)
class Solution {
public:
     int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.size() == 0 || B.size() == 0 || C.size()==0 || D.size()==0) return 0;
        //计算A,B之和,计算C,D之和. 复杂度为O(n^2)
        unordered_map<int,int> mab; //记录A,B元素每种和的个数
        unordered_map<int,int> mcd;
        for(auto x1:A)
            for(auto x2:B)
                mab[x1+x2]++;
        for(auto x1:C)
            for(auto x2:D)
                mcd[x1+x2]++;

        int result = 0;
        for(auto it1 = mab.begin(); it1 != mab.end();++it1)
        {
            auto it2 = mcd.find(- it1->first); //find查找复杂度为O(1),unordered_map内部为hash表
            if(it2 != mcd.end())
                result += (it1->second * it2->second);
        }
        return result;
                
                
    }
};