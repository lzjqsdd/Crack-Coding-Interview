//Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k > nums.size()/2)
            addtoback(nums,k);
        else
            addtofront(nums,k);
    }
    void addtofront(vector<int>&nums,int k)
    {
        for(int i=0;i<k;i++){
            nums.insert(nums.begin(),nums.back());
            nums.pop_back();
        }
    }
    void addtoback(vector<int>&nums,int k)
    {
        int rk = nums.size()-k;
        for(int i=0;i<rk;i++){
            nums.push_back(nums.front());
            nums.erase(nums.begin());
        }
    }
};



void * memmove ( void * destination, const void * source, size_t num );


vector<int> vec;
for(int i=0;i<10;++i)    
    vec.push_back(i+1);
int last = *(vec.end()-1);
int* pos = &vec[0];
memmove(pos+1 ,pos, sizeof(int)*(vec.size()-1));	
*vec.begin() = last;