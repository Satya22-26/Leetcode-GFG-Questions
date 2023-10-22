class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> premin(n,0);
        premin[0]=nums[0];
        for(int i=1;i<n;i++){
            premin[i]=min(premin[i-1],nums[i]);
        }
        vector<int> sufmin(n,0);
        sufmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            sufmin[i]=min(sufmin[i+1],nums[i]);
        }
        int sum=INT_MAX;
        for(int i=1;i<=n-2;i++){
            if(premin[i-1]>=nums[i] || sufmin[i+1]>=nums[i])continue;
            sum=min(sum,(nums[i]+premin[i-1]+sufmin[i+1]));
        }
        if(sum==INT_MAX)return -1;
        return sum;
    }
};