class Solution {
public:
    bool isSubstringTrue(unordered_map<string,int> mp,string con,int wl){
        int i=0;
        while(i<con.size()){
            string f=con.substr(i,wl);
            if(mp.find(f)!=mp.end()){
                mp[f]--;
            }
            i+=wl;
        }
        for(auto i:mp){
            if(i.second>0)return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
     //constraints say o(n^2) will work
       //sliding  window  size = words concatenated size 
       vector<int> ans;
       int wl=words[0].size();
       int k=words.size()*wl;
       int n=s.size();
       unordered_map<string,int> mp;
       for(int i=0;i<words.size();i++){
           mp[words[i]]++;
       }
       int r=0;
       while(r+k<=n)//= as r+k is  already 1 more
       {
           //check if r can be the answer
           if(isSubstringTrue(mp,s.substr(r,k),wl)){
               ans.push_back(r);
           }
           r++;
       }
       return ans;
    }
};