class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //think that why we cant apply sliding window directly
        //now convert all 0 to -1  
        // find longest subarray with sum=0
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        int sum=0;
        int maxlen=0;
        unordered_map<int,int> mp;
         mp[0]=-1;
        int r=0;
        while(r<nums.size()){
            sum+=nums[r];
            if(mp.find(sum)!=mp.end()){
                maxlen=max(maxlen,r-mp[sum]);
            }
            if(mp.find(sum)==mp.end())mp[sum]=r;
            r++;
        }
        return maxlen;
    }
};