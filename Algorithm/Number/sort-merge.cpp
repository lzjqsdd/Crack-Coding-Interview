
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&num,int l,int mid,int r)
{
    vector<int> tmp;
    int i = l,j=mid+1;
    while(i<=mid && j<=r)
    {
        if(num[i] < num[j]) tmp.push_back(num[i++]);
        else tmp.push_back(num[j++]);
    }
    while(i<=mid) tmp.push_back(num[i++]);
    while(j<=mid) tmp.push_back(num[j++]);

    for(int i=0,k=l;i<tmp.size();i++,k++)  num[k] = tmp[i];
}


void sort_merge(vector<int>&num,int l,int r)
{
    if(l < r)
    {
        int mid = l+(r-l)/2;
        sort_merge(num,l,mid);
        sort_merge(num,mid+1,r);
        merge(num,l,mid,r);
    }
}



int main()
{
    //vector<int> num = {1,4,3,6,10,33,2,3,5};
    vector<int> num = {1,4,3,6,10,33,2,3,5,100,-1,16,87,22,34};
    sort_merge(num,0,num.size()-1);
    for(int x:num) cout << x << ",";
    cout << endl;
}

