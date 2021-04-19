/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
    {
        return NULL;
    }

    //拷贝节点挂在原节点后面
    struct Node* cur = head;

    while(cur)
    {
        struct Node* next = cur->next;
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        copy->next = next;
        cur->next = copy;
        cur = next;
    }

    //处理copy节点得到random
    cur = head;

    while(cur)
    {
        struct Node* copy = cur->next;

        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }

    //拷贝节点取下来链接到一起，恢复原链表
    cur = head;
    struct Node* copyHead, *copyTail;
    copyHead = copyTail = (struct Node*)malloc(sizeof(struct Node));

    while(cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        copyTail->next = copy;
        copyTail = copyTail->next;
        cur->next = next;
        cur = next;
    }
    struct Node* guard = copyHead;
    copyHead = copyHead->next;
    free(guard);

    return copyHead;
}