#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

class AddValue {
    public:
        AddValue(int v):theValue(v){}
        void operator()(int& elem) const {
            elem += theValue;
            cout << elem << ",";
        };
    private:
        int theValue;
};

int main()
{
    list<int> coll;
    for(int i=1;i<=9;++i)
        coll.push_back(i);

    //for_each(coll.begin(), coll.end(), AddValue(10));
    for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
    cout << endl;
}
