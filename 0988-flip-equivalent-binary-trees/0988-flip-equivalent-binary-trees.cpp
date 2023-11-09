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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //use preorder and check if node val equals and then check whether right or left are same but 4 conditions needed due to swapping condition
         if (!root1 && !root2) return true;
        if (!root2) return false;
        if (!root1) return false;
        if (root1->val != root2->val) return false;
        return ((flipEquiv(root1->left,root2->left) && 
                flipEquiv(root1->right,root2->right)) || 
                (flipEquiv(root1->left,root2->right) && 
                flipEquiv(root1->right,root2->left)));
    }
};