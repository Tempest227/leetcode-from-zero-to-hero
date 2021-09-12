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
        queue<Node*> que;
        if (root == nullptr) return root;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            Node* node;
            Node* preNode;
            for (int i = 0; i < size; i++)
            {
                if (i == 0)
                {
                    preNode = que.front();//获取本层第一个节点
                    que.pop();
                    node = preNode;
                }
                else
                {
                    preNode = que.front();
                    que.pop();
                    node->next = preNode;
                    node = preNode;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            node->next = nullptr;//本层最后一个节点指向nullptr
        }
        return root;
    }
};