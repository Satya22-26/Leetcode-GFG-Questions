class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long c=0;
        for(int i=0;i<nums.size();i++){
            auto h=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            auto l=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            c+=h-l;
        }
        return c;
    }
};