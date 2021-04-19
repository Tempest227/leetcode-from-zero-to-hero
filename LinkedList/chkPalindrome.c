/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        if (A == NULL)
        {
            return false;
        }
        if (A->next == NULL)
        {
            return true;
        }
        //找到中间节点
        ListNode* slow = A;
        ListNode* fast = A;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow;
        //反转链表
        ListNode* cur = mid;
        ListNode* pre = NULL;
        
        if (cur == NULL || cur->next == NULL)
        {
            return cur;
        }
        
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        while(pre && A)
        {
            if (pre->val != A->val)
            {
                return false;
            }
            pre = pre->next;
            A = A->next;
        }
        return true;
    }
};