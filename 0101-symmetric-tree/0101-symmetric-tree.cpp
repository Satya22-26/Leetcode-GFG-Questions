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
    bool isSymmetric(TreeNode* root) {
        //insread of checking corner corner by dequue
        //we use queue with ll rr lr rl to check adjacent same
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* p1=q.front();
            q.pop();
            TreeNode* p2=q.front();
            q.pop();
            if(p1==NULL && p2==NULL)continue;
            if(p1==NULL || p2==NULL)return false;
            if(p1->val!=p2->val){
                return false;
            }
                q.push(p1->left);
                q.push(p2->right);
                q.push(p1->right);
                q.push(p2->left);
        }
        return true;
    }
};