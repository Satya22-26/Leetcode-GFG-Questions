//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        //max sum + k is hint
        //sort both and add in maxheap all of 1 with last of 2
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int,pair<int,int>>> maxH;
        int size=N-1;
        for(int i=0;i<A.size();i++){
            maxH.push({A[i]+B[N-1],{i,size}});
        }
        vector<int> ans;
        while(K-- && !maxH.empty()){
            ans.push_back(maxH.top().first);
            if(maxH.top().second.second!=0){
                maxH.push({A[maxH.top().second.first]+B[maxH.top().second.second-1],{maxH.top().second.first,maxH.top().second.second-1}});
            }
            maxH.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends