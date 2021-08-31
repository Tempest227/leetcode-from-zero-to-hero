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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;

        int tmp = n;
        while(tmp >= 0)
        {
            fast = fast->next;
            tmp--;
        }
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* node = slow->next;
        slow->next = node->next;
        delete node;

        return dummyHead->next;
    }
};