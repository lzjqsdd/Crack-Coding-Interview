#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			vector<int>::iterator it;
			for(it = nums.begin();it<nums.end()-1;)
			{
				if(*it == *(it+1))
				{  
					cout<<*it<<"VS"<<*(it+1)<<endl;
					it = nums.erase(it); 
				}
				else
					it++;
			}
			return nums.size();
		}
};


int main()
{
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(2);
	test.push_back(2);
	test.push_back(3);
	Solution s;
	s.removeDuplicates(test);

}
