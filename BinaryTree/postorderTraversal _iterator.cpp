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
    // void traversal(TreeNode* cur, vector<int>& result)
    // {
    //     if (cur == nullptr) return;
    //     traversal(cur->left, result);
    //     traversal(cur->right, result);
    //     result.push_back(cur->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traversal(root, result);
    //     return result;
    // }

    // 前序遍历：中左右 ；后序遍历：左右中
    //中右左->reverse->左右中
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        if (root == nullptr) return result;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            result.push_back(node->val);
            st.pop();

            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};