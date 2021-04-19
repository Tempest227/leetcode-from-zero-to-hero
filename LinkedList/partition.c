/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if (pHead == NULL)
        {
            return NULL;
        }
        struct ListNode* lessHead;
        struct ListNode* lessTail;
        struct ListNode* greaterHead;
        struct ListNode* greaterTail;
        
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        struct ListNode* cur = pHead;
        
        while(cur)
        {
            if (cur->val < x)
            {
                lessTail->next = cur;
                lessTail = lessTail->next;
            }
            else
            {
                greaterTail->next = cur;
                greaterTail = greaterTail->next;
            }
            cur = cur->next;
        }
        lessTail->next = greaterHead->next;
        greaterTail->next = NULL;
        free(greaterHead);
        
        return lessHead->next;
    }
    
};