// Minimum Moves to Equal Array Elements
//Incrementing all but one is equivalent to decrementing that one. So let's do that instead.
// How many single-element decrements to make all equal? No point to decrementing below the current minimum,
//so how many single-element decrements to make all equal to the current minimum? 
//Just take the difference from what's currently there (the sum) to what we want (n times the minimum).
class Solution {
public:
    int minMoves(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int min = *(nums.begin());
      int sum = 0;
      for(auto it = nums.begin()+1;it!=nums.end();++it)
        sum+=((*it)-min);
      return sum;
    }
};