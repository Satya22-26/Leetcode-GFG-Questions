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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return NULL;
        int index=0;
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==root->val){
                index=i;
                break;
            }
        }
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        vector<int> v4;
        copy(preorder.begin()+1,preorder.begin()+index+1,back_inserter(v1));       copy(inorder.begin(),inorder.begin()+index,back_inserter(v2));
        copy(preorder.begin()+index+1,preorder.end(),back_inserter(v3));
        copy(inorder.begin()+index+1,inorder.end(),back_inserter(v4));
        root->left=buildTree(v1,v2);
        root->right=buildTree(v3,v4);
        return root;
    }
};