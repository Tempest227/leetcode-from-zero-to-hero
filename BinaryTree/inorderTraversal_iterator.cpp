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
    // 中序遍历
    // void traversal(TreeNode* cur, vector<int>& result)
    // {
    //     if (cur == nullptr) return;
    //     traversal(cur->left, result);
    //     result.push_back(cur->val);
    //     traversal(cur->right, result);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     traversal(root, result);
    //     return result;
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }

        return result;
    }
};