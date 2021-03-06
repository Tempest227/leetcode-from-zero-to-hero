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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> result;
        if (root == nullptr) return result;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            double sum = 0;
            vector<int> vec;

            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                vec.push_back(node->val);
                que.pop();
                sum += vec[i];
                
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(sum / size);

        }
        return result;
    }
};