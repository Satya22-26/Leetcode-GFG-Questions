class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        vector<int>mp(256,-1);
        int r=0;
        int l=0;
        int maxlen=INT_MIN;
        while(r<s.size()){
            if(mp[s[r]]!=-1){
                l=max(l,mp[s[r]]+1);
            }
            mp[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
        
    }
};