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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;

        while(cur->next && cur->next->next)
        {
            ListNode* tmp = cur->next;
            ListNode* otherTmp = tmp->next->next;

            cur->next = tmp->next;
            tmp->next->next = tmp;
            tmp->next = otherTmp;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};