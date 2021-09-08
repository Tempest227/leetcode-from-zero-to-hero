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
    // 递归
    // void traversal(TreeNode* cur, vector<int>& result)
    // {
    //     if (cur == nullptr)
    //     {
    //         return;
    //     }
    //     result.push_back(cur->val);
    //     traversal(cur->left, result);
    //     traversal(cur->right, result);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traversal(root, result);

    //     return result;
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        if (root == nullptr) return result;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            result.push_back(node->val);
            st.pop();

            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return result;
    }
};