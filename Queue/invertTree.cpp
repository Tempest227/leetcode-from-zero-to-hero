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