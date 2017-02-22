#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    int arrangeCoins(int n) {
        int nx = (int)sqrt(n);
        while(true)
        {
            if(nx/2 == n/(nx+1)) return nx;
            else if(nx/2 < n/(nx+1)) nx++;
            else return nx-1;
            
            /*
            if(nx*(nx+1)/2 == n/(nx)) return nx;
            else if(nx*(nx+1)/2 < n )
            {
                nx++;
            }
            else
            {
                if(nx*(nx+1)/2-n < nx)
                    return nx-1;
            }
            */
        }
    }
};