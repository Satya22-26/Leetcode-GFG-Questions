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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
               vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        bool rev=false;
        while(!q.empty()){
            vector<int> res;
            int levelsize=q.size();
            for(int i=0;i<levelsize;i++){
              if(rev==false){
                    TreeNode* curr=q.front();
                    q.pop_front();
                    res.push_back(curr->val);
                    if(curr->left!=NULL){
                        q.push_back(curr->left);
                    }
                    if(curr->right!=NULL){
                        q.push_back(curr->right);
                    }
              }
              else{
                  //remove from back and add in front reversely
                TreeNode* curr=q.back();
                q.pop_back();
                res.push_back(curr->val);
                if(curr->right!=NULL){
                    q.push_front(curr->right);
                }
                 if(curr->left!=NULL){
                    q.push_front(curr->left);
                }
              }
                
            }
            v.push_back(res);
            rev=!rev;
        }
        return v;
    }
};