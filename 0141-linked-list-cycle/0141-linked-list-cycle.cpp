/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow=head, *fast=head;
        while(slow!=NULL && fast!=NULL)
        {
            slow=slow->next;
            if(fast->next!=NULL)
                fast=fast->next->next;
            else
                return 0;
            if(slow==fast)
                return 1;
        }
        return 0;
    }
};