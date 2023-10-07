class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum=0;
        if(nums.size()==1)return nums[0];
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            string v=to_string(nums[r]);
            long long concat=(nums[l]*pow(10,v.size()))+nums[r];
            sum+=concat;
            l++;
            r--;
        }
        if(l==r){
            sum+=nums[r];
        }
        return sum;
    }
};