/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        //apply bfs
        int ans=INT_MIN;
        if(root==NULL){
            return 0;
        }
        int k=0;;
        queue<TreeNode*> q;
        q.push(root);
        int lev=1;
        while(!q.empty()){
            int levelsize=q.size();
            int sum=0;
            for(int i=0;i<levelsize;i++){
                TreeNode* curr=q.front();
                sum+=curr->val;
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                
            }
            if(sum>ans){
                k=lev;
                ans=sum;
            }
            lev++;
        }
        return k;
    }
};