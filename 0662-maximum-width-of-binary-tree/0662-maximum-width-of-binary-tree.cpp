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
    int widthOfBinaryTree(TreeNode* root) {
        //widthwise prob can be solved size of last level and include null
        //BFS
        //we have to add null elements explicitly 
        int width=INT_MIN;
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int levelsize=q.size();
            int minindex=q.front().second;
            int s,l;
            for(int i=0;i<levelsize;i++){
                TreeNode* curr=q.front().first;
                long long idx=q.front().second-minindex;
                if(i==0)s=idx;
                if(i==levelsize-1)l=idx;
                q.pop();
                if(curr->left!=NULL){
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right!=NULL){
                    q.push({curr->right,2*idx+2});
                }
                
            }
            width=max(width,l-s+1);
        }
        return width;
    }
};