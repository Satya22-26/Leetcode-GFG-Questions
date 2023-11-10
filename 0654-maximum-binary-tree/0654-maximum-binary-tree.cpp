class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;
        TreeNode* root = nullptr;
        for (int num: nums) {
            TreeNode* node = new TreeNode (num);
            while (!st.empty() && node->val > st.top()->val) {
                node->left = st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.top()->right = node;
            }
            else {
                root = node;
            }
            st.push(node);
        }
        return root;
    }
};