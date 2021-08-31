/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //不带虚拟头节点
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {

//         while(head != nullptr && head->val == val)
//         {
//             ListNode* tmp = head;
//             head = head->next;
//             delete tmp;
//         }

//         ListNode* cur = head;
//         while(cur != nullptr && cur->next != nullptr)
//         {
//             if (cur->next->val == val)
//             {
//                 ListNode* tmp = cur->next;
//                 cur->next = tmp->next;
//                 delete tmp;                
//             }
//             else
//             {
//                 cur = cur->next;
//             }
//         }

//         return head;
//     }
// };
 //带虚拟头节点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        while(cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};