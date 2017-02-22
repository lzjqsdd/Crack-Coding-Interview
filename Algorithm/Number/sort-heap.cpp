//用数组表示堆，因为二叉堆节点的关系明确
//本代码实现采用小顶堆
//根节点编号从0开始，left = 2*root+1,right = 2*root+2
//root = (left-1)/2  =(right-1)/2
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;



void FixAddElement(vector<int>&num ,vector<int>& heap,int n)
{
    int p = (n-1)/2;
    while(p >= 0 && heap[n] < heap[p])
    {
        swap(heap[n],heap[p]);
        n = p;
        p = (n-1)/2;
    }
    //cout << "add" << endl;
    //for(int x:heap) cout << x << "," ;
    //puts("");
}

void buildHeap(vector<int>&num,vector<int>& heap)
{
    for(int i=0;i<num.size();i++)
    {
        heap[i] = num[i];
        FixAddElement(num,heap,i);
    }
    //cout << "buildDone" << endl;
    //for(int x:heap) cout << x << "," ;
    //puts("");
}


void FixRemoveRoot(vector<int>&heap) //调用此函数时最小的已经被取走。
{
    int i = 0;
    while(i<heap.size())
    {
        int l = 2*i+1;
        int r = 2*i+2;
        int k;
        if(l > heap.size()-1)
            break;
        else
        {
            if(r > heap.size() - 1) k = l;
            else k = heap[l] < heap[r] ? l:r;
        }

        if(heap[k] < heap[i])
        {
            swap(heap[k],heap[i]);
            i = k;
        }
        else break;
    }
    //cout << "remove" << endl;
    //for(int x:heap) cout << x << "," ;
    //puts("");
}


void sort_heap(vector<int> &num)
{
    vector<int> heap(num.size(),0);
    buildHeap(num,heap);

    for(int i=0;i<num.size();i++)
    {
        num[i] = heap[0];
        swap(heap.front(),heap.back());
        heap.erase(heap.end()-1);
        FixRemoveRoot(heap);
    }
    for(int x:num) cout << x << "," ;
    puts("");
}

int main()
{
    vector<int> num1 = {-1,3,3,5,61,23,8,10,11,29};
    vector<int> num2 = {10,9,7,8,6,5,3,4,1,2};
    vector<int> num3 = {10,9,8,7,6,5,4,3,2,1,};
    sort_heap(num1);
    sort_heap(num2);
    sort_heap(num3);
}
