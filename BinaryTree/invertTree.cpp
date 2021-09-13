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
    //深度遍历
    // TreeNode* invertTree(TreeNode* root) {
    //     if (root == nullptr) return root;
    //     swap(root->left, root->right);
    //     invertTree(root->left);
    //     invertTree(root->right);
    //     return root;
    // }
    //层序遍历
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                swap(node->left, node->right);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};