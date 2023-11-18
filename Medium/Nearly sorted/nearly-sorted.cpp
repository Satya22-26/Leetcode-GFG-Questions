//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector<int> v;
        priority_queue<int,vector<int>,greater<int>> maxH;
        for(int i=0;i<num;i++){
            maxH.push(arr[i]);
            if(maxH.size()>K){
                v.push_back(maxH.top());
                maxH.pop();
            }
        }
        while(!maxH.empty()){
            v.push_back(maxH.top());
            maxH.pop();
        }
        return v;
        
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends