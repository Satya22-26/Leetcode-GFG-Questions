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
//unoptimised will be preorder and store elements in a queue and makr ll or skewed tree or do make a tree directly during preorder but we  dont hjave to make rather modify
    void flatten(TreeNode* root) {
        //preorder-perform at node and the go downwards
        //we have to bring lest st to right and not loose right st
        //NLR -- there  should note be any left node
        //everytime attach the right subtree to rightmost  leafnode  of left subtree and make the left  subtree to right subtree
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* temp=curr->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                temp->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};