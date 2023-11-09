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
TreeNode* Helper(vector<int>& preorder,int &i,int h,int l){
    if(i>=preorder.size())return NULL;
    if(preorder[i]>h || preorder[i]<l)return NULL;
    TreeNode* root=new  TreeNode(preorder[i]);
    i++;
    root->left=Helper(preorder,i,preorder[i-1],l);
    root->right=Helper(preorder,i,h,preorder[i-1]);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //PREORDER MEANS NLR
        //BSt so ater  nodee all smaller elements on left
        if(preorder.size()==0)return NULL;
        int i=0;
        return Helper(preorder,i,INT_MAX,INT_MIN);
    }
};