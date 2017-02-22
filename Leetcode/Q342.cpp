#include <iostream>
using namespace std;

/*class Solution {
public:
    bool isPowerOfFour(int num) {
        if( (num&(num-1)) == 0 )
        {
            cout << (num&0x55555555) << endl;
            if(num&0x55555555 == 0) return false;
            else return true;
        }
        else
            return false;
    }
};
*/

int main()
{
    int num  = 16;
     if( (num&(num-1)) == 0 )
    {
        cout << (num&0x55555555) << endl;
        if((num&0x55555555) == num){cout << 1 << endl; return true;}
        else {cout << 0 << endl; return false;}
    }
    else
    {
        cout << 10 << endl;
        return false;
    }
}
