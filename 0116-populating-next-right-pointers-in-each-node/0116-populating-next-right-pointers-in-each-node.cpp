/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        //perfect binary tree
        //given constant extra space
        // otherwise just join next to next element in queue in each level
        Node* leftmost=root;
        while(leftmost!=NULL){
            Node* curr=leftmost;
            while(curr!=NULL && curr->left!=NULL){
                curr->left->next=curr->right;
                if(curr->next!=NULL){
                    curr->right->next=curr->next->left;
                }
                curr=curr->next;
            }
            leftmost=leftmost->left;
        }
        return root;
    }
};