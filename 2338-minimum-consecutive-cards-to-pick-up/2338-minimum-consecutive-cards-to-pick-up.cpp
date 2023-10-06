class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int l=0;
        int r=0;
        int len=INT_MAX;
        unordered_map<int,int> mp;
        while(r<cards.size()){
            mp[cards[r]]++;
            if(mp[cards[r]]>=2){
                while(mp[cards[r]]>=2){
                    len=min(len,r-l+1);
                    mp[cards[l]]--;
                    l++;
                }
            }
            r++;
        }
        if(len==INT_MAX)return -1;
        return len;
    }
};